#ifndef OGRGEOMETRYCOLLECTION_H
#define OGRGEOMETRYCOLLECTION_H

#include"OGRGeometry.h"

class OGRGeometryCollection :public OGRGeometry
{
private:
	vector<OGRGeometry*> geometrys;  //���ָ���Ԫ�ص�ָ�������

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRGeometryCollection";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRGeometryCollection;
	}

	virtual void AddGeometry(OGRGeometry* geo)  //���geo��ĩβ
	{
		geometrys.push_back(geo);
	}
	virtual void RemoveGeometry(int index)  //��������ɾ��λ��ΪindexԪ��
	{
		auto iter = geometrys.begin() + index;
		geometrys.erase(iter);
	}
	virtual OGRGeometry* GetGeometry(int index)  //����������ѯλ��Ϊindex��Ԫ��
	{
		return geometrys[index];
	}
	virtual void UpdateGeometry(int index, OGRGeometry* geo)  //����ָ����������indexλ�õ�Ԫ��
	{
		geometrys[index] = geo;
	}
	virtual int GetNumGeometries()  //��ȡ������Ԫ�ص���Ŀ
	{
		return geometrys.size();
	}

};

#endif