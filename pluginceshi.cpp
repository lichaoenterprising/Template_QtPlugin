#include "pluginceshi.h"

pluginceshi::pluginceshi(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(on_pushButton_2_clicked()));
	connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(on_pushButton_4_clicked()));
	connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(on_pushButton_3_clicked()));
	connect(ui.comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(on_comboboxcurrentTextChanged(QString)));

	
	
}
void pluginceshi::on_pushButton_clicked()
{
	LoadPlugin("D:\\application_addin\\ceshiMysqlToplugindll\\QtWidgetsApplication1\\x64\\Release\\QtWidgetsApplication1.dll");
}
void pluginceshi::on_pushButton_2_clicked()
{
	LoadPlugin("D:\\987654321\\bianchengdll\\x64\\Release\\gisTest2.dll");
}
void pluginceshi::on_pushButton_4_clicked()
{
	QString s = QFileDialog::getOpenFileName(this,QString::fromLocal8Bit("选择dll插件文件"),".",QString::fromLocal8Bit("插件格式(*.dll)"));
	ui.comboBox->addItem(s);
}
void pluginceshi::on_pushButton_3_clicked()
{
	//connect(this, SIGNAL(receiveVideoPlayerPath(QString)), m_plugin, SLOT(receiveVideoPlayerPath(QString)));
	_qsOpenFileName = QFileDialog::getOpenFileName(this, QStringLiteral("打开视频文件"), ".", "AVI(*.avi);;MP4(*.mp4);;WMV(*.wmv);;*");
	//emit receiveVideoPlayerPath(_qsOpenFileName);
	//m_plugin = loadPlugin("D:\\ceshivideo\\MediaPlayer\\release\\MediaPlayer.dll");
	//m_plugin = loadPlugin("./plugins/gisTest2.dll");
	m_plugin = loadPlugin("D:/fengzhuang_dll/ImageProcess/x64/Release/ImageProcess.dll");
	m_plugin->show();
}
void pluginceshi::on_comboboxcurrentTextChanged(QString path)
{
	LoadPlugin(path);
}
QWidget *pluginceshi::loadPlugin(QString pluginPath)
{
	QFile file(pluginPath);
	qDebug() << file.fileName();
	QPluginLoader loader(pluginPath);
	if (loader.load())
	{
		qDebug() << pluginPath + " load ok";
	}
	else
	{
		qDebug() << pluginPath + " load failed !";
		return NULL;
	}

	QObject* plugin = loader.instance();

	if (plugin)
	{
		MainInterface* interface = qobject_cast<MainInterface*>(plugin);
		if (interface)
		{
			//QWidget* w = interface->centerWidget();
			QWidget * w1 = interface->centerWidget1(_qsOpenFileName, 0);
			ui.textEdit->setText(interface->receiveVideoPlayerPath(_qsOpenFileName));
			return w1;
		}
	}
	else {
		qDebug() << "loader.instance failed!";
		return NULL;
	}

}

bool pluginceshi::LoadPlugin(QString pluginpath)
{
	QFile file(pluginpath);
	if (!file.exists())
	{
		QMessageBox::warning(this, QStringLiteral("错误信息"), QString::fromLocal8Bit("找不到%1文件").arg(pluginpath));
		return false;
	}
	QLibrary lib;
	QString file_name = pluginpath;
	lib.setFileName(file_name);

	if (!lib.load())
	{
		QMessageBox::warning(nullptr, "提  示", "动态加载【" + file_name + "】或其依赖的DLL文件失败。");
		qDebug() << lib.errorString();
	}

	QPluginLoader loader(pluginpath);
	QObject *instance = loader.instance();
	qDebug() << instance;//
	if (instance != NULL)
	{
		qDebug() << pluginpath + " is loaded";
		MainInterface *avc = qobject_cast<MainInterface *>(instance);
		ui.lineEdit->setText(avc->name());
		//ui.textEdit->setText(avc->information());
		//ui.textEdit->setText(avc->receiveVideoPlayerPath(pluginpath));
		//MySQLconfig_Plugindll = qobject_cast<MySQLconfig_Plugindll * >(instance);
		//auto centerWidget = qobject_cast<MainInterface*>(sender()->parent())->centerWidget();
		ui.widget_2 = avc->centerWidget();
		ui.widget_2->show();
	
		
		//avc->information();
		//avc->centerWidget();
		//ui.widget_2->centerW;
		//m_Form->show();
		//ui->lineEdit->setText(QString::number(avc->add(7, 8)));
		return true;
	}
	else {
		QMessageBox::information(this, "failed to load plugin", loader.errorString());
	}
	// 需要手动释放  
	delete instance;
}

//void ReadPluginsInfo(const QString & pluginsDirPath /*= ""*/)
//{
//	QString pluginsPath = pluginsDirPath;
//	if (pluginsDirPath.isEmpty())
//	{
//		pluginsPath = QApplication::applicationDirPath();
//	}
//	QDir pluginsDir(pluginsPath);
//	pluginsDir.cd("Plugins");
//
//	QFileInfoList pluginsFile = pluginsDir.entryInfoList(QStringList() << "*.dll", QDir::Files);
//	foreach(QFileInfo fileInfo, pluginsFile)
//	{
//		QPluginLoader loader(fileInfo.absoluteFilePath());
//		bool isLoad = loader.isLoaded();
//		QString info = loader.errorString();
//
//		if (QObject * plugin = loader.instance())
//		{
//			if (MainInterface * pinterface = dynamic_cast<MainInterface*>(plugin))
//			{
//				pinterface->install(center());//初始化插件
//				m_lstPluginInterFace.push_back(pinterface);
//			}
//		}
//		else
//		{
//			qDebug() << loader.errorString();
//		}
//	}
//}