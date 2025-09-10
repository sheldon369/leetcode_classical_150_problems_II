#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target == nums[m])
                return m;
            else if (target < nums[m])
                r = m - 1;
            else
                l = m + 1;

        }//当查询失败时，r < l,r = l-1,l总是指向target该被顺序插入的位置
        return l;

    }
};

int main() {
    vector<int> vec{ 1,3,5,6 };
    Solution sol;
    sol.searchInsert(vec, 5);

}