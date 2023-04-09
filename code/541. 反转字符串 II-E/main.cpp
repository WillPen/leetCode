/*

给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。

子字符串 是字符串中的一个连续字符序列。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;//使用标准命名空间

#if 0
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int len = s.length();
        unordered_map<char, int> hash;
        int left = 0, right = 0;
        int num = 0;
        int max_num = -1;
        //int i = 0;


        for (int i = 0; i < len; i++)
        {
            num = len-i-2;
            hash[s[i]] = 1;
            for (int j = len-1; j > i; j--)
            {
                if (hash[s[j]] == 1)
                {
                    hash.clear();
                    max_num = max(max_num,num);
                }
                else
                {
                    num--;
                }
            }
        }

        return max_num;
    }
};
#endif

//记录26个字母第一次出现的位置，后续判断重复字母最后出现的位置，计算长度，取最大
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int max_num = -1;
        int len = s.size();
        vector<int> first(26, -1);

        for (int i = 0; i < len; i++)
        {
            if (first[s[i] - 'a'] < 0)
            {
                first[s[i] - 'a'] = i;
            }
            else
            {
                max_num = max(i-first[s[i]-'a']-1, max_num);
            }
        }

        return max_num;
    }
};


int main(int argc, char** argv)
{
    string arr = "abba";



    Solution sa;
    int o = sa.maxLengthBetweenEqualCharacters(arr);



    return 0;
}
