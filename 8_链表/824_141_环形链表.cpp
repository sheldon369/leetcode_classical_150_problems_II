#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

// ����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
// ��1������ָ�뷨����ָ��һ���ƶ�2������ָ��һ���ƶ�1����������ָ�뵽���βǰ������������ڻ�
// ��2����ϣ���ǽڵ��Ƿ񱻷��ʹ�


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
  
 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;  // ��ָ��
        ListNode* n = head;
        while (n != nullptr) {//�жϵ�ǰָ���Ƿ�Ϊ��
            if (s.count(n))  // ���ָ���Ѿ����ֹ�
                return true;
            s.insert(n);
            n = n->next;
        }
        return false;
    }
};