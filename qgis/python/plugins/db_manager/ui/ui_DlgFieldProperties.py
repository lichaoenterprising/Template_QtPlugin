# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'C:/src/qgis/python/plugins/db_manager/ui/DlgFieldProperties.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_DbManagerDlgFieldProperties(object):
    def setupUi(self, DbManagerDlgFieldProperties):
        DbManagerDlgFieldProperties.setObjectName("DbManagerDlgFieldProperties")
        DbManagerDlgFieldProperties.resize(354, 247)
        self.vboxlayout = QtWidgets.QVBoxLayout(DbManagerDlgFieldProperties)
        self.vboxlayout.setObjectName("vboxlayout")
        self.gridlayout = QtWidgets.QGridLayout()
        self.gridlayout.setObjectName("gridlayout")
        self.label = QtWidgets.QLabel(DbManagerDlgFieldProperties)
        self.label.setObjectName("label")
        self.gridlayout.addWidget(self.label, 0, 0, 1, 1)
        self.editName = QtWidgets.QLineEdit(DbManagerDlgFieldProperties)
        self.editName.setText("")
        self.editName.setObjectName("editName")
        self.gridlayout.addWidget(self.editName, 0, 1, 1, 1)
        self.label_2 = QtWidgets.QLabel(DbManagerDlgFieldProperties)
        self.label_2.setObjectName("label_2")
        self.gridlayout.addWidget(self.label_2, 1, 0, 1, 1)
        self.cboType = QtWidgets.QComboBox(DbManagerDlgFieldProperties)
        self.cboType.setEditable(True)
        self.cboType.setInsertPolicy(QtWidgets.QComboBox.NoInsert)
        self.cboType.setObjectName("cboType")
        self.gridlayout.addWidget(self.cboType, 1, 1, 1, 1)
        self.label_3 = QtWidgets.QLabel(DbManagerDlgFieldProperties)
        self.label_3.setObjectName("label_3")
        self.gridlayout.addWidget(self.label_3, 3, 0, 1, 1)
        self.chkNull = QtWidgets.QCheckBox(DbManagerDlgFieldProperties)
        self.chkNull.setText("")
        self.chkNull.setChecked(True)
        self.chkNull.setObjectName("chkNull")
        self.gridlayout.addWidget(self.chkNull, 3, 1, 1, 1)
        self.label_4 = QtWidgets.QLabel(DbManagerDlgFieldProperties)
        self.label_4.setObjectName("label_4")
        self.gridlayout.addWidget(self.label_4, 4, 0, 1, 1)
        self.editDefault = QtWidgets.QLineEdit(DbManagerDlgFieldProperties)
        self.editDefault.setText("")
        self.editDefault.setObjectName("editDefault")
        self.gridlayout.addWidget(self.editDefault, 4, 1, 1, 1)
        self.label_5 = QtWidgets.QLabel(DbManagerDlgFieldProperties)
        self.label_5.setObjectName("label_5")
        self.gridlayout.addWidget(self.label_5, 2, 0, 1, 1)
        self.editLength = QtWidgets.QLineEdit(DbManagerDlgFieldProperties)
        self.editLength.setText("")
        self.editLength.setObjectName("editLength")
        self.gridlayout.addWidget(self.editLength, 2, 1, 1, 1)
        self.vboxlayout.addLayout(self.gridlayout)
        self.buttonBox = QtWidgets.QDialogButtonBox(DbManagerDlgFieldProperties)
        self.buttonBox.setOrientation(QtCore.Qt.Horizontal)
        self.buttonBox.setStandardButtons(QtWidgets.QDialogButtonBox.Cancel|QtWidgets.QDialogButtonBox.Ok)
        self.buttonBox.setObjectName("buttonBox")
        self.vboxlayout.addWidget(self.buttonBox)

        self.retranslateUi(DbManagerDlgFieldProperties)
        self.buttonBox.rejected.connect(DbManagerDlgFieldProperties.reject)
        QtCore.QMetaObject.connectSlotsByName(DbManagerDlgFieldProperties)
        DbManagerDlgFieldProperties.setTabOrder(self.editName, self.cboType)
        DbManagerDlgFieldProperties.setTabOrder(self.cboType, self.editLength)
        DbManagerDlgFieldProperties.setTabOrder(self.editLength, self.chkNull)
        DbManagerDlgFieldProperties.setTabOrder(self.chkNull, self.editDefault)
        DbManagerDlgFieldProperties.setTabOrder(self.editDefault, self.buttonBox)

    def retranslateUi(self, DbManagerDlgFieldProperties):
        _translate = QtCore.QCoreApplication.translate
        DbManagerDlgFieldProperties.setWindowTitle(_translate("DbManagerDlgFieldProperties", "Field properties"))
        self.label.setText(_translate("DbManagerDlgFieldProperties", "Name"))
        self.label_2.setText(_translate("DbManagerDlgFieldProperties", "Type"))
        self.label_3.setText(_translate("DbManagerDlgFieldProperties", "Can be NULL"))
        self.label_4.setText(_translate("DbManagerDlgFieldProperties", "Default value expression"))
        self.editDefault.setToolTip(_translate("DbManagerDlgFieldProperties", "<html><head/><body><p>Properly quoted PostgreSQL expression (e.g. <code>4</code>, <code>\'text\'</code> or  <code>nextval(\'foo_id_seq\')</code><br/></p></body></html>"))
        self.label_5.setText(_translate("DbManagerDlgFieldProperties", "Length"))

