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

//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
//我们设计额外字段储存每个结点的父节点，便可以得到从该结点到根节点的路径，比对即可得到公共祖先
//问题是在这个问题中，树的 结构体固定，则额外信息使用哈希表存储

class Solution {
private:
    map<TreeNode*, TreeNode*> parent;
public:
    void preOrder(TreeNode* root) {
        if (!root)
            return;
        parent[root->left] = root;
        parent[root->right] = root;
        preOrder(root->left);
        preOrder(root->right);
     }
    stack<TreeNode*> getRoute(TreeNode* p) {
        stack<TreeNode*> st;
        while (p) {
            st.push(p);
            p = parent[p];
        }
        return st;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = nullptr;
        preOrder(root);
        stack<TreeNode*> stP = getRoute(p);
        stack<TreeNode*> stQ = getRoute(q);
        TreeNode* ans;
        while (stP.size() && stQ.size()&& stP.top() == stQ.top()) {
            ans = stP.top();
            stP.pop();
            stQ.pop();
        }
        return ans;


    }
};

//优化：并不需要构建出栈，只需要记录从p到根访问过的结点，q向上访问时，输出首个已经访问过的结点即可