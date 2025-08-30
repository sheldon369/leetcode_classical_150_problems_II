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

//给定一个非空二叉树的根节点 root, 以数组的形式返回每一层节点的平均值。与实际答案相差 10 - 5 以内的答案可以被接受。
//分析：可用层次遍历，但还是须判断是否在同一层次，也可先计算出每层的结点（先序遍历无需考虑顺序），再计算值
//关注到层次遍历有个比较好的性质，当上一层的结点全部访问完，队列中刚好为下一层的全部结点


class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root)
            return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({ root ,0 });
        int count{};
        double sum{};
        while (q.size()) {
            TreeNode*  p = q.front().first;
            int curLevel = q.front().second;
            count++;
            sum += p->val;
            if (p->left)
                q.push({ p->left ,curLevel + 1 });
            if (p->right)
                q.push({ p->right ,curLevel + 1 });
            q.pop();
            if (q.empty() || q.front().second != curLevel) {//p为本层最后一个结点
                ans.push_back(sum / count);
                sum = 0;
                count = 0;
            }

        }
        return ans;


    }
};