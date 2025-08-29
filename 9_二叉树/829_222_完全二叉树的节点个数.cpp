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

//给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
//分析：解1：遍历树统计结点个数，O（n）
//解2：完全二叉树高为h，第h-1层必然是满的，对第h层，进行二分查找，找出确切包含的结点数量，O（h^2）
//解3：完全二叉树的子树中必然存在满二叉树（左子树的深度 = 右子树的深度），且另一颗子树必然还是完全二叉树

class Solution {
public:
    int countDepthL(TreeNode* root) {
        int i = 0;
        while (root) {
            i++;
            root = root->left;
        }
        return i;
    }
    int countDepthR(TreeNode* root) {
        int i = 0;
        while (root) {
            i++;
            root = root->right;
        }
        return i;
    }
    int countNodes(TreeNode* root) {
        if (countDepthL(root) == countDepthR(root))//满二叉树
            return pow(2, countDepthL(root)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);//否则是完全二叉树，完全二叉树的一个子树又必然是满二叉树

    }
};