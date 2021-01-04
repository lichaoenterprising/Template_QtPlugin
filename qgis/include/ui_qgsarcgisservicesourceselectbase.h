/********************************************************************************
** Form generated from reading UI file 'qgsarcgisservicesourceselectbase.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSARCGISSERVICESOURCESELECTBASE_H
#define UI_QGSARCGISSERVICESOURCESELECTBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QgsArcGisServiceSourceSelectBase
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *GroupBox1;
    QGridLayout *gridLayout_2;
    QComboBox *cmbConnections;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConnect;
    QPushButton *btnNew;
    QPushButton *btnEdit;
    QPushButton *btnDelete;
    QSpacerItem *spacerItem;
    QPushButton *btnLoad;
    QPushButton *btnSave;
    QHBoxLayout *horizontalLayoutFilter;
    QLabel *labelFilter;
    QLineEdit *lineFilter;
    QTreeView *treeView;
    QCheckBox *cbxUseTitleLayerName;
    QCheckBox *cbxFeatureCurrentViewExtent;
    QGroupBox *gbImageEncoding;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *gbCRS;
    QHBoxLayout *hboxLayout;
    QLabel *labelCoordRefSys;
    QSpacerItem *spacerItem1;
    QPushButton *btnChangeSpatialRefSys;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *QgsArcGisServiceSourceSelectBase)
    {
        if (QgsArcGisServiceSourceSelectBase->objectName().isEmpty())
            QgsArcGisServiceSourceSelectBase->setObjectName(QStringLiteral("QgsArcGisServiceSourceSelectBase"));
        QgsArcGisServiceSourceSelectBase->resize(592, 440);
        verticalLayout = new QVBoxLayout(QgsArcGisServiceSourceSelectBase);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        GroupBox1 = new QGroupBox(QgsArcGisServiceSourceSelectBase);
        GroupBox1->setObjectName(QStringLiteral("GroupBox1"));
        gridLayout_2 = new QGridLayout(GroupBox1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        cmbConnections = new QComboBox(GroupBox1);
        cmbConnections->setObjectName(QStringLiteral("cmbConnections"));

        gridLayout_2->addWidget(cmbConnections, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnConnect = new QPushButton(GroupBox1);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setEnabled(false);

        horizontalLayout->addWidget(btnConnect);

        btnNew = new QPushButton(GroupBox1);
        btnNew->setObjectName(QStringLiteral("btnNew"));

        horizontalLayout->addWidget(btnNew);

        btnEdit = new QPushButton(GroupBox1);
        btnEdit->setObjectName(QStringLiteral("btnEdit"));
        btnEdit->setEnabled(false);

        horizontalLayout->addWidget(btnEdit);

        btnDelete = new QPushButton(GroupBox1);
        btnDelete->setObjectName(QStringLiteral("btnDelete"));
        btnDelete->setEnabled(false);

        horizontalLayout->addWidget(btnDelete);

        spacerItem = new QSpacerItem(171, 30, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerItem);

        btnLoad = new QPushButton(GroupBox1);
        btnLoad->setObjectName(QStringLiteral("btnLoad"));

        horizontalLayout->addWidget(btnLoad);

        btnSave = new QPushButton(GroupBox1);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        horizontalLayout->addWidget(btnSave);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout->addWidget(GroupBox1);

        horizontalLayoutFilter = new QHBoxLayout();
        horizontalLayoutFilter->setObjectName(QStringLiteral("horizontalLayoutFilter"));
        labelFilter = new QLabel(QgsArcGisServiceSourceSelectBase);
        labelFilter->setObjectName(QStringLiteral("labelFilter"));
        labelFilter->setEnabled(true);

        horizontalLayoutFilter->addWidget(labelFilter);

        lineFilter = new QLineEdit(QgsArcGisServiceSourceSelectBase);
        lineFilter->setObjectName(QStringLiteral("lineFilter"));
        lineFilter->setEnabled(true);

        horizontalLayoutFilter->addWidget(lineFilter);


        verticalLayout->addLayout(horizontalLayoutFilter);

        treeView = new QTreeView(QgsArcGisServiceSourceSelectBase);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeView->setSortingEnabled(true);
        treeView->header()->setVisible(true);

        verticalLayout->addWidget(treeView);

        cbxUseTitleLayerName = new QCheckBox(QgsArcGisServiceSourceSelectBase);
        cbxUseTitleLayerName->setObjectName(QStringLiteral("cbxUseTitleLayerName"));

        verticalLayout->addWidget(cbxUseTitleLayerName);

        cbxFeatureCurrentViewExtent = new QCheckBox(QgsArcGisServiceSourceSelectBase);
        cbxFeatureCurrentViewExtent->setObjectName(QStringLiteral("cbxFeatureCurrentViewExtent"));

        verticalLayout->addWidget(cbxFeatureCurrentViewExtent);

        gbImageEncoding = new QGroupBox(QgsArcGisServiceSourceSelectBase);
        gbImageEncoding->setObjectName(QStringLiteral("gbImageEncoding"));
        horizontalLayout_2 = new QHBoxLayout(gbImageEncoding);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout->addWidget(gbImageEncoding);

        gbCRS = new QGroupBox(QgsArcGisServiceSourceSelectBase);
        gbCRS->setObjectName(QStringLiteral("gbCRS"));
        hboxLayout = new QHBoxLayout(gbCRS);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(9, 9, 9, 9);
        labelCoordRefSys = new QLabel(gbCRS);
        labelCoordRefSys->setObjectName(QStringLiteral("labelCoordRefSys"));

        hboxLayout->addWidget(labelCoordRefSys);

        spacerItem1 = new QSpacerItem(441, 23, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem1);

        btnChangeSpatialRefSys = new QPushButton(gbCRS);
        btnChangeSpatialRefSys->setObjectName(QStringLiteral("btnChangeSpatialRefSys"));
        btnChangeSpatialRefSys->setEnabled(false);

        hboxLayout->addWidget(btnChangeSpatialRefSys);


        verticalLayout->addWidget(gbCRS);

        buttonBox = new QDialogButtonBox(QgsArcGisServiceSourceSelectBase);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Help);

        verticalLayout->addWidget(buttonBox);

#ifndef QT_NO_SHORTCUT
        labelFilter->setBuddy(lineFilter);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(cmbConnections, btnConnect);
        QWidget::setTabOrder(btnConnect, btnNew);
        QWidget::setTabOrder(btnNew, btnEdit);
        QWidget::setTabOrder(btnEdit, btnDelete);
        QWidget::setTabOrder(btnDelete, btnLoad);
        QWidget::setTabOrder(btnLoad, btnSave);
        QWidget::setTabOrder(btnSave, lineFilter);
        QWidget::setTabOrder(lineFilter, treeView);
        QWidget::setTabOrder(treeView, cbxUseTitleLayerName);
        QWidget::setTabOrder(cbxUseTitleLayerName, cbxFeatureCurrentViewExtent);
        QWidget::setTabOrder(cbxFeatureCurrentViewExtent, btnChangeSpatialRefSys);

        retranslateUi(QgsArcGisServiceSourceSelectBase);

        QMetaObject::connectSlotsByName(QgsArcGisServiceSourceSelectBase);
    } // setupUi

    void retranslateUi(QDialog *QgsArcGisServiceSourceSelectBase)
    {
        GroupBox1->setTitle(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Server Connections", nullptr));
#ifndef QT_NO_TOOLTIP
        btnConnect->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Connect to selected database", nullptr));
#endif // QT_NO_TOOLTIP
        btnConnect->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "C&onnect", nullptr));
#ifndef QT_NO_TOOLTIP
        btnNew->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Create a new database connection", nullptr));
#endif // QT_NO_TOOLTIP
        btnNew->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "&New", nullptr));
#ifndef QT_NO_TOOLTIP
        btnEdit->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Edit selected database connection", nullptr));
#endif // QT_NO_TOOLTIP
        btnEdit->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Edit", nullptr));
#ifndef QT_NO_TOOLTIP
        btnDelete->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Remove connection to selected database", nullptr));
#endif // QT_NO_TOOLTIP
        btnDelete->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Remove", nullptr));
#ifndef QT_NO_TOOLTIP
        btnLoad->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Load connections from file", nullptr));
#endif // QT_NO_TOOLTIP
        btnLoad->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Load", nullptr));
#ifndef QT_NO_TOOLTIP
        btnSave->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Save connections to file", nullptr));
#endif // QT_NO_TOOLTIP
        btnSave->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Save", nullptr));
        labelFilter->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Fi&lter", nullptr));
#ifndef QT_NO_TOOLTIP
        lineFilter->setToolTip(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Display WFS FeatureTypes containing this word in the title, name or abstract", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        lineFilter->setWhatsThis(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Display WFS FeatureTypes containing this word in the title, name or abstract", nullptr));
#endif // QT_NO_WHATSTHIS
        cbxUseTitleLayerName->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Use title for layer name", nullptr));
        cbxFeatureCurrentViewExtent->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Only request features overlapping the current view extent", nullptr));
        gbImageEncoding->setTitle(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Image Encoding", nullptr));
        gbCRS->setTitle(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Coordinate Reference System", nullptr));
        labelCoordRefSys->setText(QString());
        btnChangeSpatialRefSys->setText(QApplication::translate("QgsArcGisServiceSourceSelectBase", "Change...", nullptr));
        Q_UNUSED(QgsArcGisServiceSourceSelectBase);
    } // retranslateUi

};

namespace Ui {
    class QgsArcGisServiceSourceSelectBase: public Ui_QgsArcGisServiceSourceSelectBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSARCGISSERVICESOURCESELECTBASE_H
