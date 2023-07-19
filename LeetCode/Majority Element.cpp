/*
Учитывая массив nums размера n, верните основной элемент.

Мажоритарный элемент - это элемент, который появляется более n / 2 раз.
Вы можете предположить, что основной элемент всегда существует в массиве.

Пример 1:
Input: nums = [3, 2, 3]
Output : 3

Пример 2:
Input : nums = [2, 2, 1, 1, 1, 2, 2]
Output : 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() <= 0) return 0;

        int n = nums.size() ;

        int mash_elem = (n / 2 != 0) ? n / 2 : 1;
        sort(nums.begin(), nums.end());

        int count_max{};
        int count{}; // кол-во повторений
        int elem{ nums[0]}; // значение этого элемента

        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                if (count_max < count)
                {
                    count_max = count;
                    elem = nums[i - 1];
                }
                count = 0;
            }

            ++count;

            if (i == nums.size() - 1)
            {
                if (count_max < count)
                {
                    count_max = count;
                    elem = nums[i - 1];
                }
            }

        }


        return elem;

    }
};


int main()
{

    Solution xx;
    vector<int> nums{ 1 };

    cout << xx.majorityElement(nums) << endl;

    return 0;
}