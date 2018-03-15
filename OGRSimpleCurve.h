#ifndef OGRSIMPLECURVE_H
#define OGRSIMPLECURVE_H

#include"OGRCurve.h"

class OGRSimpleCurve :public OGRCurve
{
private:


public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRSimpleCurve";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRSimpleCurve;
	}

};

#endif