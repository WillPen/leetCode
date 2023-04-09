/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/
#include <stdlib.h>
#include <string>
#include <vector>

#include <unordered_map>

using namespace std;//使用标准命名空间

struct ListNode {
    int val;
    struct ListNode* next;
};


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int flag = 0;
    struct ListNode* out = l1;
    struct ListNode* prev = NULL;
    struct ListNode* l11 = l1;
    struct ListNode* l22 = l2;
    while (l11 || l22)
    {
        int n1 = l11 ? l11->val : 0;
        int n2 = l22 ? l22->val : 0;
        struct ListNode* tmp = l11 ? l11 : l22;
        int sum = n1 + n2 + flag;
        if (sum >= 10)
        {
            sum %= 10;
            flag = 1;
        }
        else
            flag = 0;

        tmp->val = sum;
        if (prev != NULL)
            prev->next = tmp;
        prev = tmp;

        if (l11)
            l11 = l11->next;
        else
            l11 = NULL;
        if (l22)
            l22 = l22->next;
        else
            l22 = NULL;
    }
    //是否进位
    if (flag == 1)
    {
        struct ListNode* last = (struct ListNode*)malloc(sizeof(struct ListNode));
        last->val = 1;
        last->next = NULL;
        if (prev != NULL)
            prev->next = last;
    }

    return out;
}

struct ListNode* addTwoNumbers1(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL, * tail = NULL;
    int flag = 0;

    while (l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + flag;
        if (!head)
        {
            head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
            head->val = sum % 10;
            head->next = NULL;
        }
        else
        {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }

        if (sum >= 10)
            flag = 1;
        else
            flag = 0;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (flag == 1)
    {
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail->next->val = 1;
        tail->next->next = NULL;

    }

    return head;
}

int main(int argc, char** argv)
{
    struct ListNode* out = NULL;
    struct ListNode a1, a2, a3;
    struct ListNode b1, b2, b3;

    a1.val = 2;
    a2.val = 4;
    a3.val = 3;
    a1.next = &a2;
    a2.next = &a3;
    a3.next = NULL;

    b1.val = 5;
    b2.val = 6;
    b3.val = 9;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = NULL;

    out = addTwoNumbers1(&a1, &b1);

    return 0;
}
