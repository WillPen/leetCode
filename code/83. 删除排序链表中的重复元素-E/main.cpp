/*

给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间


/*
* 这个方式使用了hash表，由于val是-100~100，数组不饿能使用负数，所以都加上了100，变成了0~200
* 
* 其实还有更简单的方法，注意：题目是一个已排序的链表，所以连续的都在一块，只要遍历一遍把前后重复的处理下就行
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* phead = head, *pre_head = head;
        int hashmap_org[250] = { 0 };

        while (head)
        {
            if (hashmap_org[head->val + 100] == 0)
            {
                hashmap_org[head->val + 100] = 1;
                pre_head = head;
                head = head->next;
            }    
            else
            {
                pre_head->next = head->next;
                head = head->next;
            }
        }

        return phead;

    }
};


int main(int argc, char** argv)
{
    ListNode d(4);
    ListNode c(2,&d);
    ListNode b(2, &c);
    ListNode a(1, &b);





    Solution sa;
    ListNode* out = sa.deleteDuplicates(&a);



    return 0;
}
