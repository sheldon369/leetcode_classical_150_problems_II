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

//����һ��������, �ҵ�����������ָ���ڵ������������ȡ�
//������ƶ����ֶδ���ÿ�����ĸ��ڵ㣬����Եõ��Ӹý�㵽���ڵ��·�����ȶԼ��ɵõ���������
//����������������У����� �ṹ��̶����������Ϣʹ�ù�ϣ��洢

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

//�Ż���������Ҫ������ջ��ֻ��Ҫ��¼��p�������ʹ��Ľ�㣬q���Ϸ���ʱ������׸��Ѿ����ʹ��Ľ�㼴��