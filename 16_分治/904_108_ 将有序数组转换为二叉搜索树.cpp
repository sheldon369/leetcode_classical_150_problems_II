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

//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 平衡 二叉搜索树。
//分析：平衡的二叉搜索树要求每棵树的左右子树之高之差不超过1，我们每次都插入数组的中间元素即可

class Solution {
    vector<int> vec;
public:
    //TreeNode* buildBST(vector<int> nums) {//顺序建树
    //    TreeNode* root;
    //    for (int n : nums) {
    //        TreeNode* p = new TreeNode(n);
    //        if (!root)
    //            root = p;
    //        TreeNode* pre = root;
    //        TreeNode* next = root;
    //        int flag;
    //        while (!next) {
    //            if (n > pre->val) {
    //                next = pre->right;
    //                flag = 1;//右
    //            }
    //            else {
    //                next = pre->left;
    //                flag = 0;

    //            }
    //            pre = next;
    //        }
    //        if (flag)
    //            pre->right = p;
    //        else
    //            pre->left = p;

    //    }
    //}
    TreeNode* buildBST(vector<int>&nums, int begin, int end) {//每次只建立根节点,注意访问数组使用引用指针，能避免数组的复制，从而大大提升效率
        if (begin > end)
            return nullptr;
        int mid = (begin + end) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        p->left = buildBST(nums, begin, mid - 1);
        p->right = buildBST(nums, mid + 1, end);
        return p;

    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
};