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

//ʵ��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������
//BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����
//
// ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�
//boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��
//int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�
// 
//ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�
//����Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�

class BSTIterator {
private:
    vector<int> inOrder;
    int index{ 0 };
public:
    void inOrderTree(TreeNode* root) {
        if (!root)
            return;
        inOrderTree(root->left);
        inOrder.push_back(root->val);
        inOrderTree(root->right);
    }




    BSTIterator(TreeNode* root) {
        inOrder.push_back(-1);
        inOrderTree(root);
    }

    int next() {
        index++;
        return inOrder[index];
    }

    bool hasNext() {
        return inOrder.size() > index + 1;
    }
};