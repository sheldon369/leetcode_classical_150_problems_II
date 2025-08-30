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

//����һ���ǿն������ĸ��ڵ� root, ���������ʽ����ÿһ��ڵ��ƽ��ֵ����ʵ�ʴ���� 10 - 5 ���ڵĴ𰸿��Ա����ܡ�
//���������ò�α��������������ж��Ƿ���ͬһ��Σ�Ҳ���ȼ����ÿ��Ľ�㣨����������迼��˳�򣩣��ټ���ֵ
//��ע����α����и��ȽϺõ����ʣ�����һ��Ľ��ȫ�������꣬�����иպ�Ϊ��һ���ȫ�����


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
            if (q.empty() || q.front().second != curLevel) {//pΪ�������һ�����
                ans.push_back(sum / count);
                sum = 0;
                count = 0;
            }

        }
        return ans;


    }
};