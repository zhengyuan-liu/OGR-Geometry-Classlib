/***************************************************************************
 * �ļ�����auxiliary_function.cpp                                          *
 * ���ܣ���Ÿ��������Ķ���                                                *
 ***************************************************************************/

#include"auxiliary_function.h"

double max2(double a, double b)  //����2���������ֵ
{
	if (a > b)
		return a;
	else
		return b;
}

double max4(double a, double b, double c, double d)  //����4���������ֵ
{
	a = max2(a, b);
	a = max2(a, c);
	a = max2(a, d);
	return a;
}

double min2(double a, double b)  //����2��������Сֵ
{
	if (a < b)
		return a;
	else
		return b;
}

double min4(double a, double b, double c, double d)  //����4��������Сֵ
{
	a = min2(a, b);
	a = min2(a, c);
	a = min2(a, d);
	return a;
}