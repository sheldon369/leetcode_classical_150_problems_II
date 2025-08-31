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

//����һ�������������ĸ��ڵ� root ����һ������ k ���������һ���㷨�������е� k С��Ԫ�أ��� 1 ��ʼ��������
//��������kС��Ԫ�ؼ����������k�����

class Solution {
private:
    int count{};
    int ans;
public:
    void Inorder(TreeNode* p,int k) {
        if (!p)
            return;
        Inorder(p->left,k);
        count++;
        if (count == k) {
            ans = p->val;
            return;
        }
        Inorder(p->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        Inorder(root, k);
        return ans;
    }
};

