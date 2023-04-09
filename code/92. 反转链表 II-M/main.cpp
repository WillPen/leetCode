/*

给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。


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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i = 1;
        ListNode* cur = head, * pre = NULL, * next = NULL;
        ListNode* start = NULL, * end = NULL;
        while (cur)
        {
            if (i == left)
            {
                start = pre;
            }
            else if (i == right+1)
            {
                end = cur;
            }

            pre = cur;
            cur = cur->next;
            i++;
        }

        cur = head;
        pre = end;
        int n = 1;

        while (cur)
        {
            if (n >= left && n <= right)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                if (n == right && start)
                {
                    start->next = cur;
                }
                else if (n == right && start == NULL)
                {
                    head = cur;
                }
                cur = next;
            }
            else
                cur = cur->next;
            n++;
        }
        return head;
    }
};

int main(int argc, char** argv)
{
   // ListNode e(5);
   // ListNode d(4,&e);
   // ListNode c(3,&d);
    ListNode b(2);
    ListNode a(1, &b);





    Solution sa;
    ListNode* out = sa.reverseBetween(&a,1,2);



    return 0;
}
