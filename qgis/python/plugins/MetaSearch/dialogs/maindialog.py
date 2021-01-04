# -*- coding: utf-8 -*-
###############################################################################
#
# CSW Client
# ---------------------------------------------------------
# QGIS Catalog Service client.
#
# Copyright (C) 2010 NextGIS (http://nextgis.org),
#                    Alexander Bruy (alexander.bruy@gmail.com),
#                    Maxim Dubinin (sim@gis-lab.info)
#
# Copyright (C) 2017 Tom Kralidis (tomkralidis@gmail.com)
#
# This source is free software; you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free
# Software Foundation; either version 2 of the License, or (at your option)
# any later version.
#
# This code is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
###############################################################################

import json
import os.path
import warnings
from urllib.request import build_opener, install_opener, ProxyHandler

from qgis.PyQt.QtCore import Qt
from qgis.PyQt.QtWidgets import (QApplication, QDialog, QComboBox,
                                 QDialogButtonBox, QMessageBox,
                                 QTreeWidgetItem, QWidget)
from qgis.PyQt.QtGui import QColor, QCursor

from qgis.core import (QgsApplication, QgsCoordinateReferenceSystem,
                       QgsCoordinateTransform, QgsGeometry, QgsPointXY,
                       QgsProviderRegistry, QgsSettings, QgsProject)
from qgis.gui import QgsRubberBand
from qgis.utils import OverrideCursor

with warnings.catch_warnings():
    warnings.filterwarnings("ignore", category=ResourceWarning)
    warnings.filterwarnings("ignore", category=ImportWarning)
    from owslib.csw import CatalogueServiceWeb # spellok

from owslib.fes import BBox, PropertyIsLike
from owslib.ows import ExceptionReport

from MetaSearch import link_types
from MetaSearch.dialogs.manageconnectionsdialog import ManageConnectionsDialog
from MetaSearch.dialogs.newconnectiondialog import NewConnectionDialog
from MetaSearch.dialogs.recorddialog import RecordDialog
from MetaSearch.dialogs.xmldialog import XMLDialog
from MetaSearch.util import (clean_ows_url, get_connections_from_file,
                             get_ui_class, get_help_url, highlight_xml,
                             normalize_text, open_url, render_template,
                             serialize_string, StaticContext)

BASE_CLASS = get_ui_class('maindialog.ui')


class MetaSearchDialog(QDialog, BASE_CLASS):

    """main dialogue"""

    def __init__(self, iface):
        """init window"""

        QDialog.__init__(self)
        self.setupUi(self)

        self.iface = iface
        self.map = iface.mapCanvas()
        self.settings = QgsSettings()
        self.catalog = None
        self.catalog_url = None
        self.catalog_username = None
        self.catalog_password = None
        self.context = StaticContext()

        self.leKeywords.setShowSearchIcon(True)
        self.leKeywords.setPlaceholderText(self.tr('Search keywords'))

        self.setWindowTitle(self.tr('MetaSearch'))

        self.rubber_band = QgsRubberBand(self.map, True)  # True = a polygon
        self.rubber_band.setColor(QColor(255, 0, 0, 75))
        self.rubber_band.setWidth(5)

        # form inputs
        self.startfrom = 0
        self.maxrecords = 10
        self.timeout = 10
        self.constraints = []

        # Servers tab
        self.cmbConnectionsServices.activated.connect(self.save_connection)
        self.cmbConnectionsSearch.activated.connect(self.save_connection)
        self.btnServerInfo.clicked.connect(self.connection_info)
        self.btnAddDefault.clicked.connect(self.add_default_connections)
        self.btnCapabilities.clicked.connect(self.show_xml)
        self.tabWidget.currentChanged.connect(self.populate_connection_list)

        # server management buttons
        self.btnNew.clicked.connect(self.add_connection)
        self.btnEdit.clicked.connect(self.edit_connection)
        self.btnDelete.clicked.connect(self.delete_connection)
        self.btnLoad.clicked.connect(self.load_connections)
        self.btnSave.clicked.connect(save_connections)

        # Search tab
        self.treeRecords.itemSelectionChanged.connect(self.record_clicked)
        self.treeRecords.itemDoubleClicked.connect(self.show_metadata)
        self.btnSearch.clicked.connect(self.search)
        self.leKeywords.returnPressed.connect(self.search)
        # prevent dialog from closing upon pressing enter
        self.buttonBox.button(QDialogButtonBox.Close).setAutoDefault(False)
        # launch help from button
        self.buttonBox.helpRequested.connect(self.help)
        self.btnCanvasBbox.setAutoDefault(False)
        self.btnCanvasBbox.clicked.connect(self.set_bbox_from_map)
        self.btnGlobalBbox.clicked.connect(self.set_bbox_global)

        # navigation buttons
        self.btnFirst.clicked.connect(self.navigate)
        self.btnPrev.clicked.connect(self.navigate)
        self.btnNext.clicked.connect(self.navigate)
        self.btnLast.clicked.connect(self.navigate)

        self.mActionAddWms.triggered.connect(self.add_to_ows)
        self.mActionAddWfs.triggered.connect(self.add_to_ows)
        self.mActionAddWcs.triggered.connect(self.add_to_ows)
        self.mActionAddAms.triggered.connect(self.add_to_ows)
        self.mActionAddAfs.triggered.connect(self.add_to_ows)
        self.mActionAddGisFile.triggered.connect(self.add_gis_file)
        self.btnShowXml.clicked.connect(self.show_xml)

        # settings
        self.radioTitleAsk.clicked.connect(self.set_ows_save_title_ask)
        self.radioTitleNoAsk.clicked.connect(self.set_ows_save_title_no_ask)
        self.radioTempName.clicked.connect(self.set_ows_save_temp_name)

        self.manageGui()

    def manageGui(self):
        """open window"""

        self.tabWidget.setCurrentIndex(0)
        self.populate_connection_list()
        self.btnCapabilities.setEnabled(False)
        self.spnRecords.setValue(
            int(self.settings.value('/MetaSearch/returnRecords', 10)))

        key = '/MetaSearch/%s' % self.cmbConnectionsSearch.currentText()
        self.catalog_url = self.settings.value('%s/url' % key)
        self.catalog_username = self.settings.value('%s/username' % key)
        self.catalog_password = self.settings.value('%s/password' % key)

        self.set_bbox_global()

        self.reset_buttons()

        # get preferred connection save strategy from settings and set it
        save_strategy = self.settings.value('/MetaSearch/ows_save_strategy',
                                            'title_ask')
        if save_strategy == 'temp_name':
            self.radioTempName.setChecked(True)
        elif save_strategy == 'title_no_ask':
            self.radioTitleNoAsk.setChecked(True)
        else:
            self.radioTitleAsk.setChecked(True)

        # install proxy handler if specified in QGIS settings
        self.install_proxy()

    # Servers tab

    def populate_connection_list(self):
        """populate select box with connections"""

        self.settings.beginGroup('/MetaSearch/')
        self.cmbConnectionsServices.clear()
        self.cmbConnectionsServices.addItems(self.settings.childGroups())
        self.cmbConnectionsSearch.clear()
        self.cmbConnectionsSearch.addItems(self.settings.childGroups())
        self.settings.endGroup()

        self.set_connection_list_position()

        if self.cmbConnectionsServices.count() == 0:
            # no connections - disable various buttons
            state_disabled = False
            self.btnSave.setEnabled(state_disabled)
            # and start with connection tab open
            self.tabWidget.setCurrentIndex(1)
            # tell the user to add services
            msg = self.tr('No services/connections defined. To get '
                          'started with MetaSearch, create a new '
                          'connection by clicking \'New\' or click '
                          '\'Add default services\'.')
            self.textMetadata.setHtml('<p><h3>%s</h3></p>' % msg)
        else:
            # connections - enable various buttons
            state_disabled = True

        self.btnServerInfo.setEnabled(state_disabled)
        self.btnEdit.setEnabled(state_disabled)
        self.btnDelete.setEnabled(state_disabled)

    def set_connection_list_position(self):
        """set the current index to the selected connection"""
        to_select = self.settings.value('/MetaSearch/selected')
        conn_count = self.cmbConnectionsServices.count()

        if conn_count == 0:
            self.btnDelete.setEnabled(False)
            self.btnServerInfo.setEnabled(False)
            self.btnEdit.setEnabled(False)

        # does to_select exist in cmbConnectionsServices?
        exists = False
        for i in range(conn_count):
            if self.cmbConnectionsServices.itemText(i) == to_select:
                self.cmbConnectionsServices.setCurrentIndex(i)
                self.cmbConnectionsSearch.setCurrentIndex(i)
                exists = True
                break

        # If we couldn't find the stored item, but there are some, default
        # to the last item (this makes some sense when deleting items as it
        # allows the user to repeatidly click on delete to remove a whole
        # lot of items)
        if not exists and conn_count > 0:
            # If to_select is null, then the selected connection wasn't found
            # by QgsSettings, which probably means that this is the first time
            # the user has used CSWClient, so default to the first in the list
            # of connetions. Otherwise default to the last.
            if not to_select:
                current_index = 0
            else:
                current_index = conn_count - 1

            self.cmbConnectionsServices.setCurrentIndex(current_index)
            self.cmbConnectionsSearch.setCurrentIndex(current_index)

    def save_connection(self):
        """save connection"""

        caller = self.sender().objectName()

        if caller == 'cmbConnectionsServices':  # servers tab
            current_text = self.cmbConnectionsServices.currentText()
        elif caller == 'cmbConnectionsSearch':  # search tab
            current_text = self.cmbConnectionsSearch.currentText()

        self.settings.setValue('/MetaSearch/selected', current_text)
        key = '/MetaSearch/%s' % current_text

        if caller == 'cmbConnectionsSearch':  # bind to service in search tab
            self.catalog_url = self.settings.value('%s/url' % key)
            self.catalog_username = self.settings.value('%s/username' % key)
            self.catalog_password = self.settings.value('%s/password' % key)

        if caller == 'cmbConnectionsServices':  # clear server metadata
            self.textMetadata.clear()

        self.btnCapabilities.setEnabled(False)

    def connection_info(self):
        """show connection info"""

        current_text = self.cmbConnectionsServices.currentText()
        key = '/MetaSearch/%s' % current_text
        self.catalog_url = self.settings.value('%s/url' % key)
        self.catalog_username = self.settings.value('%s/username' % key)
        self.catalog_password = self.settings.value('%s/password' % key)

        # connect to the server
        if not self._get_csw():
            return

        if self.catalog:  # display service metadata
            self.btnCapabilities.setEnabled(True)
            metadata = render_template('en', self.context,
                                       self.catalog,
                                       'service_metadata.html')
            style = QgsApplication.reportStyleSheet()
            self.textMetadata.clear()
            self.textMetadata.document().setDefaultStyleSheet(style)
            self.textMetadata.setHtml(metadata)

    def add_connection(self):
        """add new service"""

        conn_new = NewConnectionDialog()
        conn_new.setWindowTitle(self.tr('New Catalog Service'))
        if conn_new.exec_() == QDialog.Accepted:  # add to service list
            self.populate_connection_list()
        self.textMetadata.clear()

    def edit_connection(self):
        """modify existing connection"""

        current_text = self.cmbConnectionsServices.currentText()

        url = self.settings.value('/MetaSearch/%s/url' % current_text)

        conn_edit = NewConnectionDialog(current_text)
        conn_edit.setWindowTitle(self.tr('Edit Catalog Service'))
        conn_edit.leName.setText(current_text)
        conn_edit.leURL.setText(url)
        conn_edit.leUsername.setText(self.settings.value('/MetaSearch/%s/username' % current_text))
        conn_edit.lePassword.setText(self.settings.value('/MetaSearch/%s/password' % current_text))

        if conn_edit.exec_() == QDialog.Accepted:  # update service list
            self.populate_connection_list()

    def delete_connection(self):
        """delete connection"""

        current_text = self.cmbConnectionsServices.currentText()

        key = '/MetaSearch/%s' % current_text

        msg = self.tr('Remove service {0}?').format(current_text)

        result = QMessageBox.question(self, self.tr('Delete Service'), msg,
                                      QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if result == QMessageBox.Yes:  # remove service from list
            self.settings.remove(key)
            index_to_delete = self.cmbConnectionsServices.currentIndex()
            self.cmbConnectionsServices.removeItem(index_to_delete)
            self.cmbConnectionsSearch.removeItem(index_to_delete)
            self.set_connection_list_position()

    def load_connections(self):
        """load services from list"""

        ManageConnectionsDialog(1).exec_()
        self.populate_connection_list()

    def add_default_connections(self):
        """add default connections"""

        filename = os.path.join(self.context.ppath,
                                'resources', 'connections-default.xml')
        doc = get_connections_from_file(self, filename)
        if doc is None:
            return

        self.settings.beginGroup('/MetaSearch/')
        keys = self.settings.childGroups()
        self.settings.endGroup()

        for server in doc.findall('csw'):
            name = server.attrib.get('name')
            # check for duplicates
            if name in keys:
                msg = self.tr('{0} exists.  Overwrite?').format(name)
                res = QMessageBox.warning(self,
                                          self.tr('Loading connections'), msg,
                                          QMessageBox.Yes | QMessageBox.No)
                if res != QMessageBox.Yes:
                    continue

            # no dups detected or overwrite is allowed
            key = '/MetaSearch/%s' % name
            self.settings.setValue('%s/url' % key, server.attrib.get('url'))

        self.populate_connection_list()

    # Settings tab

    def set_ows_save_title_ask(self):
        """save ows save strategy as save ows title, ask if duplicate"""

        self.settings.setValue('/MetaSearch/ows_save_strategy', 'title_ask')

    def set_ows_save_title_no_ask(self):
        """save ows save strategy as save ows title, do NOT ask if duplicate"""

        self.settings.setValue('/MetaSearch/ows_save_strategy', 'title_no_ask')

    def set_ows_save_temp_name(self):
        """save ows save strategy as save with a temporary name"""

        self.settings.setValue('/MetaSearch/ows_save_strategy', 'temp_name')

    # Search tab

    def set_bbox_from_map(self):
        """set bounding box from map extent"""

        crs = self.map.mapSettings().destinationCrs()
        try:
            crsid = int(crs.authid().split(':')[1])
        except IndexError:  # no projection
            crsid = 4326

        extent = self.map.extent()

        if crsid != 4326:  # reproject to EPSG:4326
            src = QgsCoordinateReferenceSystem(crsid)
            dest = QgsCoordinateReferenceSystem(4326)
            xform = QgsCoordinateTransform(src, dest, QgsProject.instance())
            minxy = xform.transform(QgsPointXY(extent.xMinimum(),
                                               extent.yMinimum()))
            maxxy = xform.transform(QgsPointXY(extent.xMaximum(),
                                               extent.yMaximum()))
            minx, miny = minxy
            maxx, maxy = maxxy
        else:  # 4326
            minx = extent.xMinimum()
            miny = extent.yMinimum()
            maxx = extent.xMaximum()
            maxy = extent.yMaximum()

        self.leNorth.setText(str(maxy)[0:9])
        self.leSouth.setText(str(miny)[0:9])
        self.leWest.setText(str(minx)[0:9])
        self.leEast.setText(str(maxx)[0:9])

    def set_bbox_global(self):
        """set global bounding box"""
        self.leNorth.setText('90')
        self.leSouth.setText('-90')
        self.leWest.setText('-180')
        self.leEast.setText('180')

    def search(self):
        """execute search"""

        self.catalog = None
        self.constraints = []

        # clear all fields and disable buttons
        self.lblResults.clear()
        self.treeRecords.clear()

        self.reset_buttons()

        # save some settings
        self.settings.setValue('/MetaSearch/returnRecords',
                               self.spnRecords.cleanText())

        # set current catalog
        current_text = self.cmbConnectionsSearch.currentText()
        key = '/MetaSearch/%s' % current_text
        self.catalog_url = self.settings.value('%s/url' % key)
        self.catalog_username = self.settings.value('%s/username' % key)
        self.catalog_password = self.settings.value('%s/password' % key)

        # start position and number of records to return
        self.startfrom = 0
        self.maxrecords = self.spnRecords.value()

        # set timeout
        self.timeout = self.spnTimeout.value()

        # bbox
        # CRS is WGS84 with axis order longitude, latitude
        # defined by 'urn:ogc:def:crs:OGC:1.3:CRS84'
        minx = self.leWest.text()
        miny = self.leSouth.text()
        maxx = self.leEast.text()
        maxy = self.leNorth.text()
        bbox = [minx, miny, maxx, maxy]

        # only apply spatial filter if bbox is not global
        # even for a global bbox, if a spatial filter is applied, then
        # the CSW server will skip records without a bbox
        if bbox != ['-180', '-90', '180', '90']:
            self.constraints.append(BBox(bbox,
                                         crs='urn:ogc:def:crs:OGC:1.3:CRS84'))

        # keywords
        if self.leKeywords.text():
            # TODO: handle multiple word searches
            keywords = self.leKeywords.text()
            self.constraints.append(PropertyIsLike('csw:AnyText', keywords))

        if len(self.constraints) > 1:  # exclusive search (a && b)
            self.constraints = [self.constraints]

        # build request
        if not self._get_csw():
            return

        # TODO: allow users to select resources types
        # to find ('service', 'dataset', etc.)
        try:
            with OverrideCursor(Qt.WaitCursor):
                self.catalog.getrecords2(constraints=self.constraints,
                                         maxrecords=self.maxrecords, esn='full')
        except ExceptionReport as err:
            QMessageBox.warning(self, self.tr('Search error'),
                                self.tr('Search error: {0}').format(err))
            return
        except Exception as err:
            QMessageBox.warning(self, self.tr('Connection error'),
                                self.tr('Connection error: {0}').format(err))
            return

        if self.catalog.results['matches'] == 0:
            self.lblResults.setText(self.tr('0 results'))
            return

        self.display_results()

    def display_results(self):
        """display search results"""

        self.treeRecords.clear()

        position = self.catalog.results['returned'] + self.startfrom

        msg = self.tr('Showing {0} - {1} of %n result(s)', 'number of results',
                      self.catalog.results['matches']).format(self.startfrom + 1,
                                                              position)

        self.lblResults.setText(msg)

        for rec in self.catalog.records:
            item = QTreeWidgetItem(self.treeRecords)
            if self.catalog.records[rec].type:
                item.setText(0, normalize_text(self.catalog.records[rec].type))
            else:
                item.setText(0, 'unknown')
            if self.catalog.records[rec].title:
                item.setText(1,
                             normalize_text(self.catalog.records[rec].title))
            if self.catalog.records[rec].identifier:
                set_item_data(item, 'identifier',
                              self.catalog.records[rec].identifier)

        self.btnShowXml.setEnabled(True)

        if self.catalog.results["matches"] < self.maxrecords:
            disabled = False
        else:
            disabled = True

        self.btnFirst.setEnabled(disabled)
        self.btnPrev.setEnabled(disabled)
        self.btnNext.setEnabled(disabled)
        self.btnLast.setEnabled(disabled)

    def record_clicked(self):
        """record clicked signal"""

        # disable only service buttons
        self.reset_buttons(True, False, False)

        if not self.treeRecords.selectedItems():
            return

        item = self.treeRecords.currentItem()
        if not item:
            return

        identifier = get_item_data(item, 'identifier')
        try:
            record = self.catalog.records[identifier]
        except KeyError as err:
            QMessageBox.warning(self,
                                self.tr('Record parsing error'),
                                'Unable to locate record identifier')
            return

        # if the record has a bbox, show a footprint on the map
        if record.bbox is not None:
            points = bbox_to_polygon(record.bbox)
            if points is not None:
                src = QgsCoordinateReferenceSystem(4326)
                dst = self.map.mapSettings().destinationCrs()
                geom = QgsGeometry.fromWkt(points)
                if src.postgisSrid() != dst.postgisSrid():
                    ctr = QgsCoordinateTransform(src, dst, QgsProject.instance())
                    try:
                        geom.transform(ctr)
                    except Exception as err:
                        QMessageBox.warning(
                            self,
                            self.tr('Coordinate Transformation Error'),
                            str(err))
                self.rubber_band.setToGeometry(geom, None)

        # figure out if the data is interactive and can be operated on
        self.find_services(record, item)

    def find_services(self, record, item):
        """scan record for WMS/WMTS|WFS|WCS endpoints"""

        links = record.uris + record.references

        services = {}
        for link in links:

            if 'scheme' in link:
                link_type = link['scheme']
            elif 'protocol' in link:
                link_type = link['protocol']
            else:
                link_type = None

            if link_type is not None:
                link_type = link_type.upper()

            wmswmst_link_types = list(map(str.upper, link_types.WMSWMST_LINK_TYPES))
            wfs_link_types = list(map(str.upper, link_types.WFS_LINK_TYPES))
            wcs_link_types = list(map(str.upper, link_types.WCS_LINK_TYPES))
            ams_link_types = list(map(str.upper, link_types.AMS_LINK_TYPES))
            afs_link_types = list(map(str.upper, link_types.AFS_LINK_TYPES))
            gis_file_link_types = list(map(str.upper, link_types.GIS_FILE_LINK_TYPES))

            # if the link type exists, and it is one of the acceptable
            # interactive link types, then set
            if all([link_type is not None,
                    link_type in wmswmst_link_types + wfs_link_types +
                    wcs_link_types + ams_link_types + afs_link_types + gis_file_link_types]):
                if link_type in wmswmst_link_types:
                    services['wms'] = link['url']
                    self.mActionAddWms.setEnabled(True)
                if link_type in wfs_link_types:
                    services['wfs'] = link['url']
                    self.mActionAddWfs.setEnabled(True)
                if link_type in wcs_link_types:
                    services['wcs'] = link['url']
                    self.mActionAddWcs.setEnabled(True)
                if link_type in ams_link_types:
                    services['ams'] = link['url']
                    self.mActionAddAms.setEnabled(True)
                if link_type in afs_link_types:
                    services['afs'] = link['url']
                    self.mActionAddAfs.setEnabled(True)
                if link_type in gis_file_link_types:
                    services['gis_file'] = link['url']
                    services['title'] = record.title
                    self.mActionAddGisFile.setEnabled(True)
                self.tbAddData.setEnabled(True)

            set_item_data(item, 'link', json.dumps(services))

    def navigate(self):
        """manage navigation / paging"""

        caller = self.sender().objectName()

        if caller == 'btnFirst':
            self.startfrom = 0
        elif caller == 'btnLast':
            self.startfrom = self.catalog.results['matches'] - self.maxrecords
        elif caller == 'btnNext':
            self.startfrom += self.maxrecords
            if self.startfrom >= self.catalog.results["matches"]:
                msg = self.tr('End of results. Go to start?')
                res = QMessageBox.information(self, self.tr('Navigation'),
                                              msg,
                                              (QMessageBox.Ok |
                                               QMessageBox.Cancel))
                if res == QMessageBox.Ok:
                    self.startfrom = 0
                else:
                    return
        elif caller == "btnPrev":
            self.startfrom -= self.maxrecords
            if self.startfrom <= 0:
                msg = self.tr('Start of results. Go to end?')
                res = QMessageBox.information(self, self.tr('Navigation'),
                                              msg,
                                              (QMessageBox.Ok |
                                               QMessageBox.Cancel))
                if res == QMessageBox.Ok:
                    self.startfrom = (self.catalog.results['matches'] -
                                      self.maxrecords)
                else:
                    return

        try:
            with OverrideCursor(Qt.WaitCursor):
                self.catalog.getrecords2(constraints=self.constraints,
                                         maxrecords=self.maxrecords,
                                         startposition=self.startfrom, esn='full')
        except ExceptionReport as err:
            QMessageBox.warning(self, self.tr('Search error'),
                                self.tr('Search error: {0}').format(err))
            return
        except Exception as err:
            QMessageBox.warning(self, self.tr('Connection error'),
                                self.tr('Connection error: {0}').format(err))
            return

        self.display_results()

    def add_to_ows(self):
        """add to OWS provider connection list"""

        conn_name_matches = []

        item = self.treeRecords.currentItem()

        if not item:
            return

        item_data = json.loads(get_item_data(item, 'link'))

        caller = self.sender().objectName()

        # stype = human name,/qgis/connections-%s,providername
        if caller == 'mActionAddWms':
            stype = ['OGC:WMS/OGC:WMTS', 'wms', 'wms']
            data_url = item_data['wms']
        elif caller == 'mActionAddWfs':
            stype = ['OGC:WFS', 'wfs', 'WFS']
            data_url = item_data['wfs']
        elif caller == 'mActionAddWcs':
            stype = ['OGC:WCS', 'wcs', 'wcs']
            data_url = item_data['wcs']
        elif caller == 'mActionAddAms':
            stype = ['ESRI:ArcGIS:MapServer', 'ams', 'arcgismapserver']
            data_url = item_data['ams'].split('MapServer')[0] + 'MapServer'
        elif caller == 'mActionAddAfs':
            stype = ['ESRI:ArcGIS:FeatureServer', 'afs', 'arcgisfeatureserver']
            data_url = item_data['afs'].split('FeatureServer')[0] + 'FeatureServer'

        sname = '%s from MetaSearch' % stype[1]

        # store connection
        # check if there is a connection with same name
        if caller in ['mActionAddAms', 'mActionAddAfs']:
            self.settings.beginGroup('/qgis/connections-%s' % stype[2])
        else:
            self.settings.beginGroup('/qgis/connections-%s' % stype[1])
        keys = self.settings.childGroups()
        self.settings.endGroup()

        for key in keys:
            if key.startswith(sname):
                conn_name_matches.append(key)
        if conn_name_matches:
            sname = conn_name_matches[-1]

        # check for duplicates
        if sname in keys:  # duplicate found
            if self.radioTitleAsk.isChecked():  # ask to overwrite
                msg = self.tr('Connection {0} exists. Overwrite?').format(sname)
                res = QMessageBox.warning(self, self.tr('Saving server'), msg,
                                          QMessageBox.Yes | QMessageBox.No)
                if res != QMessageBox.Yes:  # assign new name with serial
                    sname = serialize_string(sname)
            elif self.radioTitleNoAsk.isChecked():  # don't ask to overwrite
                pass
            elif self.radioTempName.isChecked():  # use temp name
                sname = serialize_string(sname)

        # no dups detected or overwrite is allowed
        if caller in ['mActionAddAms', 'mActionAddAfs']:
            self.settings.beginGroup('/qgis/connections-%s' % stype[2])
        else:
            self.settings.beginGroup('/qgis/connections-%s' % stype[1])
        self.settings.setValue('/%s/url' % sname, clean_ows_url(data_url))
        self.settings.endGroup()

        # open provider window
        ows_provider = QgsProviderRegistry.instance().createSelectionWidget(stype[2],
                                                                            self)
        service_type = stype[0]

        # connect dialog signals to iface slots
        if service_type == 'OGC:WMS/OGC:WMTS':
            ows_provider.addRasterLayer.connect(self.iface.addRasterLayer)
            conn_cmb = ows_provider.findChild(QWidget, 'cmbConnections')
            connect = 'btnConnect_clicked'
        elif service_type == 'OGC:WFS':
            def addVectorLayer(path, name):
                self.iface.mainWindow().addVectorLayer(path, name, 'WFS')
            ows_provider.addVectorLayer.connect(addVectorLayer)
            conn_cmb = ows_provider.findChild(QWidget, 'cmbConnections')
            connect = 'connectToServer'
        elif service_type == 'OGC:WCS':
            ows_provider.addRasterLayer.connect(self.iface.addRasterLayer)
            conn_cmb = ows_provider.findChild(QWidget, 'mConnectionsComboBox')
            connect = 'mConnectButton_clicked'
        elif service_type == 'ESRI:ArcGIS:MapServer':
            ows_provider.addRasterLayer.connect(self.iface.addRasterLayer)
            conn_cmb = ows_provider.findChild(QComboBox)
            connect = 'connectToServer'
        elif service_type == 'ESRI:ArcGIS:FeatureServer':
            def addAfsLayer(path, name):
                self.iface.mainWindow().addVectorLayer(path, name, 'afs')
            ows_provider.addVectorLayer.connect(addAfsLayer)
            conn_cmb = ows_provider.findChild(QComboBox)
            connect = 'connectToServer'
        ows_provider.setModal(False)
        ows_provider.show()

        # open provider dialogue against added OWS
        index = conn_cmb.findText(sname)
        if index > -1:
            conn_cmb.setCurrentIndex(index)
            # only for wfs
            if service_type == 'OGC:WFS':
                ows_provider.cmbConnections_activated(index)
            elif service_type in ['ESRI:ArcGIS:MapServer', 'ESRI:ArcGIS:FeatureServer']:
                ows_provider.cmbConnections_activated(index)
        getattr(ows_provider, connect)()

    def add_gis_file(self):
        """add GIS file from result"""
        item = self.treeRecords.currentItem()

        if not item:
            return

        item_data = json.loads(get_item_data(item, 'link'))
        gis_file = item_data['gis_file']

        title = item_data['title']

        layer = self.iface.addVectorLayer(gis_file, title, "ogr")
        if not layer:
            self.iface.messageBar().pushWarning(None, "Layer failed to load!")

    def show_metadata(self):
        """show record metadata"""

        if not self.treeRecords.selectedItems():
            return

        item = self.treeRecords.currentItem()
        if not item:
            return

        identifier = get_item_data(item, 'identifier')

        try:
            with OverrideCursor(Qt.WaitCursor):
                cat = CatalogueServiceWeb(self.catalog_url, timeout=self.timeout, # spellok
                                          username=self.catalog_username,
                                          password=self.catalog_password)
                cat.getrecordbyid(
                    [self.catalog.records[identifier].identifier])
        except ExceptionReport as err:
            QMessageBox.warning(self, self.tr('GetRecords error'),
                                self.tr('Error getting response: {0}').format(err))
            return
        except KeyError as err:
            QMessageBox.warning(self,
                                self.tr('Record parsing error'),
                                self.tr('Unable to locate record identifier'))
            return

        record = cat.records[identifier]
        record.xml_url = cat.request

        crd = RecordDialog()
        metadata = render_template('en', self.context,
                                   record, 'record_metadata_dc.html')

        style = QgsApplication.reportStyleSheet()
        crd.textMetadata.document().setDefaultStyleSheet(style)
        crd.textMetadata.setHtml(metadata)
        crd.exec_()

    def show_xml(self):
        """show XML request / response"""

        crd = XMLDialog()
        request_html = highlight_xml(self.context, self.catalog.request)
        response_html = highlight_xml(self.context, self.catalog.response)
        style = QgsApplication.reportStyleSheet()
        crd.txtbrXMLRequest.clear()
        crd.txtbrXMLResponse.clear()
        crd.txtbrXMLRequest.document().setDefaultStyleSheet(style)
        crd.txtbrXMLResponse.document().setDefaultStyleSheet(style)
        crd.txtbrXMLRequest.setHtml(request_html)
        crd.txtbrXMLResponse.setHtml(response_html)
        crd.exec_()

    def reset_buttons(self, services=True, xml=True, navigation=True):
        """Convenience function to disable WMS/WMTS|WFS|WCS buttons"""

        if services:
            self.tbAddData.setEnabled(False)
            self.mActionAddWms.setEnabled(False)
            self.mActionAddWfs.setEnabled(False)
            self.mActionAddWcs.setEnabled(False)
            self.mActionAddAms.setEnabled(False)
            self.mActionAddAfs.setEnabled(False)
            self.mActionAddGisFile.setEnabled(False)

        if xml:
            self.btnShowXml.setEnabled(False)

        if navigation:
            self.btnFirst.setEnabled(False)
            self.btnPrev.setEnabled(False)
            self.btnNext.setEnabled(False)
            self.btnLast.setEnabled(False)

    def help(self):
        """launch help"""

        open_url(get_help_url())

    def reject(self):
        """back out of dialogue"""

        QDialog.reject(self)
        self.rubber_band.reset()

    def _get_csw(self):
        """convenience function to init owslib.csw.CatalogueServiceWeb""" # spellok

        # connect to the server
        with OverrideCursor(Qt.WaitCursor):
            try:
                self.catalog = CatalogueServiceWeb(self.catalog_url, # spellok
                                                   timeout=self.timeout,
                                                   username=self.catalog_username,
                                                   password=self.catalog_password)
                return True
            except ExceptionReport as err:
                msg = self.tr('Error connecting to service: {0}').format(err)
            except ValueError as err:
                msg = self.tr('Value Error: {0}').format(err)
            except Exception as err:
                msg = self.tr('Unknown Error: {0}').format(err)

        QMessageBox.warning(self, self.tr('CSW Connection error'), msg)
        return False

    def install_proxy(self):
        """set proxy if one is set in QGIS network settings"""

        # initially support HTTP for now
        if self.settings.value('/proxy/proxyEnabled') == 'true':
            if self.settings.value('/proxy/proxyType') == 'HttpProxy':
                ptype = 'http'
            else:
                return

            user = self.settings.value('/proxy/proxyUser')
            password = self.settings.value('/proxy/proxyPassword')
            host = self.settings.value('/proxy/proxyHost')
            port = self.settings.value('/proxy/proxyPort')

            proxy_up = ''
            proxy_port = ''

            if all([user != '', password != '']):
                proxy_up = '%s:%s@' % (user, password)

            if port != '':
                proxy_port = ':%s' % port

            conn = '%s://%s%s%s' % (ptype, proxy_up, host, proxy_port)
            install_opener(build_opener(ProxyHandler({ptype: conn})))


def save_connections():
    """save servers to list"""

    ManageConnectionsDialog(0).exec_()


def get_item_data(item, field):
    """return identifier for a QTreeWidgetItem"""

    return item.data(_get_field_value(field), 32)


def set_item_data(item, field, value):
    """set identifier for a QTreeWidgetItem"""

    item.setData(_get_field_value(field), 32, value)


def _get_field_value(field):
    """convenience function to return field value integer"""

    value = 0

    if field == 'identifier':
        value = 0
    if field == 'link':
        value = 1

    return value


def bbox_to_polygon(bbox):
    """converts OWSLib bbox object to list of QgsPointXY objects"""

    if all([bbox.minx is not None,
            bbox.maxx is not None,
            bbox.miny is not None,
            bbox.maxy is not None]):
        minx = float(bbox.minx)
        miny = float(bbox.miny)
        maxx = float(bbox.maxx)
        maxy = float(bbox.maxy)

        return 'POLYGON((%.2f %.2f, %.2f %.2f, %.2f %.2f, %.2f %.2f, %.2f %.2f))' % (minx, miny, minx, maxy, maxx, maxy, maxx, miny, minx, miny)  # noqa
    else:
        return None
