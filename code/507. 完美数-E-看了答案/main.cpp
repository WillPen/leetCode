/*

对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。

给定一个 整数 n， 如果是完美数，返回 true；否则返回 false。


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
    bool checkPerfectNumber(int num) {
        int sum = 1;
        int i = 2;

        if (num == 1)
            return false;

        while (i<sqrt(num))
        {
            if (!(num % i))
            {
                sum += i;
                if(i*i < num)
                    sum += num / i;
            }
            i++;
        }

        return  (sum == num);
    }
};


int main(int argc, char** argv)
{
    int a = 28;



    Solution sa;
    bool out = sa.checkPerfectNumber(a);



    return 0;
}
