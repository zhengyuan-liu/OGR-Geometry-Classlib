#ifndef OGRGEOMETRY_H
#define OGRGEOMETRY_H

#include"Rectangle.h"
#include"GeometryType.h"
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class OGRGeometry
{
private:
	static int count;  //统计元素数量
	int id;

public:
	OGRGeometry()  //构造函数
	{
		count++;
		id = count;
	}

	virtual char* GetGeometryTypeString()  //获取类型字符串
	{
		return "OGRGeometry";
	}

	virtual GeometryType GetGeometryType()  //获取类型
	{
		return GeometryType::OGRGeometry;
	}

	virtual Rectangle GetMBR() = 0;  //返回最小外包矩形
	//{
	//	Rectangle MBR(0,0,0,0);
	//	return MBR;
	//}

	virtual void Copy(OGRGeometry& Object)  //复制
	{
		*this = Object;
	}

	int GetID()  //返回ID
	{
		return id;
	}

	virtual void ImportFromWkt(string path){ }  //WKT转成Geometry
	virtual void ExportToWkt(string path){ }  //Geometry转成WKT,返回WKT的string

};

#endif