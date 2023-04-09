/*

给你一个整数数组 nums，请你将该数组升序排列。

*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            for (int j = i; j < len; j++)
            {
                if (nums[i] > nums[j])
                {
                    int tmp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = tmp;
                }
            }
        }

        return nums;
    }
};


int main(int argc, char** argv)
{
    vector<int> arr = { 5,2,3,1 };



    Solution sa;
    vector<int> out = sa.sortArray(arr);



    return 0;
}
