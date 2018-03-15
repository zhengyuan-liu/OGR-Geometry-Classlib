#ifndef OGRMULTILINESTRING_H
#define OGRMULTILINESTRING_H

#include"OGRMultiCurve.h"
#include"OGRLineString.h"

class OGRMultiLineString :public OGRMultiCurve
{
private:
	vector<OGRLineString> linestrings;
	double length;

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRMultiLineString";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRMultiLineString;
	}

	Rectangle GetMBR() override;  //返回最小外包矩形

	double GetLength();  //返回总长度

	void AddGeometry(OGRLineString geo)  //添加geo到末尾
	{
		linestrings.push_back(geo);
	}
	void RemoveGeometry(int index)  //根据索引删除位置为index元素
	{
		auto iter = linestrings.begin() + index;
		linestrings.erase(iter);
	}
	OGRLineString* GetGeometry(int index)  //根据索引查询位置为index的元素,返回指向该元素的指针
	{
		return &linestrings[index];
	}
	void UpdateGeometry(int index, OGRLineString geo)  //根据指定索引更新index位置的元素
	{
		linestrings[index] = geo;
	}
	int GetNumGeometries()  //获取集合中元素的数目
	{
		return linestrings.size();
	}
};

#endif