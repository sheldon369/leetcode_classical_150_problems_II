#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//给你二叉树的根结点 root ，请你将它展开为一个单链表：
//展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
//展开后的单链表应该与二叉树 先序遍历 顺序相同。


class Solution {
private:
	TreeNode* pre = new TreeNode();
public:
	void PreOrder(TreeNode* proot) {//先序遍历
		if (proot == NULL) {
			return;
		}
		else {
			
			TreeNode* left = proot->left;
			TreeNode* right = proot->right;
			pre->left = nullptr;
			pre->right = proot;
			pre = proot;

	
			PreOrder(left);
			PreOrder(right);
			printf("\n"); 
		}

	}

    void flatten(TreeNode* root) {
		PreOrder(root);
		

    }
};