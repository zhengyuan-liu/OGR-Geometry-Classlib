#ifndef OGRCURVEPOLYGON_H
#define OGRCURVEPOLYGON_H

#include"OGRSurface.h"

class OGRCurvePolygon :public OGRSurface
{
private:

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRCurvePolygon";
	}

	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRCurvePolygon;
	}

};

#endif