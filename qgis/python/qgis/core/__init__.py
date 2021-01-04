# -*- coding: utf-8 -*-

"""
***************************************************************************
    __init__.py
    ---------------------
    Date                 : May 2014
    Copyright            : (C) 2014 by Nathan Woodrow
    Email                : woodrow dot nathan at gmail dot com
***************************************************************************
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
***************************************************************************
"""

__author__ = 'Nathan Woodrow'
__date__ = 'May 2014'
__copyright__ = '(C) 2014, Nathan Woodrow'
# This will get replaced with a git SHA1 when you do a git archive
__revision__ = '$Format:%H$'

from qgis.PyQt.QtCore import NULL
from qgis._core import *

from .additions.edit import edit, QgsEditError
from .additions.fromfunction import fromFunction
from .additions.metaenum import metaEnumFromType, metaEnumFromValue
from .additions.processing import processing_output_layer_repr, processing_source_repr
from .additions.projectdirtyblocker import ProjectDirtyBlocker
from .additions.qgsfeature import mapping_feature
from .additions.qgsfunction import register_function, qgsfunction
from .additions.qgsgeometry import _geometryNonZero, mapping_geometry
from .additions.qgssettings import _qgssettings_enum_value, _qgssettings_set_enum_value, _qgssettings_flag_value
from .additions.qgstaskwrapper import QgsTaskWrapper
from .additions.readwritecontextentercategory import ReadWriteContextEnterCategory

# Injections into classes
QgsFeature.__geo_interface__ = property(mapping_feature)
QgsGeometry.__bool__ = _geometryNonZero
QgsGeometry.__geo_interface__ = property(mapping_geometry)
QgsGeometry.__nonzero__ = _geometryNonZero
QgsProcessingFeatureSourceDefinition.__repr__ = processing_source_repr
QgsProcessingOutputLayerDefinition.__repr__ = processing_output_layer_repr
QgsProject.blockDirtying = ProjectDirtyBlocker
QgsReadWriteContext.enterCategory = ReadWriteContextEnterCategory
QgsSettings.enumValue = _qgssettings_enum_value
QgsSettings.setEnumValue = _qgssettings_set_enum_value
QgsSettings.flagValue = _qgssettings_flag_value
QgsTask.fromFunction = fromFunction
"""
This folder is completed using sipify.pl script
It is not aimed to be manually edited
"""
# The following has been generated automatically from src/core/geometry/qgsabstractgeometry.h
QgsAbstractGeometry.SegmentationToleranceType.baseClass = QgsAbstractGeometry
# The following has been generated automatically from src/core/auth/qgsauthmanager.h
QgsAuthManager.MessageLevel.baseClass = QgsAuthManager
# The following has been generated automatically from src/core/qgsdataitem.h
QgsDataItem.Type.baseClass = QgsDataItem
QgsDataItem.State.baseClass = QgsDataItem
QgsLayerItem.LayerType.baseClass = QgsLayerItem
# The following has been generated automatically from src/core/qgsdataprovider.h
QgsDataProvider.DataCapability.baseClass = QgsDataProvider
# The following has been generated automatically from src/core/qgsdatasourceuri.h
QgsDataSourceUri.SslMode.baseClass = QgsDataSourceUri
# The following has been generated automatically from src/core/qgsdefaultvalue.h
QgsDefaultValue.__bool__ = lambda self: self.isValid()
# The following has been generated automatically from src/core/qgsfieldproxymodel.h
QgsFieldProxyModel.Filters.baseClass = QgsFieldProxyModel
Filters = QgsFieldProxyModel  # dirty hack since SIP seems to introduce the flags in module
# The following has been generated automatically from src/core/geometry/qgsgeometry.h
QgsGeometry.BufferSide.baseClass = QgsGeometry
QgsGeometry.EndCapStyle.baseClass = QgsGeometry
QgsGeometry.JoinStyle.baseClass = QgsGeometry
# The following has been generated automatically from src/core/locator/qgslocatorfilter.h
QgsLocatorFilter.Priority.baseClass = QgsLocatorFilter
QgsLocatorFilter.Flags.baseClass = QgsLocatorFilter
Flags = QgsLocatorFilter  # dirty hack since SIP seems to introduce the flags in module
# The following has been generated automatically from src/core/qgsmaplayer.h
QgsMapLayer.LayerFlag.baseClass = QgsMapLayer
QgsMapLayer.LayerFlags.baseClass = QgsMapLayer
LayerFlags = QgsMapLayer  # dirty hack since SIP seems to introduce the flags in module
QgsMapLayer.StyleCategory.baseClass = QgsMapLayer
QgsMapLayer.StyleCategories.baseClass = QgsMapLayer
StyleCategories = QgsMapLayer  # dirty hack since SIP seems to introduce the flags in module
# The following has been generated automatically from src/core/qgsmaplayerproxymodel.h
QgsMapLayerProxyModel.Filters.baseClass = QgsMapLayerProxyModel
Filters = QgsMapLayerProxyModel  # dirty hack since SIP seems to introduce the flags in module
# The following has been generated automatically from src/core/qgsnetworkcontentfetcherregistry.h
QgsNetworkContentFetcherRegistry.FetchingMode.baseClass = QgsNetworkContentFetcherRegistry
# The following has been generated automatically from src/core/raster/qgsrasterprojector.h
QgsRasterProjector.Precision.baseClass = QgsRasterProjector
# The following has been generated automatically from src/core/qgssnappingconfig.h
QgsSnappingConfig.SnappingMode.baseClass = QgsSnappingConfig
QgsSnappingConfig.SnappingType.baseClass = QgsSnappingConfig
# The following has been generated automatically from src/core/qgstolerance.h
QgsTolerance.UnitType.baseClass = QgsTolerance
# The following has been generated automatically from src/core/qgsunittypes.h
QgsUnitTypes.SystemOfMeasurement.baseClass = QgsUnitTypes
QgsUnitTypes.DistanceUnit.baseClass = QgsUnitTypes
QgsUnitTypes.AreaUnit.baseClass = QgsUnitTypes
QgsUnitTypes.AngleUnit.baseClass = QgsUnitTypes
QgsUnitTypes.RenderUnit.baseClass = QgsUnitTypes
QgsUnitTypes.LayoutUnit.baseClass = QgsUnitTypes
# The following has been generated automatically from src/core/qgsvectorsimplifymethod.h
QgsVectorSimplifyMethod.SimplifyHint.baseClass = QgsVectorSimplifyMethod
QgsVectorSimplifyMethod.SimplifyHints.baseClass = QgsVectorSimplifyMethod
SimplifyHints = QgsVectorSimplifyMethod  # dirty hack since SIP seems to introduce the flags in module
QgsVectorSimplifyMethod.SimplifyAlgorithm.baseClass = QgsVectorSimplifyMethod
# The following has been generated automatically from src/core/geometry/qgswkbtypes.h
QgsWkbTypes.GeometryType.baseClass = QgsWkbTypes
