#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0, 1, 2, 4, 5, 6, 7] 在变化后可能得到：
//若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 2]
//若旋转 7 次，则可以得到[0, 1, 2, 4, 5, 6, 7]
//注意，数组[a[0], a[1], a[2], ..., a[n - 1]] 旋转一次 的结果为数组[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] 。

//给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

//分析：该问题类似于907_33_搜索旋转排序数组，问题更改为找最小元素 而非指定元素
//思路类似 ,查中间元素，若 n[m] 大于 n[0] ,则说明m仍处于左半区间，向右搜索；
//若n[m] < n[0],则说明搜到右半区间了，此时更新n[0] 为 n[m],继续向左搜索；

class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r) {
        int res = nums[0];
        while (l <= r) {
            int midIdx = l + (r - l) / 2;
            int mid = nums[midIdx];
            if (mid >= res) {
                l = midIdx+ 1;
            }
            else {
                r = midIdx - 1;
                res = mid;
            }

        }
        return res;

    }




    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};


int main() {
    vector<int> num1{ 3,4,5,1,2 };
    Solution sol;
    sol.findMin(num1);



}