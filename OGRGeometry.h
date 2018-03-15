#ifndef OGRGEOMETRY_H
#define OGRGEOMETRY_H

#include"Rectangle.h"
#include"GeometryType.h"
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

class OGRGeometry
{
private:
	static int count;  //ͳ��Ԫ������
	int id;

public:
	OGRGeometry()  //���캯��
	{
		count++;
		id = count;
	}

	virtual char* GetGeometryTypeString()  //��ȡ�����ַ���
	{
		return "OGRGeometry";
	}

	virtual GeometryType GetGeometryType()  //��ȡ����
	{
		return GeometryType::OGRGeometry;
	}

	virtual Rectangle GetMBR() = 0;  //������С�������
	//{
	//	Rectangle MBR(0,0,0,0);
	//	return MBR;
	//}

	virtual void Copy(OGRGeometry& Object)  //����
	{
		*this = Object;
	}

	int GetID()  //����ID
	{
		return id;
	}

	virtual void ImportFromWkt(string path){ }  //WKTת��Geometry
	virtual void ExportToWkt(string path){ }  //Geometryת��WKT,����WKT��string

};

#endif