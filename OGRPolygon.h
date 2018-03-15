#ifndef OGRPOLYGON_H
#define OGRPOLYGON_H

#include"OGRCurvePolygon.h"
#include"OGRLinearRing.h"

class OGRPolygon :public OGRCurvePolygon
{
private:
	vector<OGRPoint> points;
	vector<OGRLinearRing> rings;  //集合类第一个元素（下标索引为0）为最外侧的“环”，如有后续元素，均为第一个元素内部的“环”（表示“岛”或“洞”）
	double area;  //面积
	double perimeter;  //周长

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRPolygon";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRPolygon;
	}

	Rectangle GetMBR() override;  //返回最小外包矩形

	double GetArea() override;  //返回面积
	double GetPerimeter() override;  //返回周长

	void ImportFromWkt(string path) override;  //从path读取WKT,并将WKT转成Polygon
	void ExportToWkt(string path) override;  //Polygon转成WKT,返回WKT的string
	void ImportFromWktString(string path);  //WKT字符串转成Polygon
	string ExportToWktString();  //Polygon转成WKT字符串
};

#endif