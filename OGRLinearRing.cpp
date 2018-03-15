#include"OGRLinearRing.h"

double OGRLinearRing::GetArea()  //�������
{	
	area = 0;
	for (unsigned i = 0; i < lines.size() - 1; i++)
	{
		area += 0.5*(points[i].GetY() + points[i + 1].GetY())*(points[i + 1].GetX() - points[i].GetX());
	}
	area += 0.5*(points[0].GetY() + points[lines.size() - 1].GetY())*(points[0].GetX() - points[lines.size() - 1].GetX());
	if (area < 0)
		area *= -1;
	return area;
}

void OGRLinearRing::FromString(string partialWkt)  //��WKT�ַ�����һ����"(x1 y1, x2 y2, ...)"ת����LinearRing
{
	double x, y;
	points.clear();  //�����������
	for (unsigned i = 0; i < partialWkt.size(); i++)
	{
		string strPoint = "";
		while (partialWkt[++i] != ',')
		{
			if (partialWkt[i] == ')')
				break;
			strPoint.push_back(partialWkt[i]);
		}
		stringstream ss(strPoint);
		ss >> x >> y;
		OGRPoint p(x, y);
		points.push_back(p);
	}

	//�����߶�
	lines.clear();
	for (unsigned i = 1; i < points.size(); i++)
	{
		LineSegment l(points[i - 1], points[i]);
		lines.push_back(l);
	}
	//�պ�
	LineSegment l(points[points.size() - 1], points[0]);
	lines.push_back(l);
}

string OGRLinearRing::ToString()  //��LinearRingת����WKT�ַ�����һ����"(x1 y1, x2 y2, ...)"
{
	string partialWkt = "(";
	stringstream ss;
	for (unsigned i = 0; i < points.size(); i++)
	{
		if (i == 0)
			ss << points[i].GetX() << " " << points[i].GetY();
		else
			ss << ", " << points[i].GetX() << " " << points[i].GetY();
	}
	partialWkt += ss.str() + ")";
	return partialWkt;
}