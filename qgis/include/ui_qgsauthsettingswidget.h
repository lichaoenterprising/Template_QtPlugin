/********************************************************************************
** Form generated from reading UI file 'qgsauthsettingswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSAUTHSETTINGSWIDGET_H
#define UI_QGSAUTHSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsauthconfigselect.h"
#include "qgspasswordlineedit.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAuthSettingsWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabAuth;
    QWidget *tabConfigurations;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QgsAuthConfigSelect *mAuthConfigSelect;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabBasic;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnConvertToEncrypted;
    QCheckBox *cbStorePassword;
    QLabel *lblWarning;
    QLineEdit *txtUserName;
    QCheckBox *cbStoreUsername;
    QgsPasswordLineEdit *txtPassword;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QLabel *lblBasic;

    void setupUi(QWidget *QgsAuthSettingsWidget)
    {
        if (QgsAuthSettingsWidget->objectName().isEmpty())
            QgsAuthSettingsWidget->setObjectName(QStringLiteral("QgsAuthSettingsWidget"));
        QgsAuthSettingsWidget->resize(226, 179);
        verticalLayout = new QVBoxLayout(QgsAuthSettingsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabAuth = new QTabWidget(QgsAuthSettingsWidget);
        tabAuth->setObjectName(QStringLiteral("tabAuth"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabAuth->sizePolicy().hasHeightForWidth());
        tabAuth->setSizePolicy(sizePolicy);
        tabConfigurations = new QWidget();
        tabConfigurations->setObjectName(QStringLiteral("tabConfigurations"));
        verticalLayout_4 = new QVBoxLayout(tabConfigurations);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        label_5 = new QLabel(tabConfigurations);
        label_5->setObjectName(QStringLiteral("label_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setTextFormat(Qt::PlainText);
        label_5->setWordWrap(true);

        verticalLayout_4->addWidget(label_5);

        mAuthConfigSelect = new QgsAuthConfigSelect(tabConfigurations);
        mAuthConfigSelect->setObjectName(QStringLiteral("mAuthConfigSelect"));
        mAuthConfigSelect->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(mAuthConfigSelect->sizePolicy().hasHeightForWidth());
        mAuthConfigSelect->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(mAuthConfigSelect);

        label_6 = new QLabel(tabConfigurations);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setTextFormat(Qt::PlainText);
        label_6->setWordWrap(true);

        verticalLayout_4->addWidget(label_6);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabAuth->addTab(tabConfigurations, QString());
        tabBasic = new QWidget();
        tabBasic->setObjectName(QStringLiteral("tabBasic"));
        gridLayout_3 = new QGridLayout(tabBasic);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btnConvertToEncrypted = new QPushButton(tabBasic);
        btnConvertToEncrypted->setObjectName(QStringLiteral("btnConvertToEncrypted"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnConvertToEncrypted->sizePolicy().hasHeightForWidth());
        btnConvertToEncrypted->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(btnConvertToEncrypted);


        gridLayout_3->addLayout(horizontalLayout, 4, 0, 1, 3);

        cbStorePassword = new QCheckBox(tabBasic);
        cbStorePassword->setObjectName(QStringLiteral("cbStorePassword"));
        cbStorePassword->setChecked(false);

        gridLayout_3->addWidget(cbStorePassword, 2, 2, 1, 1);

        lblWarning = new QLabel(tabBasic);
        lblWarning->setObjectName(QStringLiteral("lblWarning"));
        lblWarning->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);font-weight: bold;}"));
        lblWarning->setAlignment(Qt::AlignCenter);
        lblWarning->setWordWrap(true);

        gridLayout_3->addWidget(lblWarning, 3, 0, 1, 3);

        txtUserName = new QLineEdit(tabBasic);
        txtUserName->setObjectName(QStringLiteral("txtUserName"));
        txtUserName->setMinimumSize(QSize(80, 0));

        gridLayout_3->addWidget(txtUserName, 1, 1, 1, 1);

        cbStoreUsername = new QCheckBox(tabBasic);
        cbStoreUsername->setObjectName(QStringLiteral("cbStoreUsername"));
        cbStoreUsername->setChecked(false);

        gridLayout_3->addWidget(cbStoreUsername, 1, 2, 1, 1);

        txtPassword = new QgsPasswordLineEdit(tabBasic);
        txtPassword->setObjectName(QStringLiteral("txtPassword"));
        txtPassword->setMinimumSize(QSize(80, 0));
        txtPassword->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(txtPassword, 2, 1, 1, 1);

        label_3 = new QLabel(tabBasic);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 6, 1, 1, 1);

        label_2 = new QLabel(tabBasic);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        lblBasic = new QLabel(tabBasic);
        lblBasic->setObjectName(QStringLiteral("lblBasic"));
        lblBasic->setTextFormat(Qt::PlainText);
        lblBasic->setWordWrap(true);
        lblBasic->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_3->addWidget(lblBasic, 0, 0, 1, 3);

        tabAuth->addTab(tabBasic, QString());

        verticalLayout->addWidget(tabAuth);

#ifndef QT_NO_SHORTCUT
        label_3->setBuddy(txtPassword);
        label_2->setBuddy(txtUserName);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(tabAuth, mAuthConfigSelect);
        QWidget::setTabOrder(mAuthConfigSelect, txtUserName);
        QWidget::setTabOrder(txtUserName, cbStoreUsername);
        QWidget::setTabOrder(cbStoreUsername, txtPassword);
        QWidget::setTabOrder(txtPassword, cbStorePassword);
        QWidget::setTabOrder(cbStorePassword, btnConvertToEncrypted);

        retranslateUi(QgsAuthSettingsWidget);

        tabAuth->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsAuthSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *QgsAuthSettingsWidget)
    {
        QgsAuthSettingsWidget->setWindowTitle(QApplication::translate("QgsAuthSettingsWidget", "Form", nullptr));
        label_5->setText(QApplication::translate("QgsAuthSettingsWidget", "Choose or create an authentication configuration", nullptr));
        label_6->setText(QApplication::translate("QgsAuthSettingsWidget", "Configurations store encrypted credentials in the QGIS authentication database.", nullptr));
        tabAuth->setTabText(tabAuth->indexOf(tabConfigurations), QApplication::translate("QgsAuthSettingsWidget", "Configurations", nullptr));
        btnConvertToEncrypted->setText(QApplication::translate("QgsAuthSettingsWidget", "Convert to configuration", nullptr));
        cbStorePassword->setText(QApplication::translate("QgsAuthSettingsWidget", "Store", nullptr));
        lblWarning->setText(QApplication::translate("QgsAuthSettingsWidget", "Warning text!", nullptr));
        cbStoreUsername->setText(QApplication::translate("QgsAuthSettingsWidget", "Store", nullptr));
        txtPassword->setPlaceholderText(QApplication::translate("QgsAuthSettingsWidget", "Optional", nullptr));
        label_3->setText(QApplication::translate("QgsAuthSettingsWidget", "Passwor&d", nullptr));
        label_2->setText(QApplication::translate("QgsAuthSettingsWidget", "&User name", nullptr));
        lblBasic->setText(QString());
        tabAuth->setTabText(tabAuth->indexOf(tabBasic), QApplication::translate("QgsAuthSettingsWidget", "Basic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAuthSettingsWidget: public Ui_QgsAuthSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSAUTHSETTINGSWIDGET_H
