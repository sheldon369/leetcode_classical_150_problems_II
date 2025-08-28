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

//����������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL ��
//��ʼ״̬�£����� next ָ�붼������Ϊ NULL ��

//��������α�����ͬʱ����ֶα��浱ǰ���Ĳ����Ϣ


class Solution {


public:
	
    Node* connect(Node* root) {
		queue < pair<Node*, int> > pos;
		pair<Node*, int> pre{ nullptr,-1 };
		if (!root)
			return root;
		pos.push({ root,0 });
		while (pos.empty() == false) {//Ӧ���ȷ���ǰһ��Ԫ�أ���Ϊ��ȷ�����ڣ���ƶ�������洢��Ԫ�ؼ���
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