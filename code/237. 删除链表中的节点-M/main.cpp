/*

有一个单链表的 head，我们想删除它其中的一个节点 node。

给你一个需要删除的节点 node 。你将 无法访问 第一个节点  head。

链表的所有值都是 唯一的，并且保证给定的节点 node 不是链表中的最后一个节点。

删除给定的节点。注意，删除节点并不是指从内存中删除它。这里的意思是：

给定节点的值不应该存在于链表中。
链表中的节点数应该减少 1。
node 前面的所有值顺序相同。
node 后面的所有值顺序相同。


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
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};



class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* p = node;
        while (p->next)
        {
            p->val = p->next->val;
            if (p->next->next)
                p = p->next;
            else
                p->next = NULL;
        }
    }
};



int main(int argc, char** argv)
{
    ListNode d(8);
    ListNode c(4,&d);
    ListNode b(2, &c);
    ListNode a(1, &b);


    Solution sa;
    sa.deleteNode(&c);//4



    return 0;
}
