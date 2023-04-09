/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��

ʾ�� 1��

���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2


ʾ�� 2��

���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <algorithm>

#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�

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
