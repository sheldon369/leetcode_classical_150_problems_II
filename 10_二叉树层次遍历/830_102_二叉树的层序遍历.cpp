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

//����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��
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
            if (curLevel != pre.second) //pΪ��ǰ���׸����
                ans.push_back({p->val});
            else {//���׽����뵱ǰ����
                ans[curLevel].push_back(p->val);
            }
            if (p->left)
                q.push({ p->left ,curLevel + 1 });
            if (p->right)
                q.push({ p->right ,curLevel + 1 });
            //���һ������Ҫ�������
            
            pre = q.front();
            q.pop();

        }
        return ans;
    }
};
