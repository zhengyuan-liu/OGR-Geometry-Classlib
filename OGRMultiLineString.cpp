#include"OGRMultiLineString.h"

Rectangle OGRMultiLineString::GetMBR()  //������С�������
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

double OGRMultiLineString::GetLength()  //�����ܳ���
{
	length = 0;
	for (unsigned i = 0; i < linestrings.size(); i++)
	{
		length += linestrings[i].GetLength();
	}
	return length;
}