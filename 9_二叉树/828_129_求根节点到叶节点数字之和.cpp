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

//����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
//ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�
//���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��
//����Ӹ��ڵ㵽Ҷ�ڵ����ɵ� ��������֮�� ��

//����������828_112_·���ܺͣ������ǽ������ֵķ�ʽ��ͬ
class Solution {
private:
    int sumition{};
public:
    void PreOrder(TreeNode* proot, int sum) {//�������
        if (proot == NULL) {//�������ս��ͷ��أ�����һ�����ֻ���Һ��ӣ���������ӻ�������ֵ����������
            return;
        }
        else {
            int new_sum = 10 * sum + proot->val;
            if (!proot->left && !proot->right)
                sumition += new_sum;
            PreOrder(proot->left, new_sum);
            PreOrder(proot->right, new_sum);
        }

    }
    int sumNumbers(TreeNode* root) {
        sumition = 0;
        PreOrder(root, 0);
        return sumition;

    }
};