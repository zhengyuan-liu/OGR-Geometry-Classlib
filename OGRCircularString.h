#ifndef OGRCIRCULARSTRING_H
#define OGRCIRCULARSTRING_H

#include"OGRSimpleCurve.h"

class OGRCircularString :public OGRSimpleCurve
{
private:


public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRCircularString";
	}

	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRCircularString;
	}

};

#endif