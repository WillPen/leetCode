/*
给你一个 升序排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。

由于在某些语言中不能改变数组的长度，所以必须将结果放在数组nums的第一部分。更规范地说，如果在删除重复项之后有 k 个元素，那么 nums 的前 k 个元素应该保存最终结果。

将最终结果插入 nums 的前 k 个位置后返回 k 。

不要使用额外的空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间

//0 0 0 1 2 2 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1;
        int len = nums.size();

        if (len == 0)
            return 0;

        while (fast < len)
        {
            if (nums[fast] != nums[fast-1])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};


int main(int argc, char** argv)
{
    vector<int> a = { 1,1,2 };
   // vector<int> b = { 2,6 };

    Solution sa;
    int output = sa.removeDuplicates(a);

   // int arr[] = { 2, 4, 5, 1, 3, 1 };
   // sort(arr, arr + 6);

    return 0;
}
