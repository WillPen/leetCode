/*

给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


//这里做的不行，这里用的话滑窗，但是可以直接暴力解的，如下面注释部分
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int left = 0, right = 0;
        int max_num = 0;
        int tmp_num = 0;

        while (left < len && right < len)
        {
            if (nums[left] == 1 && nums[right] == 1)
            {
                tmp_num++;
                right++;
                max_num = tmp_num > max_num ? tmp_num : max_num;
            }
            else if (nums[left] == 1 && nums[right] != 1)
            {
                right++;
                left = right;
                tmp_num = 0;

            }
            else
            {
                left++;
                right = left;
                tmp_num = 0;
            }

        }
        return max_num;
    }
};

#if 0
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            }
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};
#endif



int main(int argc, char** argv)
{
    vector<int> arr = { 1,1,0,1,1,1 };



    Solution a;
    int out = a.findMaxConsecutiveOnes(arr);



    return 0;
}
