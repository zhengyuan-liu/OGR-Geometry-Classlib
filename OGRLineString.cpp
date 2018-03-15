#include"OGRLineString.h"

Rectangle OGRLineString::GetMBR()  //������С�������
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

double OGRLineString::GetLength()  //���س���
{
	length = 0;
	for (unsigned i = 0; i < lines.size(); i++)
	{
		length += lines[i].GetLength();
	}
	return length;
}