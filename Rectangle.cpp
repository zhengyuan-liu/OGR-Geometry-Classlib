#include"Rectangle.h"

Rectangle Rectangle::operator + (const Rectangle &r2)  //重载+，返回两个MBR的和
{
	double xMin, xMax, yMin, yMax;
	xMin = min4(x1, x2, r2.x1, r2.x2);
	xMax = max4(x1, x2, r2.x1, r2.x2);
	yMin = min4(y1, y2, r2.y1, r2.y2);
	yMax = max4(y1, y2, r2.y1, r2.y2);
	Rectangle r(xMin, yMin, xMax, yMax);
	return r;
}



