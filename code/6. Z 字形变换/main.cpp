/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);


示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
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
    string convert(string s, int numRows) {
        string last;
        vector<string> str(numRows);

        int n = 0;
        int idx = 0;
        bool reverse = false;

        if (numRows == 1)
            return s;

        while (n < s.size())
        {
            str[idx].push_back(s[n]);
            if (idx == numRows - 1) reverse = true;
            else if (idx == 0) reverse = false;

            if (reverse) idx--;
            else idx++;
            n++;
        }

        for (int i = 0; i < numRows; i++)
            last += str[i];

        return last;
    }
};


int main(int argc, char** argv)
{
    int numRows = 3;
    string s = "PAYPALISHIRING";

    Solution a;
    string out = a.convert(s, numRows);



    return 0;
}
