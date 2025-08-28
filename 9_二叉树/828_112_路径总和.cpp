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

//����������ĸ��ڵ� root ��һ����ʾĿ��͵����� targetSum ���жϸ������Ƿ���� ���ڵ㵽Ҷ�ӽڵ� ��·��������·�������нڵ�ֵ��ӵ���Ŀ��� targetSum ��
//������ڣ����� true �����򣬷��� false ��

//������ʹ��set��¼���г��ֹ���·����

class Solution {
private:
    unordered_set<int> set;
public:
	void PreOrder(TreeNode* proot,int sum) {//�������
		if (proot == NULL) {//�������ս��ͷ��أ�����һ�����ֻ���Һ��ӣ���������ӻ�������ֵ����������
			return;
		}
		else {
			int new_sum = sum + proot->val;
			if (!proot->left && !proot->right)
				set.insert(new_sum);
			PreOrder(proot->left,new_sum);
			PreOrder(proot->right, new_sum);
		}

	}

    bool hasPathSum(TreeNode* root, int targetSum) {
		set.clear();
		PreOrder(root, 0);
		return set.count(targetSum);
    }

    //��2��ֱ��ʹ�øýӿ�
    bool hasPathSum2(TreeNode* root, int targetSum) {
        if (!root) return false;

        // �����Ҷ�ӽڵ㣬���·�����Ƿ���� targetSum
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // �ݹ�����������
        return hasPathSum(root->left, targetSum - root->val) ||
            hasPathSum(root->right, targetSum - root->val);
    }
};