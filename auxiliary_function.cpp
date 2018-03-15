/***************************************************************************
 * 文件名：auxiliary_function.cpp                                          *
 * 功能：存放辅助函数的定义                                                *
 ***************************************************************************/

#include"auxiliary_function.h"

double max2(double a, double b)  //返回2个数的最大值
{
	if (a > b)
		return a;
	else
		return b;
}

double max4(double a, double b, double c, double d)  //返回4个数的最大值
{
	a = max2(a, b);
	a = max2(a, c);
	a = max2(a, d);
	return a;
}

double min2(double a, double b)  //返回2个数的最小值
{
	if (a < b)
		return a;
	else
		return b;
}

double min4(double a, double b, double c, double d)  //返回4个数的最小值
{
	a = min2(a, b);
	a = min2(a, c);
	a = min2(a, d);
	return a;
}