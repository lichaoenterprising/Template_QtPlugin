/********************************************************************************
** Form generated from reading UI file 'qgsexpressionselectiondialogbase.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSEXPRESSIONSELECTIONDIALOGBASE_H
#define UI_QGSEXPRESSIONSELECTIONDIALOGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include "qgsexpressionbuilderwidget.h"

QT_BEGIN_NAMESPACE

class Ui_QgsExpressionSelectionDialogBase
{
public:
    QAction *mActionSelect;
    QAction *mActionAddToSelection;
    QAction *mActionRemoveFromSelection;
    QAction *mActionSelectIntersect;
    QGridLayout *gridLayout;
    QPushButton *mPbnClose;
    QToolButton *mButtonZoomToFeatures;
    QSpacerItem *horizontalSpacer;
    QToolButton *mButtonSelect;
    QDialogButtonBox *buttonBox;
    QgsExpressionBuilderWidget *mExpressionBuilder;

    void setupUi(QDialog *QgsExpressionSelectionDialogBase)
    {
        if (QgsExpressionSelectionDialogBase->objectName().isEmpty())
            QgsExpressionSelectionDialogBase->setObjectName(QStringLiteral("QgsExpressionSelectionDialogBase"));
        QgsExpressionSelectionDialogBase->resize(863, 547);
        mActionSelect = new QAction(QgsExpressionSelectionDialogBase);
        mActionSelect->setObjectName(QStringLiteral("mActionSelect"));
        mActionAddToSelection = new QAction(QgsExpressionSelectionDialogBase);
        mActionAddToSelection->setObjectName(QStringLiteral("mActionAddToSelection"));
        mActionRemoveFromSelection = new QAction(QgsExpressionSelectionDialogBase);
        mActionRemoveFromSelection->setObjectName(QStringLiteral("mActionRemoveFromSelection"));
        mActionSelectIntersect = new QAction(QgsExpressionSelectionDialogBase);
        mActionSelectIntersect->setObjectName(QStringLiteral("mActionSelectIntersect"));
        gridLayout = new QGridLayout(QgsExpressionSelectionDialogBase);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(3, 3, 3, 3);
        mPbnClose = new QPushButton(QgsExpressionSelectionDialogBase);
        mPbnClose->setObjectName(QStringLiteral("mPbnClose"));

        gridLayout->addWidget(mPbnClose, 1, 5, 1, 1);

        mButtonZoomToFeatures = new QToolButton(QgsExpressionSelectionDialogBase);
        mButtonZoomToFeatures->setObjectName(QStringLiteral("mButtonZoomToFeatures"));

        gridLayout->addWidget(mButtonZoomToFeatures, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        mButtonSelect = new QToolButton(QgsExpressionSelectionDialogBase);
        mButtonSelect->setObjectName(QStringLiteral("mButtonSelect"));
        mButtonSelect->setPopupMode(QToolButton::MenuButtonPopup);
        mButtonSelect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(mButtonSelect, 1, 3, 1, 1);

        buttonBox = new QDialogButtonBox(QgsExpressionSelectionDialogBase);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStandardButtons(QDialogButtonBox::Help);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);

        mExpressionBuilder = new QgsExpressionBuilderWidget(QgsExpressionSelectionDialogBase);
        mExpressionBuilder->setObjectName(QStringLiteral("mExpressionBuilder"));

        gridLayout->addWidget(mExpressionBuilder, 0, 0, 1, 6);

        QWidget::setTabOrder(mButtonZoomToFeatures, mButtonSelect);
        QWidget::setTabOrder(mButtonSelect, mPbnClose);

        retranslateUi(QgsExpressionSelectionDialogBase);

        QMetaObject::connectSlotsByName(QgsExpressionSelectionDialogBase);
    } // setupUi

    void retranslateUi(QDialog *QgsExpressionSelectionDialogBase)
    {
        QgsExpressionSelectionDialogBase->setWindowTitle(QApplication::translate("QgsExpressionSelectionDialogBase", "Select by Expression", nullptr));
        mActionSelect->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "Select features", nullptr));
        mActionAddToSelection->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "Add to current selection", nullptr));
        mActionRemoveFromSelection->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "Remove from current selection", nullptr));
        mActionSelectIntersect->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "Filter current selection", nullptr));
        mPbnClose->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "&Close", nullptr));
        mButtonZoomToFeatures->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "Zoom to Features", nullptr));
        mButtonSelect->setText(QApplication::translate("QgsExpressionSelectionDialogBase", "\342\200\246", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsExpressionSelectionDialogBase: public Ui_QgsExpressionSelectionDialogBase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSEXPRESSIONSELECTIONDIALOGBASE_H
