/*

给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。


*/
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
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
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        map<ListNode*, int> hash;

        while (head)
        {
            if (hash.find(head) != hash.end())
                return true;
            else
            {
                hash[head] = 1;
                head = head->next;
            }
        }

        return false;

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
    bool out = sa.hasCycle(&a, 1, 2);



    return 0;
}
