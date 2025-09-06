#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ���������飬ÿ�������Ѿ����������С�
//���㽫��������ϲ���һ�����������У����غϲ��������

//������ά��һ��С���ѣ���k�������ͷ����С���ѣ�ÿ��ȡ��һ��Ԫ�أ�������Ԫ�ض�Ӧ�������һ�����


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
            if (!head) {//��������dummy�����������ж�
                head = cur;
                tail = head;
            }
            else {//ע��βָ��Ӧ��ָ�������д��ڵ����һ����㣬����ָ��ս��
                tail->next = cur;
                tail = tail->next;
            }
       
        }
        return head;
       


    }
};