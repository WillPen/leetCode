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
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));

        for (int i = 0; i < m; i++) //3
        {
            for (int j = 0; j < n; j++) //4
            {
                transposed[j][i] = matrix[i][j];
            }
        }

        return transposed;
    }
};


int main(int argc, char** argv)
{
    vector<vector<int>> arr = { { 2,4,-1 },{-10,5,11}, {18,-7,6} };



    Solution a;
    vector<vector<int>> out = a.transpose(arr);



    return 0;
}
