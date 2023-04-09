/*

给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。


示例 1：

输入：x = 121
输出：true
示例 2：

输入：x = -121
输出：false
解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3：

输入：x = 10
输出：false
解释：从右向左读, 为 01 。因此它不是一个回文数。

*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间

class Solution {
public:
    bool isPalindrome(int x) {
        bool flag = true;
        string x_str = std::to_string(x);
        int len = x_str.size();
        int i = 0;

        while (i < len/2) //只判断一半就行
        {
            if (x_str[i] != x_str[len - 1 - i])
            {
                flag = false;
                break;
            }
            i++;
        }
        return flag;
    }
};

int main(int argc, char** argv)
{
    int value = 1223321;


    Solution a;
    bool out = a.isPalindrome(value);



    return 0;
}
