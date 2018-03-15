#ifndef OGRSURFACE_H
#define OGRSURFACE_H

#include"OGRGeometry.h"

class OGRSurface :public OGRGeometry
{
private:

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRSurface";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRSurface;
	}

	virtual double GetArea() = 0;  //�������
	virtual double GetPerimeter() = 0;  //�����ܳ�
};

#endif