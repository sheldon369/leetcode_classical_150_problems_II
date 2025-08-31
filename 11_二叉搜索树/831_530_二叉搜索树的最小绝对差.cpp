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

//����һ�������������ĸ��ڵ� root ������ ������������ͬ�ڵ�ֵ֮�����С��ֵ ��
//��ֵ��һ������������ֵ������ֵ֮��ľ���ֵ��

//�����������������������Ϊ������С��ֵ��Ȼ�������������ڲ���
class Solution {
private:
    int ans{100000};//��ע��ʹ��INT_MAXʱ����ֵ���ܲ��������κ����㣬����ᳬ��Χ
    int pre = -100001;
public:
    void Inorder(TreeNode* p) {
        if (!p)
            return;
        Inorder(p->left);
        int newDif = p->val - pre;
        ans = min(newDif, ans);
        pre = p->val;
        Inorder(p->right);
    }

    int getMinimumDifference(TreeNode* root) {
        Inorder(root);
        return ans;
    }
};

//�Ż������������������κ�һ�������ԣ�����������Ԫ��<��<����������Ԫ�أ��ʱ�Ȼû���ظ�Ԫ��
//����С���Բ��Ȼ���ڵ���1����ans��ĳһ�̵���1��������ǰ��֦
