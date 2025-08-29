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

//�������е� ·�� ������Ϊһ���ڵ����У�������ÿ�����ڽڵ�֮�䶼����һ���ߡ�ͬһ���ڵ���һ��·�������� �������һ�� ����·�� ���ٰ���һ�� �ڵ㣬�Ҳ�һ���������ڵ㡣
//·���� ��·���и��ڵ�ֵ���ܺ͡�
//����һ���������ĸ��ڵ� root �������� ���·���� ��


//�����������γɵ�·���Ծ������νṹ���������Լ�����������������ֵ������Ǹ����ֻ���Ϲ��ϴ������ֵ

class Solution {
private:
    /*unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> isVisited;*/
    int ans = INT_MIN;
public:
    //TreeNode* findLeaf(TreeNode* root) {//�ҵ�������ߵ�Ҷ���
    //    TreeNode* p = root;
    //    while (1) {
    //        if (!p->left && !p->right)
    //            break;
    //        else if (!p->left)
    //            p = p->right;
    //        else
    //            p = p->left;

    //    }
    //    return p;
    //}
    int preOrder(TreeNode* root) {
        if (!root)
            return 0;
        ans = max(ans, root->val);//�������Ǹ�ֵ
        int left = max(0, preOrder(root->left));//��๱�ף�������Ϊ�����粻����
        int right = max(0, preOrder(root->right));
        int sum = root->val + left + right;
        ans = max(ans, sum);
        return root->val + max(left,right);//�Ǹ����ֻ��ȡһ�๱��
     
    }
    //void visitNext(TreeNode* p,int sum) {//��֤p�ǿ�
    //    int newSum = (sum <= 0) ? p->val : (p->val + sum);
    //    ans = max(ans, newSum);
    //    isVisited[p] = 1;
    //    if (parent[p] && isVisited[parent[p]] == 0)
    //        visitNext(parent[p], newSum);
    //    if (p->left && isVisited[p->left] == 0) {
    //        visitNext(p->left, newSum);
    //    }
    //    if (p->right && isVisited[p->right] == 0) {
    //        visitNext(p->right, newSum);
    //    }

    //}



    int maxPathSum(TreeNode* root) {
        preOrder(root);
        return ans;
  
    }
};