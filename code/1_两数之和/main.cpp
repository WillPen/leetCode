/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]

*/
#include <string>
#include <vector>

#include <unordered_map>

using namespace std;//使用标准命名空间


class Solution {
public:
    //暴力求解，轮询所有情况
    vector<int> twoSum_way1(vector<int>& nums, int target) {
        //vector<int> out;
        int num = nums.size();
        for (int i = 0; i < num; i++)
        {
            for (int j = i + 1; j < num; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                   // out.push_back(i);
                   // out.push_back(j);
                   // return out;
                    return { i,j };
                }
            }
        }
        //return out;
        return {};
    }

    //使用hashmap，查找target-n时间复杂度从O(n)降低到O(1)
    vector<int> twoSum_way2(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = hash_map.find((target - nums[i]));
            if (it != hash_map.end())
            {
                return { it->second, i};
            }
            hash_map[nums[i]] = i;
        }
        //return out;
        return {};
    }
};


int main(int argc, char** argv)
{
    vector<int> out;
    vector<int> in = { 2,7,11,5};
    int target = 9;

    Solution a;
    out = a.twoSum_way2(in, target);

    return 0;
}
