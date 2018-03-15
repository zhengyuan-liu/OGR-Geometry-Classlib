#ifndef OGRCOMPOUNDCURVE_H
#define OGRCOMPOUNDCURVE_H

#include"OGRCurve.h"

class OGRCompoundCurve :public OGRCurve
{
private:


public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRCompoundCurve";
	}

	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRCompoundCurve;
	}

};

#endif