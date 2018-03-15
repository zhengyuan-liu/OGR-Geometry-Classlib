#ifndef OGRPOLYGON_H
#define OGRPOLYGON_H

#include"OGRCurvePolygon.h"
#include"OGRLinearRing.h"

class OGRPolygon :public OGRCurvePolygon
{
private:
	vector<OGRPoint> points;
	vector<OGRLinearRing> rings;  //�������һ��Ԫ�أ��±�����Ϊ0��Ϊ�����ġ����������к���Ԫ�أ���Ϊ��һ��Ԫ���ڲ��ġ���������ʾ�������򡰶�����
	double area;  //���
	double perimeter;  //�ܳ�

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRPolygon";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRPolygon;
	}

	Rectangle GetMBR() override;  //������С�������

	double GetArea() override;  //�������
	double GetPerimeter() override;  //�����ܳ�

	void ImportFromWkt(string path) override;  //��path��ȡWKT,����WKTת��Polygon
	void ExportToWkt(string path) override;  //Polygonת��WKT,����WKT��string
	void ImportFromWktString(string path);  //WKT�ַ���ת��Polygon
	string ExportToWktString();  //Polygonת��WKT�ַ���
};

#endif