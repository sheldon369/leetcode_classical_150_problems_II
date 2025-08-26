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

//����һ�������ͷ�ڵ� head ����ת����������ÿ���ڵ������ƶ� k ��λ�á�
//���������ϵ�β�ڵ����ӵ�ͷ�ڵ㣬���Ҹ����µ�ͷ�ڵ�
//��1������ʵ�ʵ� k = k mod list.size(),��Ҫ֪������ĳ���
//��2��ÿ����תһ����ִ��k�Σ��������ڵ�ʵ�ַ�����  debug:������Ҫȡģ������k����ʱ��ʱ

class Solution {
public:
    ListNode* rotateRightOnce(ListNode* head ) {
        if (!head->next )
            return head;
        ListNode* p = head;
        while (p->next->next)//pΪ�����ڶ����ڵ�
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
            //pΪ�����ڶ����ڵ�
            length++;
            p = p->next;
        }
   

        for (int i = 0;i < k % length;i++) {
            head = rotateRightOnce(head);
        }
        return head;

    }
};
