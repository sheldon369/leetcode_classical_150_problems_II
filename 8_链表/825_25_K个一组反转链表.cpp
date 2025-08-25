#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;


//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
//k 是一个正整数，它的值小于或等于链表的长度。
//如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

//分析：实现思路类似825_92_反转链表II，甚至可以直接调用该函数，但我们在此基础上修改代码实现

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

        ListNode dummy(0);//哨兵指针
        dummy.next = head;
        ListNode* pre = &dummy;

        int length{ 0 };//length为链表总长度
        ListNode* p = head;
        while (p) {
            length++;
            p = p->next;
        }

        for (int t = 0;t < length / k;t++) {
            ListNode* p = pre->next;
            for (int i = 1;i < k;i++) {//反转k个元素，执行k-1次反转
                ListNode* next = p->next;
                p->next = next->next; 
                next->next = pre->next;
                pre->next = next;
            }
            pre = p;//反转算法结束，工作结点指向反转区间的尾结点
        
        }

        return dummy.next;


    }
};