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

//给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
//有效 二叉搜索树定义如下：
//节点的左子树只包含 严格小于 当前节点的数。
//节点的右子树只包含 严格大于 当前节点的数。
//所有左子树和右子树自身必须也是二叉搜索树。

//分析：中序遍历元素递增即可

class Solution {
private:
    long pre = LONG_MIN;
public:
    
    bool isValidBST(TreeNode* root) {
        if (!root  )
            return true;
        bool left = isValidBST(root->left);
        bool cur = root->val > pre;
        pre = root->val;
        bool right = isValidBST(root->right);
        return left && cur && right;

    }
};