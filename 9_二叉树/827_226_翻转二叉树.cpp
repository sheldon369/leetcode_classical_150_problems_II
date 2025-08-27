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

//����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
//��������ת��������������ÿ���������Һ���

class Solution {
public:
    void invertTree1(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);


    }
    TreeNode* invertTree(TreeNode* root) {
        invertTree1(root);
        return root;
    }
};