/*

将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。


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


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1_cur, * p2_cur;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* head = NULL, *save_head = NULL;
        int tmp = 0;

        while (p1 || p2)
        {
            if (p1 && p2)
            {
                if (p1->val <= p2->val)
                {
                    if (!head)
                    {
                        save_head = head = p1;
                        p1 = p1->next;
                        continue;
                    }
                    head->next = p1;
                    head = head->next;
                    p1 = p1->next;
                }
                else
                {
                    if (!head)
                    {
                        save_head = head = p2;
                        p2 = p2->next;
                        continue;
                    }
                    head->next = p2;
                    head = head->next;
                    p2 = p2->next;
                }
            }
            else if (p1)
            {
                if (!head)
                {
                    save_head = head = p1;
                    p1 = p1->next;
                    continue;
                }
                head->next = p1;
                head = head->next;
                p1 = p1->next;
            }
            else
            {
                    if (!head)
                    {
                        save_head = head = p2;
                        p2 = p2->next;
                        continue;
                    }
                head->next = p2;
                head = head->next;
                p2 = p2->next;
            }
        }


        return save_head;
    }
};


int main(int argc, char** argv)
{
    ListNode c(4);
    ListNode b(2, &c);
    ListNode a(1, &b);

    ListNode cc(4);
    ListNode bb(3, &cc);
    ListNode aa(1, &bb);



    Solution sa;
    bool out = sa.mergeTwoLists(&a, &aa);



    return 0;
}
