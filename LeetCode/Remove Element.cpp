/*
*��� ������� �������������� ������� � ������ ����� ������� ��� ��������� � ������.
������� ��������� ����� ���� �������.
����� ���������� ���������� ���������, � ������� �� �����. nums val val nums nums val

���������� ���������� ���������, � ������� �� ����� , ����� �������� accepted, ��� ����� ��������� ��������� ��������:nums val k

�������� ������ ����� �������, ����� ������ �������� ��������� ��������, ������� �� ����� .
��������� �������� �� �����, ��� � ������ .nums k nums val nums nums
����������.k


������ 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
���������: ���� ������� ������ ���������� k = 2, ������ ������ ��� �������� nums ����� 2.
�� ����� ��������, ��� �� ���������� �� ��������� ������������� k (�������������, ��� ������� �������������).

������ 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
���������: ���� ������� ������ ���������� k = 5, ������ ������ ���� ��������� nums �������� 0, 0, 1, 3 � 4.
�������� ��������, ��� ���� ��������� ����� ���� ���������� � ����� �������.
�� ����� ��������, ��� �� ���������� �� ��������� ������������� k (�������������, ��� ������� �������������).
  
*/
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution {
public:
    int removeElement(vector<int>& nums, int val);

};


int Solution::removeElement(vector<int>& nums, int val)
{
    auto iter = nums.begin();

    for (int i = 0; i < nums.size();)
    {
        if (nums[i] == val)
        {
            nums.erase(iter + i);
            iter = nums.begin();
            i = 0;
            continue;
        }
        ++i;
    }

    return nums.size();
}

int main()
{
    vector<int> nums{ 0,1,2,2,3,0,4,2 };
    int val = 2;

    Solution a;

    cout << a.removeElement(nums, val) << endl;

    for (int i = 0; i < nums.size(); ++i)
        cout << nums[i];

	return 0;
}

