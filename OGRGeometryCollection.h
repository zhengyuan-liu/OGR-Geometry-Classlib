#ifndef OGRGEOMETRYCOLLECTION_H
#define OGRGEOMETRYCOLLECTION_H

#include"OGRGeometry.h"

class OGRGeometryCollection :public OGRGeometry
{
private:
	vector<OGRGeometry*> geometrys;  //存放指向各元素的指针的向量

public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRGeometryCollection";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRGeometryCollection;
	}

	virtual void AddGeometry(OGRGeometry* geo)  //添加geo到末尾
	{
		geometrys.push_back(geo);
	}
	virtual void RemoveGeometry(int index)  //根据索引删除位置为index元素
	{
		auto iter = geometrys.begin() + index;
		geometrys.erase(iter);
	}
	virtual OGRGeometry* GetGeometry(int index)  //根据索引查询位置为index的元素
	{
		return geometrys[index];
	}
	virtual void UpdateGeometry(int index, OGRGeometry* geo)  //根据指定索引更新index位置的元素
	{
		geometrys[index] = geo;
	}
	virtual int GetNumGeometries()  //获取集合中元素的数目
	{
		return geometrys.size();
	}

};

#endif