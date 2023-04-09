/*

给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，并且这些子字符串中的所有 0 和所有 1 都是成组连续的。

重复出现（不同位置）的子串也要统计它们出现的次数。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


//00111
class Solution {
public:
    int countBinarySubstrings(string s) {
        int num = 1;
        vector<int> vec_s;
        char pre = s[0];
        int count = 0;

        for (int i = 1; i < s.length(); i++)
        {
            if (pre == s[i])
            {
                num++;
            }
            else
            {
                vec_s.push_back(num);
                num = 1;
                pre = s[i];
            }
        }

        if(num > 0)
            vec_s.push_back(num);

        
        for (int i = 1; i < vec_s.size(); i++)
            count += min(vec_s[i], vec_s[i - 1]);


        return count;

    }
};




int main(int argc, char** argv)
{
    string a = "10101";
    char b = a[1];

    Solution sa;
    int out = sa.countBinarySubstrings(a);



    return 0;
}
