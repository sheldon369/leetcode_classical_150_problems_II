#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

class Solution {
private:
    vector<vector<int>> res;

public:
    void dfs(vector<int>& nums,vector<int>& arr) {
        if (arr.size() == nums.size()) {
            res.push_back(arr);
            return;
        }
        //for (int n : nums) {//n事实上是nums元素的一个副本，故我们修改n=11无法传递到nums上
        //    int val = n;
        //    if (n != 11) {//标记复原法
        //        arr.push_back(n);
        //        n = 11;
        //        dfs(nums, arr);
        //        arr.pop_back();
        //        n = val;
        //    }

        //}
        for (int i = 0;i < nums.size();i++) {//n事实上是nums元素的一个副本，故我们修改n=11无法传递到nums上
            int val = nums[i];
            if (val != 11) {//标记复原法
                arr.push_back(val);
                nums[i] = 11;
                dfs(nums, arr);
                arr.pop_back();
                nums[i] = val;
            }

        }

    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr{};
        dfs(nums, arr);
        return res;

    }
};

int main() {
    vector<int> nums = { 1,2,3 };
    Solution sol;
    vector<vector<int>> vec = sol.permute(nums);
    return 0;
}