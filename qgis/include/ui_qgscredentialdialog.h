/********************************************************************************
** Form generated from reading UI file 'qgscredentialdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSCREDENTIALDIALOG_H
#define UI_QGSCREDENTIALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgspasswordlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsCredentialDialog
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QFormLayout *formLayout_2;
    QLabel *label_3;
    QLabel *labelRealm;
    QLabel *label;
    QLineEdit *leUsername;
    QLabel *label_2;
    QgsPasswordLineEdit *lePassword;
    QLabel *labelMessage;
    QWidget *page_2;
    QVBoxLayout *verticalLayout;
    QLabel *lblPasswordTitle;
    QVBoxLayout *verticalLayout_2;
    QgsPasswordLineEdit *leMasterPass;
    QgsPasswordLineEdit *leMasterPassVerify;
    QCheckBox *chkbxPasswordHelperEnable;
    QLabel *lblDontForget;
    QLabel *lblSavedForSession;
    QGroupBox *grpbxPassAttempts;
    QVBoxLayout *verticalLayout_21;
    QCheckBox *chkbxEraseAuthDb;

    void setupUi(QDialog *QgsCredentialDialog)
    {
        if (QgsCredentialDialog->objectName().isEmpty())
            QgsCredentialDialog->setObjectName(QStringLiteral("QgsCredentialDialog"));
        QgsCredentialDialog->resize(396, 289);
        formLayout = new QFormLayout(QgsCredentialDialog);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        buttonBox = new QDialogButtonBox(QgsCredentialDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);

        stackedWidget = new QStackedWidget(QgsCredentialDialog);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        formLayout_2 = new QFormLayout(page);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_3);

        labelRealm = new QLabel(page);
        labelRealm->setObjectName(QStringLiteral("labelRealm"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, labelRealm);

        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label);

        leUsername = new QLineEdit(page);
        leUsername->setObjectName(QStringLiteral("leUsername"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, leUsername);

        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        lePassword = new QgsPasswordLineEdit(page);
        lePassword->setObjectName(QStringLiteral("lePassword"));
        lePassword->setEchoMode(QLineEdit::Password);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lePassword);

        labelMessage = new QLabel(page);
        labelMessage->setObjectName(QStringLiteral("labelMessage"));

        formLayout_2->setWidget(3, QFormLayout::SpanningRole, labelMessage);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout = new QVBoxLayout(page_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lblPasswordTitle = new QLabel(page_2);
        lblPasswordTitle->setObjectName(QStringLiteral("lblPasswordTitle"));
        lblPasswordTitle->setStyleSheet(QStringLiteral("QLabel{ font-weight: bold; }s"));

        verticalLayout->addWidget(lblPasswordTitle);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        leMasterPass = new QgsPasswordLineEdit(page_2);
        leMasterPass->setObjectName(QStringLiteral("leMasterPass"));
        leMasterPass->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(leMasterPass);

        leMasterPassVerify = new QgsPasswordLineEdit(page_2);
        leMasterPassVerify->setObjectName(QStringLiteral("leMasterPassVerify"));
        leMasterPassVerify->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(leMasterPassVerify);


        verticalLayout->addLayout(verticalLayout_2);

        chkbxPasswordHelperEnable = new QCheckBox(page_2);
        chkbxPasswordHelperEnable->setObjectName(QStringLiteral("chkbxPasswordHelperEnable"));

        verticalLayout->addWidget(chkbxPasswordHelperEnable);

        lblDontForget = new QLabel(page_2);
        lblDontForget->setObjectName(QStringLiteral("lblDontForget"));
        lblDontForget->setStyleSheet(QLatin1String("QLabel {\n"
"color: rgb(128, 128, 128);\n"
"font-weight: bold;\n"
"}"));
        lblDontForget->setWordWrap(true);

        verticalLayout->addWidget(lblDontForget);

        lblSavedForSession = new QLabel(page_2);
        lblSavedForSession->setObjectName(QStringLiteral("lblSavedForSession"));
        lblSavedForSession->setStyleSheet(QLatin1String("QLabel {\n"
"color: rgb(128, 128, 128);\n"
"font-style: italic;\n"
"}"));
        lblSavedForSession->setWordWrap(true);

        verticalLayout->addWidget(lblSavedForSession);

        grpbxPassAttempts = new QGroupBox(page_2);
        grpbxPassAttempts->setObjectName(QStringLiteral("grpbxPassAttempts"));
        verticalLayout_21 = new QVBoxLayout(grpbxPassAttempts);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalLayout_21->setContentsMargins(6, 6, 6, 6);
        chkbxEraseAuthDb = new QCheckBox(grpbxPassAttempts);
        chkbxEraseAuthDb->setObjectName(QStringLiteral("chkbxEraseAuthDb"));

        verticalLayout_21->addWidget(chkbxEraseAuthDb);


        verticalLayout->addWidget(grpbxPassAttempts);

        stackedWidget->addWidget(page_2);

        formLayout->setWidget(1, QFormLayout::SpanningRole, stackedWidget);

        QWidget::setTabOrder(leUsername, lePassword);
        QWidget::setTabOrder(lePassword, leMasterPass);
        QWidget::setTabOrder(leMasterPass, leMasterPassVerify);
        QWidget::setTabOrder(leMasterPassVerify, chkbxEraseAuthDb);

        retranslateUi(QgsCredentialDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), QgsCredentialDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), QgsCredentialDialog, SLOT(reject()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QgsCredentialDialog);
    } // setupUi

    void retranslateUi(QDialog *QgsCredentialDialog)
    {
        QgsCredentialDialog->setWindowTitle(QApplication::translate("QgsCredentialDialog", "Enter Credentials", nullptr));
        label_3->setText(QApplication::translate("QgsCredentialDialog", "Realm", nullptr));
        labelRealm->setText(QApplication::translate("QgsCredentialDialog", "TextLabel", nullptr));
        label->setText(QApplication::translate("QgsCredentialDialog", "Username", nullptr));
        label_2->setText(QApplication::translate("QgsCredentialDialog", "Password", nullptr));
        labelMessage->setText(QApplication::translate("QgsCredentialDialog", "TextLabel", nullptr));
        lblPasswordTitle->setText(QString());
        leMasterPassVerify->setPlaceholderText(QApplication::translate("QgsCredentialDialog", "Verify password", nullptr));
        chkbxPasswordHelperEnable->setText(QApplication::translate("QgsCredentialDialog", "Store master password in your password manager", nullptr));
        lblDontForget->setText(QApplication::translate("QgsCredentialDialog", "Do not forget it:  NOT retrievable!", nullptr));
        lblSavedForSession->setText(QApplication::translate("QgsCredentialDialog", "Saved for session, until app is quit.", nullptr));
        grpbxPassAttempts->setTitle(QApplication::translate("QgsCredentialDialog", "Password attempts: #", nullptr));
        chkbxEraseAuthDb->setText(QApplication::translate("QgsCredentialDialog", "Erase authentication database?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsCredentialDialog: public Ui_QgsCredentialDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSCREDENTIALDIALOG_H
