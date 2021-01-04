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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginceshiClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QLabel *label_2;
    QWidget *widget_2;

    void setupUi(QWidget *pluginceshiClass)
    {
        if (pluginceshiClass->objectName().isEmpty())
            pluginceshiClass->setObjectName(QString::fromUtf8("pluginceshiClass"));
        pluginceshiClass->resize(563, 207);
        gridLayout_2 = new QGridLayout(pluginceshiClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 3, 1, 1);

        textEdit = new QTextEdit(pluginceshiClass);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 1, 1, 1);

        lineEdit = new QLineEdit(pluginceshiClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_4 = new QLabel(pluginceshiClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(pluginceshiClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 4, 3, 1, 1);

        pushButton = new QPushButton(pluginceshiClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 3, 1, 1);

        label = new QLabel(pluginceshiClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(pluginceshiClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        pushButton_3 = new QPushButton(pluginceshiClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 3, 1, 1);

        pushButton_4 = new QPushButton(pluginceshiClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 3, 1, 1);

        comboBox = new QComboBox(pluginceshiClass);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label_2 = new QLabel(pluginceshiClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        widget_2 = new QWidget(pluginceshiClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        gridLayout->addWidget(widget_2, 4, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(pluginceshiClass);

        QMetaObject::connectSlotsByName(pluginceshiClass);
    } // setupUi

    void retranslateUi(QWidget *pluginceshiClass)
    {
        pluginceshiClass->setWindowTitle(QApplication::translate("pluginceshiClass", "pluginceshi", nullptr));
        label_4->setText(QApplication::translate("pluginceshiClass", "choiceDll\357\274\232", nullptr));
        pushButton_2->setText(QApplication::translate("pluginceshiClass", "\346\265\213\350\257\2252", nullptr));
        pushButton->setText(QApplication::translate("pluginceshiClass", "\346\265\213\350\257\2251", nullptr));
        label->setText(QApplication::translate("pluginceshiClass", "name\357\274\232", nullptr));
        label_3->setText(QApplication::translate("pluginceshiClass", "widget\357\274\232", nullptr));
        pushButton_3->setText(QApplication::translate("pluginceshiClass", "\357\274\237", nullptr));
        pushButton_4->setText(QApplication::translate("pluginceshiClass", "dianwo", nullptr));
        label_2->setText(QApplication::translate("pluginceshiClass", "information\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pluginceshiClass: public Ui_pluginceshiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINCESHI_H
