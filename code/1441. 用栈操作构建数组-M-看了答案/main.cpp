/*


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


//1 3
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> out;
        int i = 0;

        for (int num : target)
        {
            while (++i < num)
            {
                out.emplace_back("Push");
                out.emplace_back("Pop");
                //i++;
            }
            out.emplace_back("Push");
        }


        return out;
    }
};


int main(int argc, char** argv)
{
    vector<int> arr = { 1,3 };



    Solution a;
    vector<string> out = a.buildArray(arr, 3);



    return 0;
}
