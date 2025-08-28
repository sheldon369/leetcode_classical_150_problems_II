#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
#include <queue>
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

//给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
//每条从根节点到叶节点的路径都代表一个数字：
//例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
//计算从根节点到叶节点生成的 所有数字之和 。

//分析：类似828_112_路径总和，区别是解析数字的方式不同
class Solution {
private:
    int sumition{};
public:
    void PreOrder(TreeNode* proot, int sum) {//先序遍历
        if (proot == NULL) {//若碰到空结点就返回，假设一个结点只有右孩子，则进入左孩子还会加入该值，出现问题
            return;
        }
        else {
            int new_sum = 10 * sum + proot->val;
            if (!proot->left && !proot->right)
                sumition += new_sum;
            PreOrder(proot->left, new_sum);
            PreOrder(proot->right, new_sum);
        }

    }
    int sumNumbers(TreeNode* root) {
        sumition = 0;
        PreOrder(root, 0);
        return sumition;

    }
};