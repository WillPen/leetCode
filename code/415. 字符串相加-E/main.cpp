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

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int len1 = num1.length();
        int len2 = num2.length();
        int max_len = max(len1, len2) + 1; //结果的位数，可能会进位，所以+1位
        string result = string(max_len, '0');
        int k = max_len - 1;

        int i = len1-1, j = len2-1;

        while(i>=0 && j >=0)
        {
            int sum = num1[i] - '0' + num2[j] - '0' + carry;
            carry = 0;
            if(sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }
            result[k--] = sum + '0';
            i--;
            j--;
        }

        while (i >= 0)
        {
            int sum = num1[i] - '0' + carry;
            carry = 0;
            if (sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }
            result[k--] = sum + '0';
            i--;
        }

        while (j >= 0)
        {
            int sum = num2[j] - '0' + carry;
            carry = 0;
            if (sum >= 10)
            {
                carry = 1;
                sum %= 10;
            }
            result[k--] = sum + '0';
            j--;
        }

        if (carry == 1)
            result[k--] = '1';

        if (result[0] == '0')
            return result.substr(1,max_len);
        else
            return result;

    }
};


int main(int argc, char** argv)
{
    string a = "11";
    string b = "123";



    Solution sa;
    string out = sa.addStrings(a,b);



    return 0;
}
