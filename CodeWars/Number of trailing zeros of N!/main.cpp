/*
�������� ���������, ������� ����� ��������� ���������� �������� ����� � ���������� ��������� �����.
N! = 1 * 2 * 3 *  ... * N
������ ��������� � 2568 �������... .1000!

�������������� �������� ��. � �������: http://mathworld.wolfram.com/Factorial.html


�������
zeros(6) = 1
# 6! = 1 * 2 * 3 * 4 * 5 * 6 = 720 --> 1 trailing zero

zeros(12) = 2
# 12! = 479001600 --> 2 trailing zeros


���������: �� �� ������ ��������� ���������. ������� ������ ������ ����� ���������� �����.

Test
		Assert::That(zeros(0), Equals(0));
		Assert::That(zeros(6), Equals(1));
		Assert::That(zeros(30), Equals(7));
		Assert::That(zeros(100), Equals(24));
		Assert::That(zeros(1000), Equals(249));
		Assert::That(zeros(100000), Equals(24999));
		Assert::That(zeros(1000000000), Equals(249999998));

*/


#include <iostream>


long zeros(long n) {

	int count = 0;

	while (n > 1)
	{
		n /= 5;
		count += n;
	}

	return count;
}

int main()
{
	zeros(1000000000);
	return 0;
}