/*

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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
    ListNode* detectCycle(ListNode* head) {
        map<ListNode*, int> hash;

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        while (head)
        {
            if (hash.find(head) != hash.end())
            {
                return head;
            }
            else
            {
                hash[head] = 1;
                head = head->next;
            }
        }
    }
};


int main(int argc, char** argv)
{


    ListNode b(2,&c);
    ListNode a(3, &b);
    ListNode d(4, &b);
    ListNode c(0, &d);



   // Solution sa;
   // bool out = sa.detectCycle(&a, 1, 2);



    return 0;
}
