/*

给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

#include <unordered_map>

using namespace std;//使用标准命名空间

//0 1 0 3 12
//1 0 3 12
//使用快慢指针把非0填充在前面，然后后面手动填0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        int size = nums.size();

        if (size == 0)
            return;


        while (fast < size)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        for (int i = slow; i < size; i++)
            nums[i] = 0;
    }
};


int main(int argc, char** argv)
{
    vector<int> a = { 0,1,0,3,12 };

    Solution sa;
    sa.moveZeroes(a);



    return 0;
}
