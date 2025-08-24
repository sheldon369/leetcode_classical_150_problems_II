#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

// 给你一个链表的头节点 head ，判断链表中是否有环。
// 解1：快慢指针法，快指针一次移动2步，慢指针一次移动1步，若在慢指针到达结尾前二者相遇则存在环
// 解2：哈希表标记节点是否被访问过


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;  // 存指针
        ListNode* n = head;
        while (n != nullptr) {//判断当前指针是否为空
            if (s.count(n))  // 如果指针已经出现过
                return true;
            s.insert(n);
            n = n->next;
        }
        return false;
    }
};