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

//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
//分析：
//preorder:[根节点, [左子树的前序遍历结果], [右子树的前序遍历结果]]
//inorder:[ [左子树的中序遍历结果], 根节点, [右子树的中序遍历结果] ]
//关键在于定位使用到的数组,且对于任意一组遍历结果，都必有两周序列的遍历长度相同
//不同于王道机试中的串写法，这里使用数组索引定位指定位置的子数组串

class Solution {
private:
    unordered_map<int, int> index;//index存放inorder，键为inorder[i],值为索引[i]
public:
	TreeNode* Rebuild(const vector<int>& preorder, vector<int>& inorder,int pre_begin,int pre_end,int in_begin,int in_end) {
		if (pre_begin > pre_end) {//当前子树为空
			return nullptr;
		}
		else {
			TreeNode* pNew = new TreeNode(preorder[pre_begin]);
		
			int pos = index[preorder[pre_begin]];
			int lengthOfLeft = pos - in_begin;//inorder序列的长度

			pNew->left = Rebuild(preorder, inorder,pre_begin+1,pre_begin + lengthOfLeft,in_begin,pos-1);
			pNew->right = Rebuild(preorder, inorder, pre_begin + lengthOfLeft + 1, pre_end, pos+1, in_end);
			return pNew;
		}
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
		for (int i = 0;i < n;i++) {
			index[inorder[i]] = i;
		}
		return Rebuild(preorder, preorder, 0, n-1, 0, n-1);

    }
};