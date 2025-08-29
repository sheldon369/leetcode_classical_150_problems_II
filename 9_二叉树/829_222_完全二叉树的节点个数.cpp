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

//����һ�� ��ȫ������ �ĸ��ڵ� root ����������Ľڵ������
//��������1��������ͳ�ƽ�������O��n��
//��2����ȫ��������Ϊh����h-1���Ȼ�����ģ��Ե�h�㣬���ж��ֲ��ң��ҳ�ȷ�а����Ľ��������O��h^2��
//��3����ȫ�������������б�Ȼ������������������������� = ����������ȣ�������һ��������Ȼ������ȫ������

class Solution {
public:
    int countDepthL(TreeNode* root) {
        int i = 0;
        while (root) {
            i++;
            root = root->left;
        }
        return i;
    }
    int countDepthR(TreeNode* root) {
        int i = 0;
        while (root) {
            i++;
            root = root->right;
        }
        return i;
    }
    int countNodes(TreeNode* root) {
        if (countDepthL(root) == countDepthR(root))//��������
            return pow(2, countDepthL(root)) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);//��������ȫ����������ȫ��������һ�������ֱ�Ȼ����������

    }
};