#ifndef OGRCIRCULARSTRING_H
#define OGRCIRCULARSTRING_H

#include"OGRSimpleCurve.h"

class OGRCircularString :public OGRSimpleCurve
{
private:


public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRCircularString";
	}

	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRCircularString;
	}

};

#endif