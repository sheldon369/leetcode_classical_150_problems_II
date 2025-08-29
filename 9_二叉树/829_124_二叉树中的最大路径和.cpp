#include <string>
#include <map>
#include <unordered_map>
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

//二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
//路径和 是路径中各节点值的总和。
//给你一个二叉树的根节点 root ，返回其 最大路径和 。


//分析：最终形成的路径仍具有树形结构，根结点可以加入左右两棵子树的值，否则非根结点只能上供较大的子树值

class Solution {
private:
    /*unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> isVisited;*/
    int ans = INT_MIN;
public:
    //TreeNode* findLeaf(TreeNode* root) {//找到树最左边的叶结点
    //    TreeNode* p = root;
    //    while (1) {
    //        if (!p->left && !p->right)
    //            break;
    //        else if (!p->left)
    //            p = p->right;
    //        else
    //            p = p->left;

    //    }
    //    return p;
    //}
    int preOrder(TreeNode* root) {
        if (!root)
            return 0;
        ans = max(ans, root->val);//单独考虑该值
        int left = max(0, preOrder(root->left));//左侧贡献，若贡献为负不如不贡献
        int right = max(0, preOrder(root->right));
        int sum = root->val + left + right;
        ans = max(ans, sum);
        return root->val + max(left,right);//非根结点只能取一侧贡献
     
    }
    //void visitNext(TreeNode* p,int sum) {//保证p非空
    //    int newSum = (sum <= 0) ? p->val : (p->val + sum);
    //    ans = max(ans, newSum);
    //    isVisited[p] = 1;
    //    if (parent[p] && isVisited[parent[p]] == 0)
    //        visitNext(parent[p], newSum);
    //    if (p->left && isVisited[p->left] == 0) {
    //        visitNext(p->left, newSum);
    //    }
    //    if (p->right && isVisited[p->right] == 0) {
    //        visitNext(p->right, newSum);
    //    }

    //}



    int maxPathSum(TreeNode* root) {
        preOrder(root);
        return ans;
  
    }
};