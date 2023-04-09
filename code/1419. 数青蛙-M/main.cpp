/*

给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。

请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。


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
    int minNumberOfFrogs(string croakOfFrogs) {
        int num_frog = 0;
        int len_croak = 5;
        int i = 0;
        int len = croakOfFrogs.length();
        if (len % len_croak) return -1; //叫声不是5个字母说明参杂了其他，直接-1

        int c = 0, r = 0, o = 0, a = 0, k = 0;

        for (i = 0; i < len; i++)
        {
            if (croakOfFrogs[i] == 'c')
            {
                if (k > 0)
                {
                    k--;
                }
                else
                {
                    num_frog++;
                }
                c++;
            }
            else if (croakOfFrogs[i] == 'r')
            {
                c--;
                r++;
            }
            else if (croakOfFrogs[i] == 'o')
            {
                r--;
                o++;
            }
            else if (croakOfFrogs[i] == 'a')
            {
                o--;
                a++;
            }
            else if (croakOfFrogs[i] == 'k')
            {
                a--;
                k++;
            }
            if (c < 0 || r < 0 || o < 0 || a < 0) 
            {
                break;
            }
        }

        if (c != 0 || r != 0 || o != 0 || a != 0) {
            return -1;
        }


        return num_frog;
    }
};

int main(int argc, char** argv)
{
    string arr = "aoocrrackk";



    Solution a;
    int out = a.minNumberOfFrogs(arr);



    return 0;
}
