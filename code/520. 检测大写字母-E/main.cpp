/*

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如 "USA" 。
单词中所有字母都不是大写，比如 "leetcode" 。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google" 。
给你一个字符串 word 。如果大写用法正确，返回 true ；否则，返回 false 。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;//使用标准命名空间


class Solution {
public:
    bool detectCapitalUse(string word) {
        int firstLower = true;
        int secondLower = true;
        for (int i = 0; i< word.length(); i++)
        {
            if (i == 0)
            {
                if (isupper(word[i]))
                {
                    firstLower = false;
                }
            }
            else
            {
                if (firstLower)
                {
                    if (tolower(word[i]) != word[i])
                        return false;
                }
                else
                {
                    if (i == 1)
                    {
                        secondLower = islower(word[i]);
                    }
                    else
                    {
                        if (secondLower != islower(word[i]))
                            return false;
                    }
                }
            }
        }
        return true;

    }
};


int main(int argc, char** argv)
{
    string arr = "Abb";



    Solution sa;
    bool o = sa.detectCapitalUse(arr);



    return 0;
}
