#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  //����һ�������� root �������������ȡ�
  //�������� ������ ��ָ�Ӹ��ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����

  //���������������������ÿ�θ���������

  class Solution {
  private:
      int depth{ 0 };//�����ڽ�1

  public:
      //��1��ʹ�ò�������
      void depth_PreOrder(TreeNode* root,int x) {
          if (root == nullptr)
              return;
          depth = x > depth ? x : depth;
          depth_PreOrder(root->left, x + 1);
          depth_PreOrder(root->right, x + 1);
      }

      //��2:ʹ�ú�������ֵ
      int depth_PostOrder(TreeNode* root) {
          if (root == nullptr)
              return 0;

          int l = depth_PostOrder(root->left);
          int r = depth_PostOrder(root->right);
          return l > r ? l + 1 : r + 1;

      }



      int maxDepth(TreeNode* root) {
          //��1��
         /* depth_PreOrder(root,1);
          return depth;*/

          //��2��
          return depth_PostOrder(root);

      }
  };