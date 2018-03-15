#ifndef OGRMULTICURVE_H
#define OGRMULTICURVE_H

#include"OGRGeometryCollection.h"
#include"OGRCurve.h"

class OGRMultiCurve :public OGRGeometryCollection
{
private:


public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRMultiCurve";
	}

	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRMultiCurve;
	}

};

#endif