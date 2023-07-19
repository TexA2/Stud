/*
*При наличии целочисленного массива и целого числа удалите все вхождения в массив.
Порядок элементов может быть изменен.
Затем возвращаем количество элементов, в которых не равно. nums val val nums nums val

Рассмотрим количество элементов, в которых не равно , чтобы получить accepted, вам нужно выполнить следующие действия:nums val k

Измените массив таким образом, чтобы первые элементы содержали элементы, которые не равны .
Остальные элементы не важны, как и размер .nums k nums val nums nums
Возвращать.k


Пример 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Пояснение: Ваша функция должна возвращать k = 2, причем первые два элемента nums равны 2.
Не имеет значения, что вы оставляете за пределами возвращаемого k (следовательно, это символы подчеркивания).

Пример 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Пояснение: Ваша функция должна возвращать k = 5, причем первые пять элементов nums содержат 0, 0, 1, 3 и 4.
Обратите внимание, что пять элементов могут быть возвращены в любом порядке.
Не имеет значения, что вы оставляете за пределами возвращаемого k (следовательно, это символы подчеркивания).
  
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

