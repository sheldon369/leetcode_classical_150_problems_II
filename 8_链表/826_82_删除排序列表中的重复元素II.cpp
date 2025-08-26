#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//分析：有序链表，相同元素成块出现
//设计flag记录新节点和旧节点是否一样，直到找到不一样的，使用pre进行重连
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* p = pre->next;
        int flag{ 0 };
        while (p) {
            while (p->next && p->val == p->next->val) {//对于nullptr不能访问val字段
                p = p->next;
                flag = 1;
            }//p位于相同元素的末尾
            if (flag) //出现了重复元素，pre不变,跳过p
                pre->next = p->next;
            else //没出现重复元素
                pre = p;
            flag = 0;
            p = p->next;
        }
        return dummy.next;
       


    }
};