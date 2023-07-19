/*
��������, ��� ������ �������������� ������� ������������� � ������� �����������,
������� ��������� ��������� �� ����� ����� �������, ����� ������ ���������� ������� ��������� �� ����� ���� ���.
������������� ������� ��������� ������ ���� �������� �������.

��������� � ��������� ������ �������� ����� ������� ����������,
������ ����� �� ������ ��������� ��������� � ������ ����� ������� nums.
����� ���������, ���� ����� �������� ���������� �������� k ���������,
�� ������ k ��������� nums ������ ��������� �������� ���������.
�� ����� ��������, ��� �� ���������� �� ��������� ������ k ���������.

���������� k ����� ��������� ��������� ���������� � ������ k ����� nums.

�� ��������� �������������� ������������ ��� ������� �������.
�� ������ ������� ���, ������� ������� ������ �� ����� � ������� O(1) �������������� ������


������ 1:
Input: nums = [1, 1, 1, 2, 2, 3]
Output : 5, nums = [1, 1, 2, 2, 3, _]
��������� : ���� ������� ������ ���������� k = 5, ������ ������ ���� ��������� nums ����� 1, 1, 2, 2 � 3 ��������������.
�� ����� ��������, ��� �� ���������� �� ��������� ������������� k(�������������, ��� ������� �������������).

������ 2 :
Input : nums = [0, 0, 1, 1, 1, 1, 2, 3, 3]
Output : 7, nums = [0, 0, 1, 1, 2, 3, 3, _, _]
��������� : ���� ������� ������ ���������� k = 7, ������ ������ ���� ��������� nums �������� 0, 0, 1, 1, 2, 3 � 3 ��������������.
�� ����� ��������, ��� �� ���������� �� ��������� ������������� k(�������������, ��� ������� �������������).
*/

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums);
};


int Solution::removeDuplicates(vector<int>& nums)
{
    int count = 0;  // ���-�� ���
    int j = 1;
    int i = 1;

    int pair{};
    for (; i <= nums.size()- j ;)
    {
        if (nums[i] != nums[i - 1])
        {
            pair = 0;              // ���������� �������
            ++i;
            continue;

        }
        ++pair;

        if (pair > 1)
        {
            int temp{ nums[i] };
            int size = nums.size() - i;
            for (int k = 0; k < size - 1; ++k)
                nums[i + k] = nums[i + k + 1];

            nums[nums.size()-1] = temp;
            j++;
            continue;
        }

        ++i;
    }

   
    cout << i << endl;
        for (int x : nums)
            cout << x << " ";
        cout << endl;
        cout << pair << endl;


      //  if (nums.size() < 2)
        //    return i;

       // if (pair >= 1 && nums.size() <= 3)
         //   return i;

        return i;
}





int main() {

    vector<int> nums{ 1,1,1};
    Solution x;

   cout << "EEEEE: " << x.removeDuplicates(nums);



    return 0;
}