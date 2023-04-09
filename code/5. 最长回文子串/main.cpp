/*
给你一个字符串 s，找到 s 中最长的回文子串。



示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
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
    string longestPalindrome_baoli(string s) {
        int max_len = 0;
        string max_str;

        if (s.size() == 1) return s;
        if (s.size() == 0) return "";

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                string str = s.substr(i, j);
                string rev_str = str;
                reverse(rev_str.begin(), rev_str.end());
                if (rev_str == str)
                {
                    if (str.size() > max_len)
                    {
                        max_len = str.size();
                        max_str = str;
                    }
                }
            }
        }

        return max_str;
    }


    string spreadStr(string s, int i, int j)
    {
        int max_len = 1;
        int max_start_i = i;
        int left = i;
        int right = j;
        int start = 0;
        int end = s.size();


        while (left >= 0 && right < end)
        {
            if (s[left] == s[right])
            {
                max_len = right - left + 1;
                max_start_i = left;
            }
            else
                break;

            left -= 1;
            right += 1;
        }
 


        return s.substr(max_start_i, max_len);

    }

    string longestPalindrome_self(string s) {
        string max_str;
        int max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {

            string str_a = spreadStr(s, i, i);
            string str_b = spreadStr(s, i, i+1);

            if (str_a.size() > max_len)
            {
                max_len = str_a.size();
                max_str = str_a;
            }
            if (str_b.size() > max_len)
            {
                max_len = str_b.size();
                max_str = str_b;
            }
        }

        return max_str;
    }


    pair<int, int> expandStr(string& s, int i, int j)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }

        return { i+1,j-1 };
    }

    string longestPalindrome(string s) {
        int last_start = 0;
        int last_end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            pair<int, int> a1 = expandStr(s,i,i);
            pair<int, int> a2 = expandStr(s, i, i+1);

            if (a1.second - a1.first > last_end - last_start)
            {
                last_start = a1.first;
                last_end = a1.second;
            }
            if (a2.second - a2.first > last_end - last_start)
            {
                last_start = a2.first;
                last_end = a2.second;
            }
        }

        return s.substr(last_start, last_end - last_start + 1);
    }




};

int main(int argc, char** argv)
{
    string s = "ccc";

    Solution a;
    string out = a.longestPalindrome(s);



    return 0;
}
