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

//给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 小的元素（从 1 开始计数）。
//分析：第k小的元素即中序遍历第k个结点

class Solution {
private:
    int count{};
    int ans;
public:
    void Inorder(TreeNode* p,int k) {
        if (!p)
            return;
        Inorder(p->left,k);
        count++;
        if (count == k) {
            ans = p->val;
            return;
        }
        Inorder(p->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        Inorder(root, k);
        return ans;
    }
};

