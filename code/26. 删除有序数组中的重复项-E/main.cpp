/*
����һ�� �������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��

������ĳЩ�����в��ܸı�����ĳ��ȣ����Ա��뽫�����������nums�ĵ�һ���֡����淶��˵�������ɾ���ظ���֮���� k ��Ԫ�أ���ô nums ��ǰ k ��Ԫ��Ӧ�ñ������ս����

�����ս������ nums ��ǰ k ��λ�ú󷵻� k ��

��Ҫʹ�ö���Ŀռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�
*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�

//0 0 0 1 2 2 3
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 1, fast = 1;
        int len = nums.size();

        if (len == 0)
            return 0;

        while (fast < len)
        {
            if (nums[fast] != nums[fast-1])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;
    }
};


int main(int argc, char** argv)
{
    vector<int> a = { 1,1,2 };
   // vector<int> b = { 2,6 };

    Solution sa;
    int output = sa.removeDuplicates(a);

   // int arr[] = { 2, 4, 5, 1, 3, 1 };
   // sort(arr, arr + 6);

    return 0;
}
