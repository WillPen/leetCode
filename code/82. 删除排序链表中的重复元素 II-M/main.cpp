/*

给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间




struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//a 1 1 1 3  3  4   4   5
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return NULL;

        ListNode* dummy = new ListNode(150, head);
        ListNode* cur = head, * pre = dummy;
        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
            {
                int v = cur->val;
                while (cur && cur->val == v)
                {
                    cur = cur->next;
                }
                pre->next = cur;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy->next;

    }
};


int main(int argc, char** argv)
{
    ListNode d(4);
    ListNode c(2, &d);
    ListNode b(2, &c);
    ListNode a(1, &b);


    Solution sa;
    ListNode* out = sa.deleteDuplicates(&a);



    return 0;
}
