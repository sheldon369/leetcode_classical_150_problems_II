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

//给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
//参考827_105，区别是更改数组索引以及中间结点构造方式
//inorder:[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
//postorder:[ [左子树的中序遍历结果], [右子树的中序遍历结果],根节点 ]

class Solution {
private:
	unordered_map<int, int> index;//index存放inorder，键为inorder[i],值为索引[i]
public:
	TreeNode* Rebuild(const vector<int>& postorder, vector<int>& inorder, int post_begin, int post_end, int in_begin, int in_end) {
		if (post_begin > post_end) {//当前子树为空
			return nullptr;
		}
		else {
			TreeNode* pNew = new TreeNode(postorder[post_end]);

			int pos = index[postorder[post_end]];
			int lengthOfLeft = pos - in_begin;//inorder序列的长度

			pNew->left = Rebuild(postorder, inorder, post_begin, post_begin + lengthOfLeft - 1, in_begin, pos - 1);
			pNew->right = Rebuild(postorder, inorder, post_begin + lengthOfLeft, post_end - 1, pos + 1, in_end);
			return pNew;
		}
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		for (int i = 0;i < n;i++) {
			index[inorder[i]] = i;
		}
		return Rebuild(postorder, inorder, 0, n - 1, 0, n - 1);

	}
};