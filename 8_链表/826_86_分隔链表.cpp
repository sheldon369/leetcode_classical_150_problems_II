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

//����һ�������ͷ�ڵ� head ��һ���ض�ֵ x �������������зָ���
//ʹ������ С�� x �Ľڵ㶼������ ���ڻ���� x �Ľڵ�֮ǰ��
//��Ӧ�� ���� ����������ÿ���ڵ�ĳ�ʼ���λ�á�

//����������д���б���������ǰ�ڵ��������ΪС���Ǵ�
//ɨ��������¼������֮ǰС��ĩλ�ã�ʹ���ڱ��ڵ㣩���������Ժ�����С�����뵽С��ĩλ��

class Solution {
public:
    bool isBig(ListNode* p, int x) {
        return p->val >= x ? true:false;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy = ListNode();
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* p = head;
        ListNode* p_pre = &dummy;// p_pre����ָ��p֮ǰ
        int flag{1};//û����big
        while (p) {
            while (flag) {
                if (!p)//�����������нڵ㶼ΪС����pָ���ָ�룬ֱ���˳�
                    return head;
                if (!isBig(p, x)) {//����ǰ�ڵ�ΪС
                    pre = p;
                    p_pre = p;
                    p = p->next;
                }
                else 
                    flag = 0;
            }//while����preָ��С��ĩβ��pָ���
            if (isBig(p, x)) {
                p_pre = p;
                p = p->next;
            }   
            else {
                p_pre->next = p->next;
                p->next = pre->next;
                pre->next = p;
                pre = p;
                p = p_pre->next;
            }
            
        }
        return dummy.next;



    }
};
