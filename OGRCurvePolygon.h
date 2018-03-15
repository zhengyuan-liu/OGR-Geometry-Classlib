#ifndef OGRCURVEPOLYGON_H
#define OGRCURVEPOLYGON_H

#include"OGRSurface.h"

class OGRCurvePolygon :public OGRSurface
{
private:

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRCurvePolygon";
	}

	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRCurvePolygon;
	}

};

#endif