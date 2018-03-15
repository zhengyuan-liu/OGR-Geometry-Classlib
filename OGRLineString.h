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
	OGRLineString() = default;  //Ĭ�Ϲ��캯��

	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRLineString";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRLineString;
	}

	Rectangle GetMBR() override;  //������С�������

	double GetLength() override;  //���س���

};

#endif