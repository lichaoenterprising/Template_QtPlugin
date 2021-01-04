#pragma once

#include <QtWidgets/QWidget>
#include "ui_pluginceshi.h"
#include "D:\ceshivideo\MediaPlayer\MainInterface.h"
#include <qfile.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qdir.h>
#include <qfiledialog.h>


//#include "d:\application_addin\ceshiMysqlToplugindll\QtWidgetsApplication1\QtWidgetsApplication1\QtWidgetsApplication1.h"

class pluginceshi : public QWidget
{
    Q_OBJECT

public:
    pluginceshi(QWidget *parent = Q_NULLPTR);
	bool pluginceshi::LoadPlugin(QString pluginpath);
	QWidget * pluginceshi::loadPlugin(QString pluginPath);
	QString _qsOpenFileName; //获取视频路径
signals:
	QString receiveVideoPlayerPath(QString videoPlayerPath);
	private slots:
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_3_clicked();
	void on_comboboxcurrentTextChanged(QString);
private:
    Ui::pluginceshiClass ui;

	

	QWidget* m_plugin;
	//IUIPLUGINBASE * P_plug;
	//QtWidgetsApplication1 *MySQLconfig_Plugindll;
};
