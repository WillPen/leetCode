/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�

//(){}
//([])
//ʹ��ջ
class Solution {
public:

    bool match(char s1, char s2)
    {
        if ((s1 == '{' && s2 == '}') ||
            (s1 == '(' && s2 == ')') ||
            (s1 == '[' && s2 == ']'))
            return true;
        else
            return false;
    }

    bool isValid(string s) {
        int len = s.length();
        int i = 0;
        if (len == 0 || len % 2 != 0)
            return false;

        stack<char> stk;

        while (i < len)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            {
                stk.push(s[i]);
                i++;
            }
            else
            {
                if (stk.size() > 0)
                {
                    char tmp = stk.top();
                    if (match(tmp, s[i]))
                    {
                        stk.pop();
                        i++;
                    }
                    else
                        return false;
                }
                else
                    return false;

            }
        }

        return stk.size() == 0;
    }
};


int main(int argc, char** argv)
{
    string str = "){";

    Solution sa;
    bool o = sa.isValid(str);

    return 0;
}
