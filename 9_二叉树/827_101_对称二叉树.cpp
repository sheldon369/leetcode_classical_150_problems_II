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

//给你一个二叉树的根节点 root ， 检查它是否轴对称。
//分析：即判断 根结点的左子树 翻转过后是否和右子树完全相同，结合827_100_相同的树，827_226_翻转二叉树
//本解法将二者结合起来，在判别时总是比较对称位置的元素

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {//希望调成两个参数，故设计一个额外函数
        if (p == nullptr && q == nullptr)//两边同时遍历到空节点
            return true;
        else if (p == nullptr || q == nullptr)//只有一个是空节点，必然不相同
            return false;
        else if (p->val != q->val)//两个节点都有值，不同则必然不同
            return false;
        else //当前节点的比对无误，继续比较子节点
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);

    }

    bool isSymmetric(TreeNode* root) {
    
        return isSameTree(root->left, root->right);


    }
};