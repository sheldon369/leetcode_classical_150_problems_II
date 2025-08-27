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
 
  //给定一个二叉树 root ，返回其最大深度。
  //二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

  //分析：先序遍历二叉树，每次更新最大深度

  class Solution {
  private:
      int depth{ 0 };//仅用于解1

  public:
      //解1：使用参数传递
      void depth_PreOrder(TreeNode* root,int x) {
          if (root == nullptr)
              return;
          depth = x > depth ? x : depth;
          depth_PreOrder(root->left, x + 1);
          depth_PreOrder(root->right, x + 1);
      }

      //解2:使用函数返回值
      int depth_PostOrder(TreeNode* root) {
          if (root == nullptr)
              return 0;

          int l = depth_PostOrder(root->left);
          int r = depth_PostOrder(root->right);
          return l > r ? l + 1 : r + 1;

      }



      int maxDepth(TreeNode* root) {
          //解1：
         /* depth_PreOrder(root,1);
          return depth;*/

          //解2：
          return depth_PostOrder(root);

      }
  };