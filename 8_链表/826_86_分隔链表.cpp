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

//给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
//使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
//你应当 保留 两个分区中每个节点的初始相对位置。

//分析：首先写个判别函数分析当前节点所属类别为小还是大
//扫描链表，记录碰到大之前小的末位置（使用哨兵节点），碰到大以后，所有小都插入到小的末位置

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
        ListNode* p_pre = &dummy;// p_pre总是指向p之前
        int flag{1};//没碰到big
        while (p) {
            while (flag) {
                if (!p)//若链表中所有节点都为小，则p指向空指针，直接退出
                    return head;
                if (!isBig(p, x)) {//若当前节点为小
                    pre = p;
                    p_pre = p;
                    p = p->next;
                }
                else 
                    flag = 0;
            }//while结束pre指向小的末尾，p指向大
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
