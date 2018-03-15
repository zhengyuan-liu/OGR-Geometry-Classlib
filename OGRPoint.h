#ifndef OGRPOINT_H
#define OGRPOINT_H

#include"OGRGeometry.h"

class OGRPoint :public OGRGeometry
{
private:
	double x;
	double y;

public:
	OGRPoint() = default;  //Ĭ�Ϲ��캯��
	OGRPoint(double x0, double y0) :x(x0), y(y0){ }  //���캯��

	char* GetGeometryTypeString() override  //���������ַ���
	{
		return "OGRPoint";
	}
	GeometryType GetGeometryType() override //��ȡ����
	{
		return GeometryType::OGRPoint;
	}

	Rectangle GetMBR() override  //������С�������
	{
		Rectangle MBR(x, y, x, y);
		return MBR;
	}

	void ImportFromWkt(string path) override  //��path��ȡWKT,����WKTת��Point
	{
		ifstream ifs(path);
		string wkt;
		getline(ifs, wkt);
		string s = wkt.substr(7, wkt.size() - 8);
		stringstream ss(s);
		ss >> x >> y;
	}
	void ExportToWkt(string path) override  //Pointת��WKT,����WKT��string
	{
		ofstream ofs(path);
		stringstream ss;
		ss <<"Point ("<< x << " " << y << ")";
		ofs << ss.str();
	}

	double GetX(){ return x; }
	double GetY(){ return y; }
};

#endif