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

//给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

//分析：深拷贝参考825_138_随机链表的复制，我们使用unordered_map建立新老结点的对应关系,
//同时需要一个额外的映射保证元素单次访问

//DFS通常使用递归实现，BFS则一般得借助队列，每次访问到一个新节点，将他所有邻居加入到队列中
//改进：我们可以用一次DFS实现，将DFS的返回值设为Node*

class Solution {
private:
    unordered_map<Node*, Node*> mp;
    unordered_set<Node*> isVisited;
public:
    void DFS_1(Node* node) {//第一遍先建立新老结点的一一对应关系
        Node* p = new Node(node->val);
        mp[node] = p;
        isVisited.insert(node);
        for (auto neighbour : node->neighbors) {
            if (!isVisited.count(neighbour))
                DFS_1(neighbour);
        }
    }
    void DFS(Node* node) {//第二遍重新建立邻居关系
        Node* p = mp[node];
        isVisited.insert(node);
        for (auto neighbour : node->neighbors) {
            p->neighbors.push_back(mp[neighbour]);
            if (!isVisited.count(neighbour))
                DFS(neighbour);
        }
    }
    //改进：我们可以用一次DFS实现，将DFS的返回值设为Node*
    Node* dfs(Node* node) {
        if (!node) return nullptr;
        if (mp.count(node)) return mp[node];

        // 首次访问
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for (auto neighbour : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbour));
        }
        return clone;
    }


    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;//必要的防止空指针,其实这句应该封装在dfs中
        isVisited.clear();
        DFS_1(node);
        isVisited.clear();
        DFS(node);
        return mp[node];

    }
};