/*

给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

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

// 0 1 2 3 4 5
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* cur = list1, *pre = list1;
        int i = 0;

        while (cur)
        {
            if (i >= a && i <= b)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
            i++;
        }

        cur = list1;
        i = 0;
        ListNode* next1=NULL,*save=NULL;
        while (cur)
        {
            if (i == a - 1)
            {
                next1 = cur->next;
                cur->next = list2;
                while (list2)
                {
                    if (list2->next == NULL)
                        save = list2;
                    list2 = list2->next;

                }
                save->next = next1;
            }
            i++;
            cur = cur->next;
        }

        return list1;

    }
};


int main(int argc, char** argv)
{
    ListNode f(5);
    ListNode e(4, &f);
    ListNode d(3,&e);
    ListNode c(2, &d);
    ListNode b(1, &c);
    ListNode a(0, &b);

    ListNode c1(300);
    ListNode b1(200, &c1);
    ListNode a1(100, &b1);

    Solution sa;
    ListNode* out = sa.mergeInBetween(&a,3,4,&a1);



    return 0;
}
