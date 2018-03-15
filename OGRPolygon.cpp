#include"OGRPolygon.h"

Rectangle OGRPolygon::GetMBR()  //返回最小外包矩形
{
	return rings[0].GetMBR();
}

double OGRPolygon::GetPerimeter()  //返回周长
{
	perimeter = 0;
	for (unsigned i = 0; i < rings.size(); i++)
		perimeter += rings[i].GetLength();
	return perimeter;
}

double OGRPolygon::GetArea()  //返回面积
{
	area = rings[0].GetArea();
	//cout << rings.size() << endl;
	for (unsigned i = 1; i < rings.size(); i++)
		area -= rings[i].GetArea();	
	return area;
}

void OGRPolygon::ImportFromWkt(string path)  //从path读取WKT,并将WKT转成Polygon
{
	ifstream ifs(path);
	string wkt;
	getline(ifs, wkt);
	string s = wkt.substr(9, wkt.size() - 10);
	points.clear();  //清空所有坐标
	rings.clear();  //清空岛
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			string sub = "";
			for (; i < s.size(); i++)
			{
				sub.push_back(s[i]);
				if (s[i] == ')')
					break;
			}
			OGRLinearRing ring;
			ring.FromString(sub);
			rings.push_back(ring);
		}
	}
}

void OGRPolygon::ExportToWkt(string path)  //Polygon转成WKT,并输入WKT到path
{
	ofstream ofs(path);
	string wkt = "Polygon (";
	wkt += rings[0].ToString();
	for (unsigned i = 1; i < rings.size(); i++)
	{
		wkt += ", " + rings[i].ToString();
	}
	wkt += ")";
	ofs << wkt;
}

void OGRPolygon::ImportFromWktString(string wkt)  //WKT字符串转成Polygon
{
	string s = wkt.substr(9, wkt.size() - 10);
	points.clear();  //清空所有坐标
	rings.clear();  //清空岛
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			string sub = "";
			for (; i < s.size(); i++)
			{
				sub.push_back(s[i]);
				if (s[i] == ')')
					break;
			}
			OGRLinearRing ring;
			ring.FromString(sub);
			rings.push_back(ring);
		}
	}
}

string OGRPolygon::ExportToWktString()  //Polygon转成WKT字符串
{
	string wkt = "Polygon (";
	wkt += rings[0].ToString();
	for (unsigned i = 1; i < rings.size(); i++)
	{
		wkt += ", " + rings[i].ToString();
	}
	wkt += ")";
	return wkt;
}