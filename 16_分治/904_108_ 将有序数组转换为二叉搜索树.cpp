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

//����һ���������� nums ������Ԫ���Ѿ��� ���� ���У����㽫��ת��Ϊһ�� ƽ�� ������������
//������ƽ��Ķ���������Ҫ��ÿ��������������֮��֮�����1������ÿ�ζ�����������м�Ԫ�ؼ���

class Solution {
    vector<int> vec;
public:
    //TreeNode* buildBST(vector<int> nums) {//˳����
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
    //                flag = 1;//��
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
    TreeNode* buildBST(vector<int>&nums, int begin, int end) {//ÿ��ֻ�������ڵ�,ע���������ʹ������ָ�룬�ܱ�������ĸ��ƣ��Ӷ��������Ч��
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