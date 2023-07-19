/*

��� ������ ��� ������������� ������� , ��������������� � ������� �����������, � ��� ����� ����� , �������������� ���������� ��������� � ��� ��������������.nums1 nums2 m n nums1 nums2

���������� � ������ ������, ��������������� � ������� �����������. nums1 nums2

�������� ��������������� ������ �� ������ ������������ ��������, � ������ ����� ��������� ������ �������.
����� ������ ���, ����� ����� , ��� ������ �������� ���������� ��������, ������� ������ ���� ����������, � ��������� �������� ����� �������� � ������ ��������������.
����� �����: nums1 nums1 m + n m n 0 nums2 n
*/

/*

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

*/

/*
����������� �����������:

0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
*/
#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


//nums1.length == m + n
//nums2.length == n

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // ����� ��������� � nums1
        if (n == 0) return;


        if (m == 0)
        {
            int i = 0;
            nums1.resize(m + n);
            for (auto x : nums2)
                nums1[i++] = x;

            return;
        }


        int i{};

        if (nums1.capacity() < m + n)
            nums1.resize(m + n);

        auto iter2 = nums2.begin();

        for (; iter2 < nums2.end(); iter2++)
        {
            nums1[m + n - i - 1 ] = *iter2;
            i++;
        }
        
        
        sort(nums1.begin(), nums1.end());


    }
};


int main()
{


    vector<int> nums1{ 0 };
    vector<int> nums2{ 1};
    int m = 0;
    int n = 1;

    Solution x;
    x.merge(nums1, m, nums2, n);

    for (auto x : nums1)
        std::cout << x << " ";

    return 0;
}