#ifndef OGRSURFACE_H
#define OGRSURFACE_H

#include"OGRGeometry.h"

class OGRSurface :public OGRGeometry
{
private:

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRSurface";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRSurface;
	}

	virtual double GetArea() = 0;  //返回面积
	virtual double GetPerimeter() = 0;  //返回周长
};

#endif