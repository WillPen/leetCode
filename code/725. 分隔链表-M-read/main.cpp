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
    ListNode() :val(0),next(nullptr){}
    ListNode(int x) :val(x), next(nullptr) {}
    ListNode(int x, ListNode* p) :val(x), next(p) {}
};



class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;

        ListNode* p = head;
        vector<ListNode*> vec_list(k,nullptr);

        while (p)
        {
            size++;
            p = p->next;
        }

        int cyclesize = size / k; //每个list最少个数
        int remainder = size % k; //剩了几个，在最前面几个+1

        p = head;
        for (int i = 0; i < k, p!=nullptr; i++)
        {
            vec_list[i] = p;
            int list_size = i< remainder ? cyclesize + 1 : cyclesize;
            for (int j = 1; j < list_size; j++)
            {
                p = p->next;
            }

            ListNode* t = p->next;
            p->next = nullptr;
            p = t;

        }

        return vec_list;

    }
};

int main(int argc, char** argv)
{
    ListNode j(10);
    ListNode i(9, &j);
    ListNode h(8, &i);
    ListNode g(7, &h);
    ListNode f(6, &g);
    ListNode e(5, &f);
    ListNode d(4, &e);
    ListNode c(3, &d);
    ListNode b(2, &c);
    ListNode a(1, &b);

    Solution sa;
    vector<ListNode*> out = sa.splitListToParts(&a, 3);



    return 0;
}
