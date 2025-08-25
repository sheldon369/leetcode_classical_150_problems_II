#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//������������ ����� 
//���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
//�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬�����������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��

//���������ɵ�ǰ�ڵ�ʱ��random�ڵ���ܻ�û�н�����
//��һ��˳������������ʹ�ù�ϣ��洢���Ͻڵ�Ķ�Ӧ��ϵ���������������ҵ��µ������㣬���ǲ�û�з�����������Ԫ�أ�
//�ڶ���д��random�ֶ�

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        unordered_map<Node*, Node*> mp;
        while (p) {//�������½ڵ�
            Node* temp = new Node(p->val);
            mp[p] = temp;
            p = p->next;
        }
        p = head;
        while (p) {
            mp[p]->random = mp[p->random];
            mp[p]->next = mp[p->next];
            p = p->next;
        }
        return mp[head];

    }
};