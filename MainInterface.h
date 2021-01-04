#pragma once
#include <QString>
#include <QWidget>
#include <QPluginLoader>

class MainInterface
{
public:
	virtual ~MainInterface() {}
	virtual QString name() = 0;
	virtual QString information() = 0;
	//����һ��Widget���õ�centerwidget�н�����ʾ  
	virtual QWidget *centerWidget() = 0;
};
//step 2 �����ӿ�
#define MainInterface_iid "com.Interface.MainInterface"
Q_DECLARE_INTERFACE(MainInterface, MainInterface_iid)

