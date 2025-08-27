#include <stdio.h>
#include <stack>
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

//给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//分析：翻转二叉树，即交换每个结点的左右孩子

class Solution {
public:
    void invertTree1(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);


    }
    TreeNode* invertTree(TreeNode* root) {
        invertTree1(root);
        return root;
    }
};