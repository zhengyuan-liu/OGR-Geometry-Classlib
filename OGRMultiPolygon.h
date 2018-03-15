#ifndef OGRMULTIPOLYGON_H
#define OGRMULTIPOLYGON_H

#include"OGRMultiSurface.h"
#include"OGRPolygon.h"

class OGRMultiPolygon :public OGRMultiSurface
{
private:
	vector<OGRPolygon> polygons;
	double area;  //总面积
	double perimeter;  //总周长

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRMultiPolygon";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRMultiPolygon;
	}

	Rectangle GetMBR() override;  //返回最小外包矩形

	double GetArea();  //返回总面积
	double GetPerimeter();  //返回总周长

	void ImportFromWkt(string wkt) override;  //WKT转成MultiPolygon
	void ExportToWkt(string path) override;  //MultiPolygon转成WKT,返回WKT的string

	void AddGeometry(OGRPolygon geo)  //添加geo到末尾
	{
		polygons.push_back(geo);
	}
	void RemoveGeometry(int index)  //根据索引删除位置为index元素
	{
		auto iter = polygons.begin() + index;
		polygons.erase(iter);
	}
	OGRPolygon* GetGeometry(int index)  //根据索引查询位置为index的元素,返回指向该元素的指针
	{
		return &polygons[index];
	}
	void UpdateGeometry(int index, OGRPolygon geo)  //根据指定索引更新index位置的元素
	{
		polygons[index] = geo;
	}
	int GetNumGeometries()  //获取集合中元素的数目
	{
		return polygons.size();
	}
};

#endif