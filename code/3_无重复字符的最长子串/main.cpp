/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:

输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
#include <stdlib.h>
#include <string>
#include <vector>

#include <unordered_map>

using namespace std;//使用标准命名空间

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        vector<char> str;
        int max_len = 0;

        while (end < s.length() && start <=end)
        {
            vector<char>::iterator result = find(str.begin(), str.end(), s[end]); //查找3
            if (result == str.end()) //没找到
            {
                str.push_back(s[end]);
                end++;
                max_len = str.size() > max_len ? str.size() : max_len;
            }
            else
            {
                start++;
                end = start;
                str.clear();
                //str.push_back(s[start]);
            }

        }

        return max_len;
    }
};

int main(int argc, char** argv)
{
    string s = "dvdf";
    Solution a;
    int len = a.lengthOfLongestSubstring(s);

    return 0;
}
