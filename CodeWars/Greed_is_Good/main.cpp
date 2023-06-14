/*

  Throw       Score
 ---------   ------------------
 5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
 1 1 1 3 1   1100: 1000 (for three 1s) + 100 (for the other 1)
 2 4 4 5 4   450:  400 (for three 4s) + 50 (for the 5)

*/


#include <iostream>
#include <vector>

int score(const std::vector<int>& dice)
{
	int count1 = 0, count2 = 0;
	int count3 = 0, count4 = 0;
	int count5 = 0, count6 = 0;
	int score = 0;

	for (int i : dice)
		switch (i)
		{
		case 1:
			count1++;
			break;
		case 2:
			count2++;
			break;
		case 3:
			count3++;
			break;
		case 4:
			count4++;
			break;
		case 5:
			count5++;
			break;
		case 6:
			count6++;
			break;
		}


	//��� ������� => 1000 �����
	if (count1 >= 3)
	{
		score += 1000;
		count1 -= 3;
	}
	//��� �������� => 600 �����
	if (count6 >= 3)
	{
		score += 600;
		count6 -= 3;
	}
	//��� ������� => 500 ������
	if (count5 >= 3)
	{
		score += 500;
		count5 -= 3;
	}
	//��� �������� => 400 ������
	if (count4 >= 3)
	{
		score += 400;
		count4 -= 3;
	}
	//��� ������ => 300 �����
	if (count3 >= 3)
	{
		score += 300;
		count3 -= 3;
	}
	//��� ������ => 200 �����
	if (count2 >= 3)
	{
		score += 200;
		count2 -= 3;
	}
	
	while (count1 > 0 || count5 > 0)
	{
		//���� 1 => 100 ������
		//���� ������� => 50 ������	
		if (count1 > 0)
		{
			score += 100;
			count1 -= 1;
		}

		if (count5 > 0)
		{
			score += 50;
			count5 -= 1;
		}

	}

	return score; // your code here
}

int main()
{
	/*
	5 1 3 4 1   250:  50 (for the 5) + 2 * 100 (for the 1s)
	1 1 1 3 1   1100 : 1000 (for three 1s) + 100 (for the other 1)
	2 4 4 5 4   450 : 400 (for three 4s) + 50 (for the 5)
	*/
	
	std::vector<int> dice{ 2,4,4,5,4 };

	std::cout << score(dice) << std::endl;

	return 0;
}
