/*
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
*/


#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

class Accumul
{
public:
	static std::string accum(const std::string& s);
};

std::string Accumul::accum(const std::string& s) {

	//����� �����
	int size = s.length();
	int coun = 1;
	//����� ��� �������
	// A - 65	a - 97
	// Z - 90	z - 122

	std::string  str = "";

	for (int x : s)
	{
		for (int i = 0; i < coun; i++)
		{
			if ( i == 0)
				if (x >= 65 && x <= 90)							/*���� ����� �������*/
				{
				str += static_cast<char>(x);					//���������� ������� �����
				x += 32;										// ������ �� ��� ���������
				continue;
				}
				else                                            /* ���� ����� ��������� */
				{
				x -= 32;										// ������ ������� �����
				str += static_cast<char>(x);
				x += 32;										// ������ �� ���������
				continue;
				}

				if (x >= 65 && x <= 90)							/*���� ���� �������*/
			{
				x += 32;										// ������ ����� ���������
				str += static_cast<char>(x);
				continue;
			}

			str += static_cast<char>(x);
					
		}
		coun++;
		if (coun <= size)
		str += '-';
	}
	return str;
}


/*
	dotest("ZpglnRxqenU", "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
	dotest("NyffsGeyylB", "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
*/

int main()
{

	std::string str {"ZpglnRxqenU"};

	std::cout << Accumul::accum(str) << std::endl;





	return 0;

}