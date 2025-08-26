#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
//分析：将老的尾节点连接到头节点，并且更换新的头节点
//法1：计算实际的 k = k mod list.size(),需要知晓链表的长度
//法2：每次旋转一步，执行k次（类似日期的实现方案）  debug:还是需要取模，否则k过大时超时

class Solution {
public:
    ListNode* rotateRightOnce(ListNode* head ) {
        if (!head->next )
            return head;
        ListNode* p = head;
        while (p->next->next)//p为倒数第二个节点
            p = p->next;
        ListNode* newHead = p->next;
        newHead->next = head;
        p->next = nullptr;
        return newHead;

    }


    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        ListNode* p = head;
        int length{ 0 };
        while (p) {
            //p为倒数第二个节点
            length++;
            p = p->next;
        }
   

        for (int i = 0;i < k % length;i++) {
            head = rotateRightOnce(head);
        }
        return head;

    }
};
