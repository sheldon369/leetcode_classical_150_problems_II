#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//子数组是数组中的一个连续部分。

//解1：动态规划,f(i) = max(f(i-1)+nums(i),nums(i)),卡丹算法，不做赘述
//解2：分治，线段树。定义一个操作 get(a, l, r) 表示查询 a 序列 [l,r] 区间内的最大子段和，该法可对数据进行修改，并且查询任意子段
//对于一个区间 [l,r]，我们取 m= (l + r)/2,对区间[l, m] 和[m + 1, r] 分治求解。当递归逐层深入直到区间长度缩小为 1 的时候，递归「开始回升」。

//对于一个区间[l, r]，我们可以维护四个量：
//lSum 表示[l, r] 内以 l 为左端点的最大子段和
//rSum 表示[l, r] 内以 r 为右端点的最大子段和
//mSum 表示[l, r] 内的最大子段和
//iSum 表示[l, r] 的区间和

class Solution {
public:
    struct Node {//Segment tree
        int iSum;
        int lSum;
        int rSum;
        int mSum;
        Node(int _iSum, int _lSum, int _rSum, int _mSum) :iSum(_iSum), lSum(_lSum), rSum(_rSum), mSum(_mSum) {}
    };
    Node merge(Node a, Node b) {
        int iSum = a.iSum + b.iSum;
        int lSum = max(a.lSum, a.iSum + b.lSum);//左字段前缀和，或者左子段全部+右子段前缀和
        int rSum = max(b.rSum, b.iSum + a.rSum);
        int mSum = max(max(a.mSum, b.mSum), a.rSum + b.lSum);
        return Node(iSum, lSum, rSum, mSum);
    }

    Node get(const vector<int>& nums, int l, int r) {
        if (l == r)
            return Node(nums[l], nums[l], nums[l], nums[l]);
        int mid = (l + r) / 2;
        Node a = get(nums, l, mid);
        Node b = get(nums, mid + 1, r);
        return merge(a, b);
    }


    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;

    }
};





