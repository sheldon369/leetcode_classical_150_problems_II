#include <string>
#include <map>
#include <unordered_set>
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

//给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
//如果存在，返回 true ；否则，返回 false 。

//分析：使用set记录所有出现过的路径和

class Solution {
private:
    unordered_set<int> set;
public:
	void PreOrder(TreeNode* proot,int sum) {//先序遍历
		if (proot == NULL) {//若碰到空结点就返回，假设一个结点只有右孩子，则进入左孩子还会加入该值，出现问题
			return;
		}
		else {
			int new_sum = sum + proot->val;
			if (!proot->left && !proot->right)
				set.insert(new_sum);
			PreOrder(proot->left,new_sum);
			PreOrder(proot->right, new_sum);
		}

	}

    bool hasPathSum(TreeNode* root, int targetSum) {
		set.clear();
		PreOrder(root, 0);
		return set.count(targetSum);
    }

    //解2：直接使用该接口
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (!root) return false;

        // 如果到叶子节点，检查路径和是否等于 targetSum
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // 递归检查左右子树
        return hasPathSum(root->left, targetSum - root->val) ||
            hasPathSum(root->right, targetSum - root->val);
    }
};