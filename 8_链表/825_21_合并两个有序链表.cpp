#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//��������һ��������ʹ��824_2_����������Ƶ�while������ѭ��
//������ݹ飩��ʹ�õݹ��㷨�ݹ����mergeTwoLists���ú������Ƿ���ָ��ĳ�ض��ڵ��ָ�룬
//������һ��ָ���ָʱ����ݹ���ֹ�����ʱָ���ϵ�Ѿ���㹹����
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) 
            return list2;
        else if (list2 == nullptr)
            return list1;
        else {
            if (list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            }
            else {
                list2->next = mergeTwoLists(list2->next, list1);
                return list2;
            }
        }
    }
};