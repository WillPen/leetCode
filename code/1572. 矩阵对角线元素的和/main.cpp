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
#include <string>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


//判断连续3个为基数
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int num = 0;
        while (arr.size() > 2 && num < arr.size() - 2)
        {
            if (arr[num] & 1 == 1 && arr[num + 1] & 1 == 1 && arr[num + 2] & 1 == 1)
            {
                return true;
            }
            num++;
        }
        return false;
    }
};



int main(int argc, char** argv)
{
    vector<int> arr = { 4,3,2,1 };



    Solution a;
    bool out = a.threeConsecutiveOdds(arr);



    return 0;
}
