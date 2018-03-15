/**************************************************************************
 * 头文件名：GeometryType.h                                               *
 * 说明：枚举类型，为GetGeometryType返回值的类型                          *
 **************************************************************************/

enum class GeometryType
{
	OGRGeometry, OGRCurve, OGRGeometryCollection, OGRPoint, OGRSurface, OGRCompoundCurve, OGRSimpleCurve, OGRMultiCurve,
	OGRMultiPoint, OGRMultiSurface, OGRCurvePolygon, OGRCircularString, OGRLineString, OGRMultiLineString, OGRMultiPolygon,
	OGRPolygon, OGRLinearRing
};