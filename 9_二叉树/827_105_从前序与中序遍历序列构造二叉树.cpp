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

//���������������� preorder �� inorder ������ preorder �Ƕ���������������� inorder ��ͬһ����������������빹�����������������ڵ㡣
//������
//preorder:[���ڵ�, [��������ǰ��������], [��������ǰ��������]]
//inorder:[ [������������������], ���ڵ�, [������������������] ]
//�ؼ����ڶ�λʹ�õ�������,�Ҷ�������һ�����������������������еı���������ͬ
//��ͬ�����������еĴ�д��������ʹ������������λָ��λ�õ������鴮

class Solution {
private:
    unordered_map<int, int> index;//index���inorder����Ϊinorder[i],ֵΪ����[i]
public:
	TreeNode* Rebuild(const vector<int>& preorder, vector<int>& inorder,int pre_begin,int pre_end,int in_begin,int in_end) {
		if (pre_begin > pre_end) {//��ǰ����Ϊ��
			return nullptr;
		}
		else {
			TreeNode* pNew = new TreeNode(preorder[pre_begin]);
		
			int pos = index[preorder[pre_begin]];
			int lengthOfLeft = pos - in_begin;//inorder���еĳ���

			pNew->left = Rebuild(preorder, inorder,pre_begin+1,pre_begin + lengthOfLeft,in_begin,pos-1);
			pNew->right = Rebuild(preorder, inorder, pre_begin + lengthOfLeft + 1, pre_end, pos+1, in_end);
			return pNew;
		}
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = inorder.size();
		for (int i = 0;i < n;i++) {
			index[inorder[i]] = i;
		}
		return Rebuild(preorder, preorder, 0, n-1, 0, n-1);

    }
};