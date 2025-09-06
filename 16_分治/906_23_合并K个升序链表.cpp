#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个链表数组，每个链表都已经按升序排列。
//请你将所有链表合并到一个升序链表中，返回合并后的链表。

//分析：维护一个小根堆，将k个链表的头加入小根堆，每次取出一个元素，则加入该元素对应链表的下一个结点


 //Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode* next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
        ListNode* head{nullptr};
        ListNode* tail{nullptr};
        for (auto ele : lists) {
           if(ele) minHeap.push(ele);
        }
        while (!minHeap.empty()) {
            ListNode* cur = minHeap.top();
            minHeap.pop();
            if (cur->next)
                minHeap.push(cur->next);
            if (!head) {//或者设立dummy虚结点避免这句判断
                head = cur;
                tail = head;
            }
            else {//注意尾指针应该指向链表中存在的最后一个结点，不能指向空结点
                tail->next = cur;
                tail = tail->next;
            }
       
        }
        return head;
       


    }
};