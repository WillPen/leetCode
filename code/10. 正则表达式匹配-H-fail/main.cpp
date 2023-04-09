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


class Solution {
public:

    bool isMatch(string s, string p) {
        bool start = false;
        int i = 0;
        int j = 0;
        int len = s.size();
        if (p.find('.') != -1 || p.find('*') != -1)
        {
            while (i < len)
            {
                if (j >= p.size())
                    return false;
                else if (p[j] == '*') //如果当前规则是* ，那么可以匹配无限个字符，s向后移位
                {
                    if (!start && s[i] != p[j - 1])
                    {
                        j++;
                        continue;
                    }
                    else if (p[j - 1] == '.')
                    {
                        //i++;
                    }
                    else if (start && s[i] != p[j - 1])
                    {
                        j++;
                        continue;
                    }

                    start = true;
                    i++;
                }
                else if (p[j] == '.')  //如果当前规则是.那么所以字符都符合，都向后移动一位
                {
                    start = true;
                    i++;
                    j++;
                }
                else
                {
                    if (p[j] != s[i] && !start)
                    {
                        j++;
                    }
                    else if (p[j] == s[i])
                    {
                        i++;
                        j++;
                        start = true;
                    }
                    else if (start && p[j] != s[i])
                        return false;


                }
            }
        }
        else
            return s == p;

        if (j < p.size()-1 && p[j + 1] != '*' && p[j+1] != p[j-1])
            return false;

        return true;
    }
};


int main(int argc, char** argv)
{
    string str = "aaa";
    string rules = "a*a";



    Solution a;
    bool out = a.isMatch(str, rules);



    return 0;
}
