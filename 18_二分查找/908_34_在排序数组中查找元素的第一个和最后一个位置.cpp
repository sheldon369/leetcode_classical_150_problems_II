#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
//如果数组中不存在目标值 target，返回[-1, -1]。
//你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

//分析：二分查找先找到该元素，再向前向后遍历找范围
//或者找到第一个大于等于target的下标,以及第一个大于target的下标
//优化：直接找虚拟元素target - 0.5, target + 0.5，查找失败时，l总是指向目标该被插入的位置

class Solution {
public:
    //解2：直接查找，注意这个算法中的判别条件
    int binarySearch(vector<int>& nums, int target, bool lower) {//lower标记要寻找左端点还是右端点
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;//向左
                ans = mid;//满足时记录，直到递归出局，则最后记录的为符合条件的第一个或最后一个元素
            }
            else {
                left = mid + 1;//向右
            }
        }
        return ans;
    }

    int binarySearchVirtual(vector<int>& nums, float target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
        //l为虚拟元素应该插入的位置
        //搜索target - 0.5时,结果指向首个target索引，记为a
        //搜索target + 0.5时，结果指向首个大于target的索引,记为b，因此-1得到target的末尾位置

        //因此若target存在，a < b ,返回 {a,b-1}


        //若target不存在，则此时a = b,返回{-1，-1}

    }



    vector<int> searchRange(vector<int>& nums, int target) {
        return (binarySearchVirtual(nums, target - 0.5) != binarySearchVirtual(nums, target + 0.5)) ?
            vector<int>{binarySearchVirtual(nums, target - 0.5), binarySearchVirtual(nums, target + 0.5) - 1} :
            vector<int>{ -1,-1 };

    }
};