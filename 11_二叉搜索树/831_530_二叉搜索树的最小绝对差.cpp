#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
//差值是一个正数，其数值等于两值之差的绝对值。

//分析：二叉搜索树中序遍历为升序，最小差值必然在连续的两点内产生
class Solution {
private:
    int ans{100000};//关注到使用INT_MAX时，该值不能参与后序的任何运算，否则会超范围
    int pre = -100001;
public:
    void Inorder(TreeNode* p) {
        if (!p)
            return;
        Inorder(p->left);
        int newDif = p->val - pre;
        ans = min(newDif, ans);
        pre = p->val;
        Inorder(p->right);
    }

    int getMinimumDifference(TreeNode* root) {
        Inorder(root);
        return ans;
    }
};

//优化：二叉搜索树对于任何一个根而言，左子树所有元素<根<右子树所有元素，故必然没有重复元素
//则最小绝对差必然大于等于1，若ans在某一刻等于1，可以提前剪枝
