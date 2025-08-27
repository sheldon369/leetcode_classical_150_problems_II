#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct TreeNode {
	char data;
	TreeNode* left;//������ָ�롪���˴���֪TreeNode��С����֪����ָ���С��һ����ַ��
	TreeNode* right;
};
struct QueueNode {
	TreeNode* parent;
	bool isLeft;
};

void LevelOrder(TreeNode* proot) {//��ȱ���
	queue<TreeNode*> pos;
	pos.push(proot);
	while (pos.empty() == false) {
		TreeNode* pCur = pos.front();
		printf("%c", pCur->data);
		if (pCur->left != NULL) {
			pos.push(pCur->left);
		}
		if (pCur->right != NULL) {
			pos.push(pCur->right);
		}
	}
}

void PreOrder(TreeNode* proot) {//�������
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

void InOrder(TreeNode* proot) {//�������
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

void PostOrder(TreeNode* proot) {//�������
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

