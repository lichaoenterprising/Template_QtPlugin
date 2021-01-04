#include "pluginceshi.h"
#include <QtWidgets/QApplication>
#include <qgsapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QgsApplication::setPrefixPath("qgis", true);
	QgsApplication::initQgis();    //初始化QGIS应用
    pluginceshi w;
    w.show();
    return a.exec();
}
