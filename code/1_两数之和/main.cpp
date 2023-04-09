/*
����һ���������� nums ��һ������Ŀ��ֵ target�������ڸ��������ҳ� ��ΪĿ��ֵ target  ���� ���� ���������������ǵ������±ꡣ
����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
����԰�����˳�򷵻ش𰸡�

ʾ�� 1��

���룺nums = [2,7,11,15], target = 9
�����[0,1]
���ͣ���Ϊ nums[0] + nums[1] == 9 ������ [0, 1] ��
ʾ�� 2��

���룺nums = [3,2,4], target = 6
�����[1,2]
ʾ�� 3��

���룺nums = [3,3], target = 6
�����[0,1]

*/
#include <string>
#include <vector>

#include <unordered_map>

using namespace std;//ʹ�ñ�׼�����ռ�


class Solution {
public:
    //������⣬��ѯ�������
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

    //ʹ��hashmap������target-nʱ�临�Ӷȴ�O(n)���͵�O(1)
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
