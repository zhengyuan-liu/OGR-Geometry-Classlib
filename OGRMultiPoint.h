#ifndef OGRMULTIPOINT_H
#define OGRMULTIPOINT_H

#include"OGRGeometryCollection.h"
#include"OGRPoint.h"

class OGRMultiPoint :public OGRGeometryCollection
{
private:
	vector<OGRPoint> points;

public:
	OGRMultiPoint() = default;

	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRMultiPoint";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRMultiPoint;
	}

	Rectangle GetMBR() override;  //返回最小外包矩形

	void ImportFromWkt(string path) override;  //WKT转成Point
	void ExportToWkt(string path) override;  //Point转成WKT,返回WKT的string

	void AddGeometry(OGRPoint geo)  //添加geo到末尾
	{
		points.push_back(geo);
	}
	void RemoveGeometry(int index)  //根据索引删除位置为index元素
	{
		auto iter = points.begin() + index;
		points.erase(iter);
	}
	OGRPoint* GetGeometry(int index)  //根据索引查询位置为index的元素,返回指向该元素的指针
	{
		return &points[index];
	}
	void UpdateGeometry(int index, OGRPoint geo)  //根据指定索引更新index位置的元素
	{
		points[index] = geo;
	}
	int GetNumGeometries()  //获取集合中元素的数目
	{
		return points.size();
	}
};

#endif