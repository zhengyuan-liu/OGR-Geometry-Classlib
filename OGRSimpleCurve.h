#ifndef OGRSIMPLECURVE_H
#define OGRSIMPLECURVE_H

#include"OGRCurve.h"

class OGRSimpleCurve :public OGRCurve
{
private:


public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRSimpleCurve";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRSimpleCurve;
	}

};

#endif