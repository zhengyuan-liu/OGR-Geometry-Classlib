#ifndef OGRLINESTRING_H
#define OGRLINESTRING_H

#include"OGRSimpleCurve.h"
#include"OGRPoint.h"

class OGRLineString :public OGRSimpleCurve
{
protected:
	vector<OGRPoint> points;
	vector<LineSegment> lines;
	int PointNum;
	int LineNum;
	double length;

public:
	OGRLineString() = default;  //默认构造函数

	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRLineString";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRLineString;
	}

	Rectangle GetMBR() override;  //返回最小外包矩形

	double GetLength() override;  //返回长度

};

#endif