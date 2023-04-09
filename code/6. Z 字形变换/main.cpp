/*
��һ�������ַ��� s ���ݸ��������� numRows ���Դ������¡������ҽ��� Z �������С�

���������ַ���Ϊ "PAYPALISHIRING" ����Ϊ 3 ʱ���������£�

P   A   H   N
A P L S I I G
Y   I   R
֮����������Ҫ�����������ж�ȡ��������һ���µ��ַ��������磺"PAHNAPLSIIGYIR"��

����ʵ��������ַ�������ָ�������任�ĺ�����

string convert(string s, int numRows);


ʾ�� 1��

���룺s = "PAYPALISHIRING", numRows = 3
�����"PAHNAPLSIIGYIR"
ʾ�� 2��
���룺s = "PAYPALISHIRING", numRows = 4
�����"PINALSIGYAHRPI"
���ͣ�
P     I    N
A   L S  I G
Y A   H R
P     I
ʾ�� 3��

���룺s = "A", numRows = 1
�����"A"
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <algorithm>

#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�


class Solution {
public:
    string convert(string s, int numRows) {
        string last;
        vector<string> str(numRows);

        int n = 0;
        int idx = 0;
        bool reverse = false;

        if (numRows == 1)
            return s;

        while (n < s.size())
        {
            str[idx].push_back(s[n]);
            if (idx == numRows - 1) reverse = true;
            else if (idx == 0) reverse = false;

            if (reverse) idx--;
            else idx++;
            n++;
        }

        for (int i = 0; i < numRows; i++)
            last += str[i];

        return last;
    }
};


int main(int argc, char** argv)
{
    int numRows = 3;
    string s = "PAYPALISHIRING";

    Solution a;
    string out = a.convert(s, numRows);



    return 0;
}
