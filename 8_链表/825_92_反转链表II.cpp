#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。

//分析：使用计数器访问指定位置的节点
//解1：使用哈希表记录相应位置的前驱关系，并且设计指针pre，suc记录反转区间以外的前驱后继
//解2（更优）：当到达反转区间后，每次碰到一个新的元素，使用头插法

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : val(0), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);//哨兵指针
        dummy.next = head;
        ListNode* pre = &dummy;

        int curPos{ 1 };
  
        ListNode* pos = head;
        while (curPos < left) {//若left = 1，则不进入循环，则p pre均为空结点。故需要设计哨兵结点dummy
            pre = pos;//前驱结点
            curPos++;
            pos = pos->next;
        }
        ListNode* p = pre->next;//若p为head，则算法结尾p为尾结点，访问head不能得到整个链表
        for (int i = 0;i < right - left;i++) {
            ListNode* next = p->next;
            ListNode* second = pre->next;
            p->next = next->next;
            pre->next = next;
            next->next = second;
        }
        
        return dummy.next;//不能return head，因为若left为1，则head为工作结点，最终会被移到末尾
        //因此我们以哨兵结点，即头节点的前一结点为所有情况的pre，头插法均插入pre后面
           

    }
};
// 打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
// 构建测试链表
ListNode* buildList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// 测试函数
int main() {
    Solution sol;

    // 构建链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = buildList({ 1, 2, 3, 4, 5 });
    cout << "原链表: ";
    printList(head);

    // 反转 [2, 4]
    ListNode* newHead = sol.reverseBetween(head, 2, 4);
    cout << "反转 [2,4] 后: ";
    printList(newHead);

    // 再测试 [1,5]
    head = buildList({ 1, 2, 3, 4, 5 });
    newHead = sol.reverseBetween(head, 1, 5);
    cout << "反转 [1,5] 后: ";
    printList(newHead);

    return 0;
}