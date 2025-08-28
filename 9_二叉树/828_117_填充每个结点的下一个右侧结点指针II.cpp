#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//填充二叉树的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL 。
//初始状态下，所有 next 指针都被设置为 NULL 。

//分析：层次遍历，同时设计字段保存当前结点的层次信息


class Solution {


public:
	
    Node* connect(Node* root) {
		queue < pair<Node*, int> > pos;
		pair<Node*, int> pre{ nullptr,-1 };
		if (!root)
			return root;
		pos.push({ root,0 });
		while (pos.empty() == false) {//应优先访问前一个元素，因为它确定存在，设计额外变量存储该元素即可
			Node* pCur = pos.front().first;
			int cur_depth = pos.front().second;
			Node* pPre = pre.first;
			int pre_depth = pre.second;
			pre = pos.front();
			pos.pop();

			if (cur_depth == pre_depth)
				pPre->next = pCur;

			if (pCur->left != nullptr) {
				pos.push({ pCur->left, cur_depth + 1 });
			}
			if (pCur->right != nullptr) {
				pos.push({ pCur->right, cur_depth + 1 });
			}
		}
		return root;
    }
};