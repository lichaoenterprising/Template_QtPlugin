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
	//返回一个Widget设置到centerwidget中进行显示  
	virtual QWidget *centerWidget() = 0;
};
//step 2 声明接口
#define MainInterface_iid "com.Interface.MainInterface"
Q_DECLARE_INTERFACE(MainInterface, MainInterface_iid)

