#ifndef OGRMULTIPOLYGON_H
#define OGRMULTIPOLYGON_H

#include"OGRMultiSurface.h"
#include"OGRPolygon.h"

class OGRMultiPolygon :public OGRMultiSurface
{
private:
	vector<OGRPolygon> polygons;
	double area;  //�����
	double perimeter;  //���ܳ�

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRMultiPolygon";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRMultiPolygon;
	}

	Rectangle GetMBR() override;  //������С�������

	double GetArea();  //���������
	double GetPerimeter();  //�������ܳ�

	void ImportFromWkt(string wkt) override;  //WKTת��MultiPolygon
	void ExportToWkt(string path) override;  //MultiPolygonת��WKT,����WKT��string

	void AddGeometry(OGRPolygon geo)  //���geo��ĩβ
	{
		polygons.push_back(geo);
	}
	void RemoveGeometry(int index)  //��������ɾ��λ��ΪindexԪ��
	{
		auto iter = polygons.begin() + index;
		polygons.erase(iter);
	}
	OGRPolygon* GetGeometry(int index)  //����������ѯλ��Ϊindex��Ԫ��,����ָ���Ԫ�ص�ָ��
	{
		return &polygons[index];
	}
	void UpdateGeometry(int index, OGRPolygon geo)  //����ָ����������indexλ�õ�Ԫ��
	{
		polygons[index] = geo;
	}
	int GetNumGeometries()  //��ȡ������Ԫ�ص���Ŀ
	{
		return polygons.size();
	}
};

#endif