#include"OGRPolygon.h"

Rectangle OGRPolygon::GetMBR()  //������С�������
{
	return rings[0].GetMBR();
}

double OGRPolygon::GetPerimeter()  //�����ܳ�
{
	perimeter = 0;
	for (unsigned i = 0; i < rings.size(); i++)
		perimeter += rings[i].GetLength();
	return perimeter;
}

double OGRPolygon::GetArea()  //�������
{
	area = rings[0].GetArea();
	//cout << rings.size() << endl;
	for (unsigned i = 1; i < rings.size(); i++)
		area -= rings[i].GetArea();	
	return area;
}

void OGRPolygon::ImportFromWkt(string path)  //��path��ȡWKT,����WKTת��Polygon
{
	ifstream ifs(path);
	string wkt;
	getline(ifs, wkt);
	string s = wkt.substr(9, wkt.size() - 10);
	points.clear();  //�����������
	rings.clear();  //��յ�
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

void OGRPolygon::ExportToWkt(string path)  //Polygonת��WKT,������WKT��path
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

void OGRPolygon::ImportFromWktString(string wkt)  //WKT�ַ���ת��Polygon
{
	string s = wkt.substr(9, wkt.size() - 10);
	points.clear();  //�����������
	rings.clear();  //��յ�
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

string OGRPolygon::ExportToWktString()  //Polygonת��WKT�ַ���
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