#ifndef OGRLINEARRING_H
#define OGRLINEARRING_H

#include"OGRLineString.h"

class OGRLinearRing :public OGRLineString
{
private:
	double area;  //环围成的面积

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRLinearRing";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRLinearRing;
	}

	double GetArea();  //返回面积

	void FromString(string partialWkt);  //将WKT字符串的一部分"x1 y1, x2 y2, ..."转换成LinearRing
	string ToString();  //将LinearRing转换成WKT字符串的一部分"x1 y1, x2 y2, ..."

	
};

#endif