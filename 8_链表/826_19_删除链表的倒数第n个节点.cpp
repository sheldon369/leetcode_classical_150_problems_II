#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//分析：若删除节点为头节点，则判别麻烦，对于链表的操作，都可以设计哨兵节点


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode();
        dummy.next = head;
        int length{ -1 };
        ListNode* p = &dummy;
        while (p) {
            length++;
            p = p->next;
        }
        p = &dummy;
        for (int i = 0;i < length - n ;i++) {
            p = p->next;
        }//p指向待删除节点的前一个
        p->next = p->next->next;
        return dummy.next;
       
    }
};
