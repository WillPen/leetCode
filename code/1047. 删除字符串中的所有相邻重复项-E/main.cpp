/*



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
    string removeDuplicates(string s) {
        string dup;

        for (auto ch : s)
        {
            if (!dup.empty() && dup.back() == ch)
            {
                dup.pop_back();
            }
            else
                dup.push_back(ch);
        }

        return dup;

    }
};


int main(int argc, char** argv)
{
    string a = "abbaca";



    Solution sa;
    string out = sa.removeDuplicates(a);



    return 0;
}
