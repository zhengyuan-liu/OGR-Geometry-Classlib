#ifndef OGRLINEARRING_H
#define OGRLINEARRING_H

#include"OGRLineString.h"

class OGRLinearRing :public OGRLineString
{
private:
	double area;  //��Χ�ɵ����

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRLinearRing";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRLinearRing;
	}

	double GetArea();  //�������

	void FromString(string partialWkt);  //��WKT�ַ�����һ����"x1 y1, x2 y2, ..."ת����LinearRing
	string ToString();  //��LinearRingת����WKT�ַ�����һ����"x1 y1, x2 y2, ..."

	
};

#endif