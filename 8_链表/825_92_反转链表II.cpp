#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//���㵥�����ͷָ�� head ���������� left �� right ������ left <= right ��
//���㷴ת��λ�� left ��λ�� right ������ڵ㣬���� ��ת������� ��

//������ʹ�ü���������ָ��λ�õĽڵ�
//��1��ʹ�ù�ϣ���¼��Ӧλ�õ�ǰ����ϵ���������ָ��pre��suc��¼��ת���������ǰ�����
//��2�����ţ��������ﷴת�����ÿ������һ���µ�Ԫ�أ�ʹ��ͷ�巨

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

        ListNode dummy(0);//�ڱ�ָ��
        dummy.next = head;
        ListNode* pre = &dummy;

        int curPos{ 1 };
  
        ListNode* pos = head;
        while (curPos < left) {//��left = 1���򲻽���ѭ������p pre��Ϊ�ս�㡣����Ҫ����ڱ����dummy
            pre = pos;//ǰ�����
            curPos++;
            pos = pos->next;
        }
        ListNode* p = pre->next;//��pΪhead�����㷨��βpΪβ��㣬����head���ܵõ���������
        for (int i = 0;i < right - left;i++) {
            ListNode* next = p->next;
            ListNode* second = pre->next;
            p->next = next->next;
            pre->next = next;
            next->next = second;
        }
        
        return dummy.next;//����return head����Ϊ��leftΪ1����headΪ������㣬���ջᱻ�Ƶ�ĩβ
        //����������ڱ���㣬��ͷ�ڵ��ǰһ���Ϊ���������pre��ͷ�巨������pre����
           

    }
};
// ��ӡ����
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
// ������������
ListNode* buildList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// ���Ժ���
int main() {
    Solution sol;

    // ��������: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = buildList({ 1, 2, 3, 4, 5 });
    cout << "ԭ����: ";
    printList(head);

    // ��ת [2, 4]
    ListNode* newHead = sol.reverseBetween(head, 2, 4);
    cout << "��ת [2,4] ��: ";
    printList(newHead);

    // �ٲ��� [1,5]
    head = buildList({ 1, 2, 3, 4, 5 });
    newHead = sol.reverseBetween(head, 1, 5);
    cout << "��ת [1,5] ��: ";
    printList(newHead);

    return 0;
}