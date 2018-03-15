#ifndef OGRMULTILINESTRING_H
#define OGRMULTILINESTRING_H

#include"OGRMultiCurve.h"
#include"OGRLineString.h"

class OGRMultiLineString :public OGRMultiCurve
{
private:
	vector<OGRLineString> linestrings;
	double length;

public:
	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRMultiLineString";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRMultiLineString;
	}

	Rectangle GetMBR() override;  //������С�������

	double GetLength();  //�����ܳ���

	void AddGeometry(OGRLineString geo)  //���geo��ĩβ
	{
		linestrings.push_back(geo);
	}
	void RemoveGeometry(int index)  //��������ɾ��λ��ΪindexԪ��
	{
		auto iter = linestrings.begin() + index;
		linestrings.erase(iter);
	}
	OGRLineString* GetGeometry(int index)  //����������ѯλ��Ϊindex��Ԫ��,����ָ���Ԫ�ص�ָ��
	{
		return &linestrings[index];
	}
	void UpdateGeometry(int index, OGRLineString geo)  //����ָ����������indexλ�õ�Ԫ��
	{
		linestrings[index] = geo;
	}
	int GetNumGeometries()  //��ȡ������Ԫ�ص���Ŀ
	{
		return linestrings.size();
	}
};

#endif