#ifndef OGRMULTISURFACE_H
#define OGRMULTISURFACE_H

#include"OGRGeometryCollection.h"

class OGRMultiSurface :public OGRGeometryCollection
{
private:


public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRMultiSurface";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRMultiSurface;
	}

};

#endif