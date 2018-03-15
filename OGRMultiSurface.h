#ifndef OGRMULTISURFACE_H
#define OGRMULTISURFACE_H

#include"OGRGeometryCollection.h"

class OGRMultiSurface :public OGRGeometryCollection
{
private:


public:
	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRMultiSurface";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRMultiSurface;
	}

};

#endif