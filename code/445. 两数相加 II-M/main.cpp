/*

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        ListNode* cur1 = l1, * cur2 = l2;

        while (cur1)
        {
            a.push(cur1->val);
            cur1 = cur1->next;
        }

        while (cur2)
        {
            b.push(cur2->val);
            cur2 = cur2->next;
        }

        int i = 0;
        int max_len = a.size() > b.size() ? a.size() : b.size();

        int carry = 0;
        int sum = 0;
        ListNode* next = NULL;

        while (i++ < max_len)
        {
            int v1=0, v2=0;
            if (a.size() > 0)
            {
                v1 = a.top();
                a.pop();
            }
            if (b.size() > 0)
            {
                v2 = b.top();
                b.pop();
            }

            sum = v1 + v2 + carry;
            carry = 0;
            if (sum >= 10)
            {
                sum %= 10;
                carry = 1;
            }
            ListNode* head = new ListNode(sum);
            head->next = next;
            next = head;
        }

        if (carry == 1)
        {
            ListNode* head = new ListNode(1);
            head->next = next;
            next = head;
        }

        return next;
    }
};


int main(int argc, char** argv)
{
    ListNode d(3);
    ListNode c(4, &d);
    ListNode b(2, &c);
    ListNode a(7, &b);

    ListNode c1(4);
    ListNode b1(6, &c1);
    ListNode a1(5, &b1);


    Solution sa;
    ListNode* out = sa.addTwoNumbers(&a, &a1);



    return 0;
}
