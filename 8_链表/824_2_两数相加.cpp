#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

/*�������� �ǿ� ��������ʾ�����Ǹ�������������ÿλ���ֶ��ǰ��� ���� �ķ�ʽ�洢�ģ�����ÿ���ڵ�ֻ�ܴ洢 һλ ���֡�
���㽫��������ӣ�������ͬ��ʽ����һ����ʾ�͵�����
����Լ���������� 0 ֮�⣬���������������� 0 ��ͷ*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    //�ýⷨ�ܴ����λ�����ޣ���������������ǲ�������ʳ�������
    //int list_to_int(ListNode* l) {
    //    int res{0};
    //    int mul = 1;
    //    while (l != nullptr) {
    //        res += mul * (l->val);
    //        l = l->next;
    //        mul *= 10;
    //    }
    //    return res;
    //}

    //ListNode* int_to_list(int n) {
    //    if (n == 0)
    //        return new ListNode(0);//new�ڶ��ϴ������󣬷���ָ��ö����ָ��
    //    ListNode* head = nullptr;
    //    ListNode* tail = nullptr;
    //    while (n > 0) {
    //        int cur = n % 10;
    //        ListNode* node = new ListNode(cur);

    //        if (!head) {
    //            head = node;
    //            tail = node;
    //        }
    //        else {
    //            tail->next = node; 
    //            tail = node;
    //        }
    //        n /= 10;
    //    }
    //    return head;
    //}


    //��������������Ǽӷ���ԭ�����λ
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* a = l1;
        ListNode* b = l2;
        while (a || b || carry) {//a�л��н�����b�л��нڵ���߻��и�������λ
            int n = (a ? a->val : 0) + (b ? b->val : 0) + carry;// ��aΪ������0��λ
            carry = n / 10;
            n = n % 10;
            ListNode* node = new ListNode(n);
            if (!head) {
                head = tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
            if (a) a = a->next;
            if (b) b = b->next;
        }
        return head;
 
    }
};

