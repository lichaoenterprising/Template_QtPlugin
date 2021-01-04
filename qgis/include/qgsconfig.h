
// QGSCONFIG.H

#ifndef QGSCONFIG_H
#define QGSCONFIG_H

// Version must be specified according to
// <int>.<int>.<int>-<any text>.
// or else upgrading old project file will not work
// reliably.
#define VERSION "3.4.1-Madeira"

//used in vim src/core/qgis.cpp
//The way below should work but it resolves to a number like 0110 which the compiler treats as octal I think
//because debuggin it out shows the decimal number 72 which results in incorrect version status.
//As a short term fix I (Tim) am defining the version in top level cmake. It would be good to
//reinstate this more generic approach below at some point though
//#define VERSION_INT 341
#define VERSION_INT 30401
#define ABISYM(x) x ## 30401
//used in main.cpp and anywhere else where the release name is needed
#define RELEASE_NAME "Madeira"

#define QGIS_PLUGIN_SUBDIR "plugins"
#define QGIS_DATA_SUBDIR "."
#define QGIS_LIBEXEC_SUBDIR "."
#define QGIS_LIB_SUBDIR "lib"
#define QGIS_QML_SUBDIR "qml"
#define CMAKE_INSTALL_PREFIX "C:/OSGeo4W64/apps/qgis"
#define CMAKE_SOURCE_DIR "C:/src/qgis"

#define QGIS_SERVER_MODULE_SUBDIR "server"

#define QSCINTILLA_VERSION_STR "2.10.8"

#if defined( __APPLE__ )
//used by Mac to find system or bundle resources relative to amount of bundling
#define QGIS_MACAPP_BUNDLE 
#endif

#define QT_PLUGINS_DIR "C:/OSGeo4W64/apps/Qt5/plugins"
#define OSG_PLUGINS_PATH ""

/* #undef USING_NMAKE */

#define USING_NINJA

#define HAVE_GUI

#define HAVE_POSTGRESQL

#define HAVE_ORACLE

/* #undef HAVE_OSGEARTHQT */

#define SERVER_SKIP_ECW

#define HAVE_SERVER_PYTHON_PLUGINS

#define HAVE_OPENCL

/* #undef ENABLE_MODELTEST */

#define HAVE_3D

#define USE_THREAD_LOCAL

/* #undef QGISDEBUG */

/* #undef HAVE_QUICK */

#endif

