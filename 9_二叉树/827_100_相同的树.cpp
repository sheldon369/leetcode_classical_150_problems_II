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

//�������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
//����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�

//������ʹ������ + ����/����/���� ������Ψһȷ��һ����
//�������Ƕ�������������ͬ�����������ÿ�η��ʸ��ڵ㶼���ȶ�


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)//����ͬʱ�������սڵ�
            return true;
        else if (p == nullptr || q == nullptr)//ֻ��һ���ǿսڵ㣬��Ȼ����ͬ
            return false;
        else if (p->val != q->val)//�����ڵ㶼��ֵ����ͬ���Ȼ��ͬ
            return false;
        else //��ǰ�ڵ�ıȶ����󣬼����Ƚ��ӽڵ�
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};
