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
    string restoreString(string s, vector<int>& indices) {
        string result = s;
        for (int i = 0; i < indices.size(); i++)
        {
            int num = indices[i];
            result[num] = s[i];
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    string a = "codeleet";
    vector<int> b = { 4,5,6,7,0,2,1,3 };



    Solution sa;
    string out = sa.restoreString(a, b);



    return 0;
}
