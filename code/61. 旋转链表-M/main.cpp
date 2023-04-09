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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        int n = 0;
        ListNode* cur = head, * newHead=NULL, *pre = NULL;
        ListNode* tail = NULL;

        if (head == NULL || k==0) return head;

        while (cur)
        {
            len++;
            if (cur->next == NULL)
            {
                tail = cur; //保存尾部
            }

            cur = cur->next;
        }

        if (k == len)
            return head;

        n = k > len ? k%len : k; //计算需要移动的次数
        cur = head;
        tail->next = head; //连接头尾

        for (int i = 0; i <= len-n-1; i++)
        {
            if (i == len-n-1)
            {
                newHead = cur->next;
                cur->next = NULL;
                break;
            }
            else
            {
                cur = cur->next;
            }
                
        }

        return newHead;

    }
};



int main(int argc, char** argv)
{
   // ListNode e(5);
   // ListNode d(4, &e);
   // ListNode c(3, &d);
    ListNode b(2);
    ListNode a(1);



    Solution sa;
    ListNode* out = sa.rotateRight(&a, 99);



    return 0;
}
