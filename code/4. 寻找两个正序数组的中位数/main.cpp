/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2


示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int* arr = (int*)malloc((nums1.size() + nums2.size())*sizeof(int));
        memset(arr, 0, (nums1.size() + nums2.size()) * sizeof(int));
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int all = len1 + len2;
        double out = 0.0;

        while (i < len1)
            arr[j++] = nums1[i++];
        i = 0;
        while (i < len2)
            arr[j++] = nums2[i++];

        sort(arr, arr + all);
        if (all % 2 == 1)
            out =  arr[all/2];
        else
        {
            int n1 = all / 2;
            int n2 = all / 2 - 1;
            int a = arr[n1];
            int b = arr[n2];
            out = ((a + b) * 1.0) / 2;
        }
        return out;



    }
};

int main(int argc, char** argv)
{
    vector<int> a = { 1,3 };
    vector<int> b = { 2,6 };

    Solution s;
    double output = s.findMedianSortedArrays(a,b);

   // int arr[] = { 2, 4, 5, 1, 3, 1 };
   // sort(arr, arr + 6);

    return 0;
}
