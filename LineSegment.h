/**************************************************************************
 * 头文件名：LineSegment.h                                                *
 * 说明：为辅助类，两个点构成的线段，为LineString的基本元素               *
 **************************************************************************/

#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include"OGRPoint.h"

class LineSegment
{
private:
	double x1, y1;  //起点坐标
	double x2, y2;  //终点坐标
	double length;  //长度

public:
	LineSegment() = default;  //默认构造函数
	LineSegment(double a1, double b1, double a2, double b2) :x1(a1), y1(b1), x2(a2), y2(b2)  //基于4个坐标值的构造函数
	{
		length = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}
	LineSegment(OGRPoint p1, OGRPoint p2) :x1(p1.GetX()), y1(p1.GetY()), x2(p2.GetX()), y2(p2.GetY())  //基于2个点的构造函数
	{
		length = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	}

	double GetLength()  //返回长度
	{
		return length;
	}

	Rectangle GetMBR()  //返回最小外包矩形
	{
		Rectangle MBR(x1, y1, x2, y2);
		return MBR;
	}
};

#endif