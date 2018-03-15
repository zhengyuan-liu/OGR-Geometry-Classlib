/**************************************************************************
 * ͷ�ļ�����LineSegment.h                                                *
 * ˵����Ϊ�����࣬�����㹹�ɵ��߶Σ�ΪLineString�Ļ���Ԫ��               *
 **************************************************************************/

#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include"OGRPoint.h"

class LineSegment
{
private:
	double x1, y1;  //�������
	double x2, y2;  //�յ�����
	double length;  //����

public:
	LineSegment() = default;  //Ĭ�Ϲ��캯��
	LineSegment(double a1, double b1, double a2, double b2) :x1(a1), y1(b1), x2(a2), y2(b2)  //����4������ֵ�Ĺ��캯��
	{
		length = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}
	LineSegment(OGRPoint p1, OGRPoint p2) :x1(p1.GetX()), y1(p1.GetY()), x2(p2.GetX()), y2(p2.GetY())  //����2����Ĺ��캯��
	{
		length = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}

	double GetLength()  //���س���
	{
		return length;
	}

	Rectangle GetMBR()  //������С�������
	{
		Rectangle MBR(x1, y1, x2, y2);
		return MBR;
	}
};

#endif