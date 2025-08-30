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

//给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
//分析：层次遍历，取每层最后一个结点

class Solution {
public:
 


    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*,int>> q;
        TreeNode* p = root;
        q.push({ root ,0});
        pair<TreeNode*, int> pre{ nullptr,0 };
        while (q.size()) {
            p = q.front().first;
            int curLevel = q.front().second;
            if (curLevel != pre.second) //pre为上一层末尾
                ans.push_back(pre.first->val);
            if (p->left)
                q.push({ p->left ,curLevel + 1 });
            if (p->right)
                q.push({ p->right ,curLevel + 1 });
            //最后一个点总要单独输出
            if(q.size() == 1 )
                ans.push_back(p->val);
            pre = q.front();
            q.pop();
          
        }
        return ans;
   



    }
};