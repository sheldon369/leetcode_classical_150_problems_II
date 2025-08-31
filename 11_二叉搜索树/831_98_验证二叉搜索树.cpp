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

//����һ���������ĸ��ڵ� root ���ж����Ƿ���һ����Ч�Ķ�����������
//��Ч �����������������£�
//�ڵ��������ֻ���� �ϸ�С�� ��ǰ�ڵ������
//�ڵ��������ֻ���� �ϸ���� ��ǰ�ڵ������
//�������������������������Ҳ�Ƕ�����������

//�������������Ԫ�ص�������

class Solution {
private:
    long pre = LONG_MIN;
public:
    
    bool isValidBST(TreeNode* root) {
        if (!root  )
            return true;
        bool left = isValidBST(root->left);
        bool cur = root->val > pre;
        pre = root->val;
        bool right = isValidBST(root->right);
        return left && cur && right;

    }
};