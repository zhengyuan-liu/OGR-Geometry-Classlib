#ifndef OGRMULTICURVE_H
#define OGRMULTICURVE_H

#include"OGRGeometryCollection.h"
#include"OGRCurve.h"

class OGRMultiCurve :public OGRGeometryCollection
{
private:


public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRMultiCurve";
	}

	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRMultiCurve;
	}

};

#endif