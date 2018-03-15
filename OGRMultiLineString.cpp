#include"OGRMultiLineString.h"

Rectangle OGRMultiLineString::GetMBR()  //返回最小外包矩形
{
	Rectangle mbr;
	for (unsigned i = 0; i < linestrings.size(); i++)
	{
		if (i == 0)
			mbr = linestrings[0].GetMBR();
		else
			mbr = mbr + linestrings[i].GetMBR();
	}
	return mbr;
}

double OGRMultiLineString::GetLength()  //返回总长度
{
	length = 0;
	for (unsigned i = 0; i < linestrings.size(); i++)
	{
		length += linestrings[i].GetLength();
	}
	return length;
}