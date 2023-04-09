/*

给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。

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
    string thousandSeparator(int n) {
        string s;
        while (n / 1000)
        {
            int i = 0;
            int yu = n % 1000;
            string str_yu = to_string(yu);

            while (i++ < 3 - str_yu.length())
            {
                str_yu = "0" + str_yu;

            }

            s = "." + str_yu + s;
            n /= 1000;
        }
        s = to_string(n) + s;

        return s;
    }
};


int main(int argc, char** argv)
{
    int n = 51040;



    Solution a;
    string out = a.thousandSeparator(n);



    return 0;
}
