/*

给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

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

//1->2->3->4->5
//1->5->2->4->3
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> vec;
        ListNode* cur = head;

        while (cur)
        {
            vec.push_back(cur);
            cur = cur->next;
        }

        int i = 0, j = vec.size() - 1;
        cur = head;
        while (i<j)
        {
            vec[i]->next = vec[j];
            i++;
            if (i == j)
            {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = NULL;

    }
};

int main(int argc, char** argv)
{
    ListNode e(5);
    ListNode d(4,&e);
    ListNode c(3,&d);
    ListNode b(2,&c);
    ListNode a(1, &b);





    Solution sa;
    sa.reorderList(&a);



    return 0;
}
