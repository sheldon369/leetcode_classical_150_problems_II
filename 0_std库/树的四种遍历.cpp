#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;//必须用指针——此处不知TreeNode大小，而知道其指针大小（一个地址）
	TreeNode* right;
};
struct QueueNode {
	TreeNode* parent;
	bool isLeft;
};

void LevelOrder(TreeNode* proot) {//层次遍历
	if (!proot)//若root为空，无法访问内部字段left，right
		return;
	queue<TreeNode*> pos;
	pos.push(proot);
	while (!pos.empty()) {
		TreeNode* pCur = pos.front();
		printf("%c", pCur->data);
		pos.pop();
		if (pCur->left) {
			pos.push(pCur->left);
		}
		if (pCur->right) {
			pos.push(pCur->right);
		}
	}
}

void BFS(TreeNode* proot) {//带当前层次的层次遍历
	if (!proot)//若root为空，无法访问内部字段left，right
		return;
	queue<pair<TreeNode*,int>> pos;
	pos.push({ proot , 0 });
	while (!pos.empty()) {
		TreeNode* pCur = pos.front().first;
		int lCur = pos.front().second;
		printf("%c", pCur->data);
		
		if (pCur->left) {
			pos.push({ pCur->left,lCur + 1 });
		}
		if (pCur->right) {
			pos.push({ pCur->right,lCur + 1 });
		}
		pos.pop();
	}
}

void PreOrder(TreeNode* proot) {//先序遍历
	if (proot == NULL) {
		return;
	}
	else {
		printf("%c", proot->data);
		PreOrder(proot->left);
		PreOrder(proot->right);
		printf("\n");
	}

}

void InOrder(TreeNode* proot) {//中序遍历
	if (proot == NULL) {
		return;
	}
	else {
		InOrder(proot->left);
		printf("%c", proot->data);
		InOrder(proot->right);
		printf("\n");
	}

}

void PostOrder(TreeNode* proot) {//后序遍历
	if (proot == NULL) {
		return;
	}
	else {
		PostOrder(proot->left);
		PostOrder(proot->right);
		printf("%c", proot->data);
		printf("\n");
	}

}

