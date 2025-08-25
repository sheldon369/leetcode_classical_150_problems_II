#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;


//���������ͷ�ڵ� head ��ÿ k ���ڵ�һ����з�ת�����㷵���޸ĺ������
//k ��һ��������������ֵС�ڻ��������ĳ��ȡ�
//����ڵ��������� k ������������ô�뽫���ʣ��Ľڵ㱣��ԭ��˳��

//������ʵ��˼·����825_92_��ת����II����������ֱ�ӵ��øú������������ڴ˻������޸Ĵ���ʵ��

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);//�ڱ�ָ��
        dummy.next = head;
        ListNode* pre = &dummy;

        int length{ 0 };//lengthΪ�����ܳ���
        ListNode* p = head;
        while (p) {
            length++;
            p = p->next;
        }

        for (int t = 0;t < length / k;t++) {
            ListNode* p = pre->next;
            for (int i = 1;i < k;i++) {//��תk��Ԫ�أ�ִ��k-1�η�ת
                ListNode* next = p->next;
                p->next = next->next; 
                next->next = pre->next;
                pre->next = next;
            }
            pre = p;//��ת�㷨�������������ָ��ת�����β���
        
        }

        return dummy.next;


    }
};