#include"OGRMultiPoint.h"

Rectangle OGRMultiPoint::GetMBR()  //������С�������
{
	Rectangle mbr;
	for (unsigned i = 0; i < points.size(); i++)
	{
		if (i == 0)
			mbr = points[0].GetMBR();
		else
			mbr = mbr + points[i].GetMBR();
	}
	return mbr;
}

void OGRMultiPoint::ImportFromWkt(string path)  //WKTת��Point
{
	ifstream ifs(path);
	string wkt;
	getline(ifs, wkt);
	string s = wkt.substr(12, wkt.size() - 13);
	double x, y;
	points.clear();  //�����������
	for (unsigned i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			string strPoint = "";
			while (s[++i] != ')')
				strPoint.push_back(s[i]);
			stringstream ss(strPoint);
			ss >> x >> y;
			OGRPoint p(x, y);
			points.push_back(p);
		}
	}
}
void OGRMultiPoint::ExportToWkt(string path)  //LineStringת��WKT,����WKT��string
{
	string wkt = "MultiPoint (";
	stringstream ss;
	for (unsigned i = 0; i < points.size(); i++)
	{
		if (i == 0)
			ss << "(" << points[i].GetX() << " " << points[i].GetY() << ")";
		else
			ss << ", (" << points[i].GetX() << " " << points[i].GetY() << ")";
	}
	wkt += ss.str()+")";
	ofstream ofs(path);
	ofs << wkt;
}