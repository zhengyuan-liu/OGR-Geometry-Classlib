#ifndef OGRCURVE_H
#define OGRCURVE_H

#include"OGRGeometry.h"
#include"LineSegment.h"

class OGRCurve :public OGRGeometry
{
private:


public:
	OGRCurve() = default;  //Ĭ�Ϲ��캯��

	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRCurve";
	}

	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRCurve;
	}

	virtual double GetLength() = 0;  //���س���
};

#endif