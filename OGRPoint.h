#ifndef OGRPOINT_H
#define OGRPOINT_H

#include"OGRGeometry.h"

class OGRPoint :public OGRGeometry
{
private:
	double x;
	double y;

public:
	OGRPoint() = default;  //默认构造函数
	OGRPoint(double x0, double y0) :x(x0), y(y0){ }  //构造函数

	char* GetGeometryTypeString() override  //返回类型字符串
	{
		return "OGRPoint";
	}
	GeometryType GetGeometryType() override //获取类型
	{
		return GeometryType::OGRPoint;
	}

	Rectangle GetMBR() override  //返回最小外包矩形
	{
		Rectangle MBR(x, y, x, y);
		return MBR;
	}

	void ImportFromWkt(string path) override  //从path读取WKT,并将WKT转成Point
	{
		ifstream ifs(path);
		string wkt;
		getline(ifs, wkt);
		string s = wkt.substr(7, wkt.size() - 8);
		stringstream ss(s);
		ss >> x >> y;
	}
	void ExportToWkt(string path) override  //Point转成WKT,返回WKT的string
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