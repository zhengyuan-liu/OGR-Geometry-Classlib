#include"OGRMultiPolygon.h"

Rectangle OGRMultiPolygon::GetMBR()  //返回最小外包矩形
{
	Rectangle mbr;
	for (unsigned i = 0; i < polygons.size(); i++)
	{
		if (i == 0)
			mbr = polygons[0].GetMBR();
		else
			mbr = mbr + polygons[i].GetMBR();
	}
	return mbr;
}

double OGRMultiPolygon::GetArea()  //返回总面积
{
	area = 0;
	for (unsigned i = 0; i < polygons.size(); i++)
		area += polygons[i].GetArea();
	return area;
}

double OGRMultiPolygon::GetPerimeter()  //返回总周长
{
	perimeter = 0;
	for (unsigned i = 0; i < polygons.size(); i++)
		perimeter += polygons[i].GetPerimeter();
	return perimeter;
}

void OGRMultiPolygon::ImportFromWkt(string path)  //WKT转成MultiPolygon
{
	ifstream ifs(path);
	string wkt;
	getline(ifs, wkt);
	string s = wkt.substr(14, wkt.size() - 15);
	polygons.clear();  //清空所有多边形
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' && s[i + 1] == '(')
		{
			string sub = "";
			for (; i < s.size(); i++)
			{
				sub.push_back(s[i]);
				if (s[i] == ')' && s[i - 1] == ')')
					break;
			}
			string wktPolygon = "Polygon " + sub;
			OGRPolygon polygon;
			polygon.ImportFromWktString(wktPolygon);
			polygons.push_back(polygon);
		}
	}
}

void OGRMultiPolygon::ExportToWkt(string path)  //MultiPolygon转成WKT,返回WKT的string
{
	string wkt = "MultiPolygon (";
	stringstream ss;
	for (unsigned i = 0; i < polygons.size(); i++)
	{
		string s = polygons[i].ExportToWktString();
		string sub = s.substr(8);
		if (i == 0)
			wkt += sub;
		else
			wkt+= ", " +sub;
	}
	wkt += ")";
	ofstream ofs(path);
	ofs << wkt;
}