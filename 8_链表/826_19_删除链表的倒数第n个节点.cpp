#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ������ɾ������ĵ����� n ����㣬���ҷ��������ͷ��㡣
//��������ɾ���ڵ�Ϊͷ�ڵ㣬���б��鷳����������Ĳ���������������ڱ��ڵ�


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
        }//pָ���ɾ���ڵ��ǰһ��
        p->next = p->next->next;
        return dummy.next;
       
    }
};
