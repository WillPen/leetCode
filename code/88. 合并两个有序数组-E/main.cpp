/*

88. 合并两个有序数组

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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] > nums2[j])
            {
                tmp.push_back(nums2[j]);
                j++;
            }
            else
            {
                tmp.push_back(nums1[i]);
                i++;
            }
        }

        while (i < m)
        {
            tmp.push_back(nums1[i]);
            i++;
        }
        while (j < n)
        {
            tmp.push_back(nums2[j]);
            j++;
        }
        nums1.swap(tmp);
    }
};


int main(int argc, char** argv)
{
    vector<int> a = {1,2,3,0,0,0};
    vector<int> b = {2,5,6};



    Solution sa;
    sa.merge(a, 3, b, 3);



    return 0;
}
