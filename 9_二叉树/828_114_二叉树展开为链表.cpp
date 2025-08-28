#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
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

//����������ĸ���� root �����㽫��չ��Ϊһ��������
//չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
//չ����ĵ�����Ӧ��������� ������� ˳����ͬ��


class Solution {
private:
	TreeNode* pre = new TreeNode();
public:
	void PreOrder(TreeNode* proot) {//�������
		if (proot == NULL) {
			return;
		}
		else {
			
			TreeNode* left = proot->left;
			TreeNode* right = proot->right;
			pre->left = nullptr;
			pre->right = proot;
			pre = proot;

	
			PreOrder(left);
			PreOrder(right);
			printf("\n"); 
		}

	}

    void flatten(TreeNode* root) {
		PreOrder(root);
		

    }
};