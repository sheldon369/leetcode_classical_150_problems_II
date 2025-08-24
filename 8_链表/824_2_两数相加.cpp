#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

/*给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头*/


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
    //该解法能处理的位数有限，当面对天文数字是产生舍入故出现问题
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
    //        return new ListNode(0);//new在堆上创建对象，返回指向该对象的指针
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


    //本题真正考察的是加法器原理与进位
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        ListNode* a = l1;
        ListNode* b = l2;
        while (a || b || carry) {//a中还有结点或者b中还有节点或者还有个单独进位
            int n = (a ? a->val : 0) + (b ? b->val : 0) + carry;// 若a为空则用0补位
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

