/*

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。


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
// 1 2 3 4
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode *next = head;
        ListNode* pre = NULL;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }


};


int main(int argc, char** argv)
{
    ListNode d(4);
    ListNode c(3, &d);
    ListNode b(2, &c);
    ListNode a(1, &b);


    Solution sa;
    ListNode* out = sa.reverseList(&a);



    return 0;
}
