#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//构造这个链表的 深拷贝。 
//深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

//分析：生成当前节点时，random节点可能还没有建立。
//第一遍顺序建立链表，并且使用哈希表存储新老节点的对应关系（否则我们难以找到新的链表结点，我们并没有访问它的特征元素）
//第二遍写入random字段

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
        while (p) {//创建好新节点
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