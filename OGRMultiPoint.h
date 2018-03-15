#ifndef OGRMULTIPOINT_H
#define OGRMULTIPOINT_H

#include"OGRGeometryCollection.h"
#include"OGRPoint.h"

class OGRMultiPoint :public OGRGeometryCollection
{
private:
	vector<OGRPoint> points;

public:
	OGRMultiPoint() = default;

	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRMultiPoint";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRMultiPoint;
	}

	Rectangle GetMBR() override;  //������С�������

	void ImportFromWkt(string path) override;  //WKTת��Point
	void ExportToWkt(string path) override;  //Pointת��WKT,����WKT��string

	void AddGeometry(OGRPoint geo)  //���geo��ĩβ
	{
		points.push_back(geo);
	}
	void RemoveGeometry(int index)  //��������ɾ��λ��ΪindexԪ��
	{
		auto iter = points.begin() + index;
		points.erase(iter);
	}
	OGRPoint* GetGeometry(int index)  //����������ѯλ��Ϊindex��Ԫ��,����ָ���Ԫ�ص�ָ��
	{
		return &points[index];
	}
	void UpdateGeometry(int index, OGRPoint geo)  //����ָ����������indexλ�õ�Ԫ��
	{
		points[index] = geo;
	}
	int GetNumGeometries()  //��ȡ������Ԫ�ص���Ŀ
	{
		return points.size();
	}
};

#endif