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

//给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

//分析：使用中序 + 先序/后序/层序 遍历可唯一确定一棵树
//或者我们对两棵树采用相同的先序遍历，每次访问根节点都做比对


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)//两边同时遍历到空节点
            return true;
        else if (p == nullptr || q == nullptr)//只有一个是空节点，必然不相同
            return false;
        else if (p->val != q->val)//两个节点都有值，不同则必然不同
            return false;
        else //当前节点的比对无误，继续比较子节点
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};
