/********************************************************************************
** Form generated from reading UI file 'pluginceshi.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINCESHI_H
#define UI_PLUGINCESHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginceshiClass
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *pluginceshiClass)
    {
        if (pluginceshiClass->objectName().isEmpty())
            pluginceshiClass->setObjectName(QString::fromUtf8("pluginceshiClass"));
        pluginceshiClass->resize(600, 400);
        horizontalLayout_2 = new QHBoxLayout(pluginceshiClass);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(pluginceshiClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 5, 1);

        pushButton_2 = new QPushButton(pluginceshiClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        pushButton = new QPushButton(pluginceshiClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        retranslateUi(pluginceshiClass);

        QMetaObject::connectSlotsByName(pluginceshiClass);
    } // setupUi

    void retranslateUi(QWidget *pluginceshiClass)
    {
        pluginceshiClass->setWindowTitle(QApplication::translate("pluginceshiClass", "pluginceshi", nullptr));
        pushButton_2->setText(QApplication::translate("pluginceshiClass", "PushButton", nullptr));
        pushButton->setText(QApplication::translate("pluginceshiClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pluginceshiClass: public Ui_pluginceshiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINCESHI_H
