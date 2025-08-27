#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
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

//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
//���������ж� ������������ ��ת�����Ƿ����������ȫ��ͬ�����827_100_��ͬ������827_226_��ת������
//���ⷨ�����߽�����������б�ʱ���ǱȽ϶Գ�λ�õ�Ԫ��

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {//ϣ���������������������һ�����⺯��
        if (p == nullptr && q == nullptr)//����ͬʱ�������սڵ�
            return true;
        else if (p == nullptr || q == nullptr)//ֻ��һ���ǿսڵ㣬��Ȼ����ͬ
            return false;
        else if (p->val != q->val)//�����ڵ㶼��ֵ����ͬ���Ȼ��ͬ
            return false;
        else //��ǰ�ڵ�ıȶ����󣬼����Ƚ��ӽڵ�
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);

    }

    bool isSymmetric(TreeNode* root) {
    
        return isSameTree(root->left, root->right);


    }
};