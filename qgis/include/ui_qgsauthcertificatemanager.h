/********************************************************************************
** Form generated from reading UI file 'qgsauthcertificatemanager.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGSAUTHCERTIFICATEMANAGER_H
#define UI_QGSAUTHCERTIFICATEMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qgsauthauthoritieseditor.h"
#include "qgsauthidentitieseditor.h"
#include "qgsauthserverseditor.h"

QT_BEGIN_NAMESPACE

class Ui_QgsAuthCertManager
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabIdentities;
    QVBoxLayout *verticalLayout_2;
    QgsAuthIdentitiesEditor *wdgtIdentitiesEditor;
    QWidget *tabServers;
    QVBoxLayout *verticalLayout_4;
    QgsAuthServersEditor *wdgtServersEditor;
    QWidget *tabAuthorities;
    QVBoxLayout *verticalLayout_5;
    QgsAuthAuthoritiesEditor *wdgtAuthoritiesEditor;
    QLabel *lblNote;

    void setupUi(QWidget *QgsAuthCertManager)
    {
        if (QgsAuthCertManager->objectName().isEmpty())
            QgsAuthCertManager->setObjectName(QStringLiteral("QgsAuthCertManager"));
        QgsAuthCertManager->resize(706, 495);
        verticalLayout = new QVBoxLayout(QgsAuthCertManager);
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(QgsAuthCertManager);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabIdentities = new QWidget();
        tabIdentities->setObjectName(QStringLiteral("tabIdentities"));
        verticalLayout_2 = new QVBoxLayout(tabIdentities);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, -1, 6, 6);
        wdgtIdentitiesEditor = new QgsAuthIdentitiesEditor(tabIdentities);
        wdgtIdentitiesEditor->setObjectName(QStringLiteral("wdgtIdentitiesEditor"));

        verticalLayout_2->addWidget(wdgtIdentitiesEditor);

        tabWidget->addTab(tabIdentities, QString());
        tabServers = new QWidget();
        tabServers->setObjectName(QStringLiteral("tabServers"));
        verticalLayout_4 = new QVBoxLayout(tabServers);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, -1, 6, 6);
        wdgtServersEditor = new QgsAuthServersEditor(tabServers);
        wdgtServersEditor->setObjectName(QStringLiteral("wdgtServersEditor"));

        verticalLayout_4->addWidget(wdgtServersEditor);

        tabWidget->addTab(tabServers, QString());
        tabAuthorities = new QWidget();
        tabAuthorities->setObjectName(QStringLiteral("tabAuthorities"));
        verticalLayout_5 = new QVBoxLayout(tabAuthorities);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, -1, 6, 6);
        wdgtAuthoritiesEditor = new QgsAuthAuthoritiesEditor(tabAuthorities);
        wdgtAuthoritiesEditor->setObjectName(QStringLiteral("wdgtAuthoritiesEditor"));

        verticalLayout_5->addWidget(wdgtAuthoritiesEditor);

        tabWidget->addTab(tabAuthorities, QString());

        verticalLayout->addWidget(tabWidget);

        lblNote = new QLabel(QgsAuthCertManager);
        lblNote->setObjectName(QStringLiteral("lblNote"));
        QFont font;
        font.setItalic(true);
        lblNote->setFont(font);
        lblNote->setStyleSheet(QStringLiteral("color: rgb(128, 128, 128);"));
        lblNote->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblNote);


        retranslateUi(QgsAuthCertManager);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QgsAuthCertManager);
    } // setupUi

    void retranslateUi(QWidget *QgsAuthCertManager)
    {
        QgsAuthCertManager->setWindowTitle(QApplication::translate("QgsAuthCertManager", "Authentication Certificate Editors", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabIdentities), QApplication::translate("QgsAuthCertManager", "Identities", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabServers), QApplication::translate("QgsAuthCertManager", "Servers", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAuthorities), QApplication::translate("QgsAuthCertManager", "Authorities", nullptr));
        lblNote->setText(QApplication::translate("QgsAuthCertManager", "Note: Editing writes directly to authentication database", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QgsAuthCertManager: public Ui_QgsAuthCertManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGSAUTHCERTIFICATEMANAGER_H
