/*

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。


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
    void reverseString(vector<char>& s) {
        int len = s.size();
        int i = 0;

        while (i < len / 2)
        {
            char tmp = s[len - i - 1];
            s[len - i - 1] = s[i];
            s[i] = tmp;
            i++;
        }
    }
};


int main(int argc, char** argv)
{
    vector<char> arr = { 'a','b','c','d' };



    Solution sa;
     sa.reverseString(arr);



    return 0;
}
