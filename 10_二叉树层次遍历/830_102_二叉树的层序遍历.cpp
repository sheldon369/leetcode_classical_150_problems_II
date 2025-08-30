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

//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        TreeNode* p = root;
        q.push({ root ,0 });
        pair<TreeNode*, int> pre{ nullptr,-1 };
        while (q.size()) {
            p = q.front().first;
            int curLevel = q.front().second;
            if (curLevel != pre.second) //p为当前层首个结点
                ans.push_back({p->val});
            else {//非首结点加入当前数组
                ans[curLevel].push_back(p->val);
            }
            if (p->left)
                q.push({ p->left ,curLevel + 1 });
            if (p->right)
                q.push({ p->right ,curLevel + 1 });
            //最后一个点总要单独输出
            
            pre = q.front();
            q.pop();

        }
        return ans;
    }
};
