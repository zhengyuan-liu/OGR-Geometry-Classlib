#ifndef OGRCOMPOUNDCURVE_H
#define OGRCOMPOUNDCURVE_H

#include"OGRCurve.h"

class OGRCompoundCurve :public OGRCurve
{
private:


public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRCompoundCurve";
	}

	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRCompoundCurve;
	}

};

#endif