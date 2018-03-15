#ifndef OGRCURVE_H
#define OGRCURVE_H

#include"OGRGeometry.h"
#include"LineSegment.h"

class OGRCurve :public OGRGeometry
{
private:


public:
	OGRCurve() = default;  //默认构造函数

	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRCurve";
	}

	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRCurve;
	}

	virtual double GetLength() = 0;  //返回长度
};

#endif