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

//���������������� inorder �� postorder ������ inorder �Ƕ���������������� postorder ��ͬһ�����ĺ�����������㹹�첢������� ������ ��
//�ο�827_105�������Ǹ������������Լ��м��㹹�췽ʽ
//inorder:[ [������������������], ���ڵ�, [������������������] ]
//postorder:[ [������������������], [������������������],���ڵ� ]

class Solution {
private:
	unordered_map<int, int> index;//index���inorder����Ϊinorder[i],ֵΪ����[i]
public:
	TreeNode* Rebuild(const vector<int>& postorder, vector<int>& inorder, int post_begin, int post_end, int in_begin, int in_end) {
		if (post_begin > post_end) {//��ǰ����Ϊ��
			return nullptr;
		}
		else {
			TreeNode* pNew = new TreeNode(postorder[post_end]);

			int pos = index[postorder[post_end]];
			int lengthOfLeft = pos - in_begin;//inorder���еĳ���

			pNew->left = Rebuild(postorder, inorder, post_begin, post_begin + lengthOfLeft - 1, in_begin, pos - 1);
			pNew->right = Rebuild(postorder, inorder, post_begin + lengthOfLeft, post_end - 1, pos + 1, in_end);
			return pNew;
		}
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		for (int i = 0;i < n;i++) {
			index[inorder[i]] = i;
		}
		return Rebuild(postorder, inorder, 0, n - 1, 0, n - 1);

	}
};