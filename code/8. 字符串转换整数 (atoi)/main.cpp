/*

请你来实现一个 myAtoi(string s) 函数，使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。

函数 myAtoi(string s) 的算法如下：

读入字符串并丢弃无用的前导空格
检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数应该被固定为 231 − 1 。
返回整数作为最终结果。
注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。



+123
-123
-0 123
    456
    789aaa624

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

    int myAtoi(string s) {
        int value = 0;
        string last_str;
        int i = 0;
        bool negative = false;
        bool first = true; //这个标志指代空格是否是开头的，如果不少开头的就当作其他符号停止
        int conti_char = 0; //连续的+ -之类的，避免重复

        string str = s;
        while (i < str.size())
        {
            if (first && str[i] == ' ')
            {
                str.erase(i, 1); //消除开头的空格
            }
            else if (first && (str[i] == '-' || str[i] == '+') && conti_char == 0)
            {
                if (str[i] == '-')
                {
                    negative = true;
                }

                str.erase(i, 1);
                conti_char++;
                first = false;
            }
            else if (str[i] >= '0' && str[i] <= '9')
            {
                int tmp = str[i] - '0';
                if (negative) tmp = -tmp;

                //正数的时候避免溢出，为了避免value*10溢出，这里反向计算，INT_MAX/10
                if (!negative)
                {
                    if ((value > (INT_MAX / 10)))
                    {
                        return INT_MAX;
                    }

                    if (INT_MAX / 10 == value && tmp > INT_MAX % 10) //这行主要是避免在tmp超过INT_MAX最大值8
                    {
                        return INT_MAX;
                    }
                }
                else //负数的时候避免溢出
                {
                    if ((value < (INT_MIN / 10)))
                    {
                        return INT_MIN;
                    }

                    if (INT_MIN / 10 == value && tmp < INT_MIN % 10)
                    {
                        return INT_MIN;
                    }
                }

                value = value * 10 + tmp;


                first = false;
                i++;
            }
            else
                break;

        }

        return value;
    }
};

int main(int argc, char** argv)
{
    string value = "-4545645";


    Solution a;
    int out = a.myAtoi(value);



    return 0;
}
