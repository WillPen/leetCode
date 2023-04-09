/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0



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
    int reverse_way1(int x) {
        string flag;
        string x_str = to_string(x);
        string t = x_str;
        //int i = x_str.size();

        std::reverse(t.begin(), t.end());

        try {
            int x_int = stoi(t);
            return x < 0 ? -x_int : x_int;
        }
        catch (exception e) {
            return 0;
        }
    }

    int reverse(int x) {
        int r_x = 0;
        int n = x;

        try {
            while (n)
            {
                if (r_x > INT_MAX / 10 || r_x < INT_MIN / 10)
                    return 0;
                r_x = (n % 10) + r_x * 10;
                n = n / 10;
            }
        }
        catch (exception e) { return 0; }

        return r_x;
    }
};

int main(int argc, char** argv)
{
    int value = 130;


    Solution a;
    int out = a.reverse(value);



    return 0;
}
