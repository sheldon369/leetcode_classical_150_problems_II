#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ��������������ͷ head �� ɾ��ԭʼ�����������ظ����ֵĽڵ㣬ֻ���²�ͬ������ ������ ����������� ��

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//����������������ͬԪ�سɿ����
//���flag��¼�½ڵ�;ɽڵ��Ƿ�һ����ֱ���ҵ���һ���ģ�ʹ��pre��������
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* p = pre->next;
        int flag{ 0 };
        while (p) {
            while (p->next && p->val == p->next->val) {//����nullptr���ܷ���val�ֶ�
                p = p->next;
                flag = 1;
            }//pλ����ͬԪ�ص�ĩβ
            if (flag) //�������ظ�Ԫ�أ�pre����,����p
                pre->next = p->next;
            else //û�����ظ�Ԫ��
                pre = p;
            flag = 0;
            p = p->next;
        }
        return dummy.next;
       


    }
};