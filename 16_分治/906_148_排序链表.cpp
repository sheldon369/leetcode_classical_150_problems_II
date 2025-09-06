#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
//分析：对链表的排序可以采用插入排序或者归并排序，归并排序采用快慢指针找到链表的中点

  class Solution {
  public:
      ListNode* merge(ListNode* l1, ListNode* l2) {
          ListNode* dummy = new ListNode();//虚拟头指针
          ListNode* tail = dummy;
          while (l1 && l2) {
              if (l1->val < l2->val) {
                  tail->next = l1;
                  l1 = l1->next;
              }
              else {
                  tail->next = l2;
                  l2 = l2->next;
              }
              tail = tail->next;
          }
          if (l1)
              tail->next = l1;
          else
              tail->next = l2;
          return dummy->next;

      }
      ListNode* sortList(ListNode* head) {
          if (!head || !head->next)
              return head;

          ListNode* slow = head;
          ListNode* fast = head->next;
          while (fast && fast->next) {
              fast = fast->next->next;
              slow = slow->next;
          }
          ListNode* mid = slow->next;;
          slow->next = nullptr;
          
          ListNode* left = sortList(head);
          ListNode* right = sortList(mid);
          return merge(left, right);

      }
  };

