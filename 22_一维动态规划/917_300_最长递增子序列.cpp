#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3, 6, 2, 7] 是数组[0, 3, 1, 6, 2, 2, 7] 的子序列。

//分析 dp[i]记录到i为止的最长递增序列长度，dp[i]为nums[i] > nums[j]的情况下，取max dp[j] + 1,O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res{0};
        vector<int> dp(nums.size());
        for (int i = 0;i < nums.size();i++) {
            int maxPre{ 0 };
            for (int j = 0;j < i;j++) {
                if (nums[i] > nums[j] && maxPre < dp[j])
                    maxPre = dp[j];
            }
            dp[i] = maxPre + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    sol.lengthOfLIS(nums);
}