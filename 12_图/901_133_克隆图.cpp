#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����

//����������ο�825_138_�������ĸ��ƣ�����ʹ��unordered_map�������Ͻ��Ķ�Ӧ��ϵ,
//ͬʱ��Ҫһ�������ӳ�䱣֤Ԫ�ص��η���

//DFSͨ��ʹ�õݹ�ʵ�֣�BFS��һ��ý������У�ÿ�η��ʵ�һ���½ڵ㣬���������ھӼ��뵽������
//�Ľ������ǿ�����һ��DFSʵ�֣���DFS�ķ���ֵ��ΪNode*

class Solution {
private:
    unordered_map<Node*, Node*> mp;
    unordered_set<Node*> isVisited;
public:
    void DFS_1(Node* node) {//��һ���Ƚ������Ͻ���һһ��Ӧ��ϵ
        Node* p = new Node(node->val);
        mp[node] = p;
        isVisited.insert(node);
        for (auto neighbour : node->neighbors) {
            if (!isVisited.count(neighbour))
                DFS_1(neighbour);
        }
    }
    void DFS(Node* node) {//�ڶ������½����ھӹ�ϵ
        Node* p = mp[node];
        isVisited.insert(node);
        for (auto neighbour : node->neighbors) {
            p->neighbors.push_back(mp[neighbour]);
            if (!isVisited.count(neighbour))
                DFS(neighbour);
        }
    }
    //�Ľ������ǿ�����һ��DFSʵ�֣���DFS�ķ���ֵ��ΪNode*
    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];

        // �״η���
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for (auto neighbour : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbour));
        }
        return clone;
    }


    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;//��Ҫ�ķ�ֹ��ָ��,��ʵ���Ӧ�÷�װ��dfs��
        isVisited.clear();
        DFS_1(node);
        isVisited.clear();
        DFS(node);
        return mp[node];

    }
};