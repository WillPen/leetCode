/*

给你一个单链表的引用结点 head。链表中每个结点的值不是 0 就是 1。已知此链表是一个整数数字的二进制表示形式。

请你返回该链表所表示数字的 十进制值 。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#include <unordered_map>

using namespace std;//使用标准命名空间



//Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0, i=0;
        ListNode* p = head;
        while (p)
        {
            if (p->val == 1)
            {
                num = num * 2 + 1;
            }
            else
                num *= 2;
            i++;
            p = p->next;
        }

        return num;

    }
};

int main(int argc, char** argv)
{

  
    ListNode c(1);
    ListNode b(0, &c);
    ListNode a(1,&b);


    Solution aa;
    int out = aa.getDecimalValue(&a);



    return 0;
}
