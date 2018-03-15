#include"OGRLineString.h"

Rectangle OGRLineString::GetMBR()  //返回最小外包矩形
{
	Rectangle mbr;
	for (unsigned i = 0; i < lines.size(); i++)
	{
		if (i == 0)
			mbr = lines[0].GetMBR();
		else
			mbr = mbr + lines[i].GetMBR();
	}
	return mbr;
}

double OGRLineString::GetLength()  //返回长度
{
	length = 0;
	for (unsigned i = 0; i < lines.size(); i++)
	{
		length += lines[i].GetLength();
	}
	return length;
}