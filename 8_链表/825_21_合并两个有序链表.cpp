#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
using namespace std;

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//分析：解一（迭代）使用824_2_两数相加类似的while语句控制循环
//解二（递归）：使用递归算法递归调用mergeTwoLists，该函数总是返回指向某特定节点的指针，
//当存在一个指针空指时，令递归中止，则此时指向关系已经逐层构建好
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