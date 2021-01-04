  /***************************************************************************
                              qgsogrutils.h
                              -------------
     begin                : February 2016
     copyright            : (C) 2016 Nyall Dawson
     email                : nyall dot dawson at gmail dot com
  ***************************************************************************
  *                                                                         *
  *   This program is free software; you can redistribute it and/or modify  *
  *   it under the terms of the GNU General Public License as published by  *
  *   the Free Software Foundation; either version 2 of the License, or     *
  *   (at your option) any later version.                                   *
  *                                                                         *
  ***************************************************************************/
 
 #ifndef QGSOGRUTILS_H
 #define QGSOGRUTILS_H
 
 #define SIP_NO_FILE
 
 #include "qgis_core.h"
 #include "qgsfeature.h"
 
 #include <ogr_api.h>
 #include <gdal.h>
 #include <gdalwarper.h>
 #include "cpl_conv.h"
 #include "cpl_string.h"
 
 namespace gdal
 {
 
   struct OGRDataSourceDeleter
   {
 
     void CORE_EXPORT operator()( OGRDataSourceH source );
 
   };
 
   struct OGRGeometryDeleter
   {
 
     void CORE_EXPORT operator()( OGRGeometryH geometry );
 
   };
 
   struct OGRFldDeleter
   {
 
     void CORE_EXPORT operator()( OGRFieldDefnH definition );
 
   };
 
   struct OGRFeatureDeleter
   {
 
     void CORE_EXPORT operator()( OGRFeatureH feature );
 
   };
 
   struct GDALDatasetCloser
   {
 
     void CORE_EXPORT operator()( GDALDatasetH datasource );
 
   };
 
   struct GDALWarpOptionsDeleter
   {
 
     void CORE_EXPORT operator()( GDALWarpOptions *options );
 
   };
 
   using ogr_datasource_unique_ptr = std::unique_ptr< std::remove_pointer<OGRDataSourceH>::type, OGRDataSourceDeleter >;
 
   using ogr_geometry_unique_ptr = std::unique_ptr< std::remove_pointer<OGRGeometryH>::type, OGRGeometryDeleter >;
 
   using ogr_field_def_unique_ptr = std::unique_ptr< std::remove_pointer<OGRFieldDefnH>::type, OGRFldDeleter >;
 
   using ogr_feature_unique_ptr = std::unique_ptr< std::remove_pointer<OGRFeatureH>::type, OGRFeatureDeleter >;
 
   using dataset_unique_ptr = std::unique_ptr< std::remove_pointer<GDALDatasetH>::type, GDALDatasetCloser >;
 
   void CORE_EXPORT fast_delete_and_close( dataset_unique_ptr &dataset, GDALDriverH driver, const QString &path );
 
   using warp_options_unique_ptr = std::unique_ptr< GDALWarpOptions, GDALWarpOptionsDeleter >;
 }
 
 class CORE_EXPORT QgsOgrUtils
 {
   public:
 
     static QgsFeature readOgrFeature( OGRFeatureH ogrFet, const QgsFields &fields, QTextCodec *encoding );
 
     static QgsFields readOgrFields( OGRFeatureH ogrFet, QTextCodec *encoding );
 
     static QVariant getOgrFeatureAttribute( OGRFeatureH ogrFet, const QgsFields &fields, int attIndex, QTextCodec *encoding, bool *ok = nullptr );
 
     static bool readOgrFeatureAttributes( OGRFeatureH ogrFet, const QgsFields &fields, QgsFeature &feature, QTextCodec *encoding );
 
     static bool readOgrFeatureGeometry( OGRFeatureH ogrFet, QgsFeature &feature );
 
     static QgsGeometry ogrGeometryToQgsGeometry( OGRGeometryH geom );
 
     static QgsFeatureList stringToFeatureList( const QString &string, const QgsFields &fields, QTextCodec *encoding );
 
     static QgsFields stringToFields( const QString &string, QTextCodec *encoding );
 
     static QStringList cStringListToQStringList( char **stringList );
 
     static QgsWkbTypes::Type ogrGeometryTypeToQgsWkbType( OGRwkbGeometryType ogrGeomType );
 };
 
 #endif // QGSOGRUTILS_H