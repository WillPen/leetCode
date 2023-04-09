/*
����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
ʾ�� 1:

����: s = "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��

ʾ�� 2:

����: s = "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��

ʾ�� 3:

����: s = "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "wke"�������䳤��Ϊ 3��
     ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke" ��һ�������У������Ӵ���
*/
#include <stdlib.h>
#include <string>
#include <vector>

#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        vector<char> str;
        int max_len = 0;

        while (end < s.length() && start <=end)
        {
            vector<char>::iterator result = find(str.begin(), str.end(), s[end]); //����3
            if (result == str.end()) //û�ҵ�
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
