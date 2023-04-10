/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;//使用标准命名空间

//(){}
//([])
//使用栈
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
