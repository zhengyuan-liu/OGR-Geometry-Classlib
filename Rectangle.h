/**************************************************************************
 * 头文件名：Rectangle.h                                                  *
 * 说明：为GetMBR返回值的类型                                             *
 **************************************************************************/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"auxiliary_function.h"

class Rectangle
{
private:
	double x1, y1, x2, y2;

public:
	Rectangle() = default;
	Rectangle(double a1, double b1, double a2, double b2) :x1(a1), y1(b1), x2(a2), y2(b2){ }

	Rectangle operator+(const Rectangle &);  //重载+，返回两个MBR的和

	double GetX1(){ return x1; }
	double GetY1(){ return y1; }
	double GetX2(){ return x2; }
	double GetY2(){ return y2; }

};


#endif