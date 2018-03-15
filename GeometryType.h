/**************************************************************************
 * ͷ�ļ�����GeometryType.h                                               *
 * ˵����ö�����ͣ�ΪGetGeometryType����ֵ������                          *
 **************************************************************************/

enum class GeometryType
{
	OGRGeometry, OGRCurve, OGRGeometryCollection, OGRPoint, OGRSurface, OGRCompoundCurve, OGRSimpleCurve, OGRMultiCurve,
	OGRMultiPoint, OGRMultiSurface, OGRCurvePolygon, OGRCircularString, OGRLineString, OGRMultiLineString, OGRMultiPolygon,
	OGRPolygon, OGRLinearRing
};