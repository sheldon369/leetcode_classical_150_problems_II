#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//峰值元素是指其值严格大于左右相邻值的元素。
//给你一个整数数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
//你必须实现时间复杂度为 O(log n) 的算法来解决此问题。
//对于所有有效的 i 都有 nums[i] != nums[i + 1]，你可以假设 nums[-1] = nums[n] = -∞ 
//故寻找/\元素，一旦发现在/我们就向右搜，一旦发现在\我们就向左搜，必然可以找到峰值元素

class Solution {
public:
    pair<int, int> getNeighbours(vector<int>& nums, int idx) {
        pair<int, int> ans;
        int pre = (idx - 1 >= 0) ? nums[idx - 1] : INT_MIN;
        int suc = (idx + 1 < nums.size()) ? nums[idx + 1] : INT_MIN;
        ans.first = pre;
        ans.second = suc;
        return ans;

    }



    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) >> 1;

            //我们直接使用nums来访问左右数组，可能会访问到空元素nums[-1],nums[-2]
            //if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            //    return m;
            //else if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1]) // 上山，向右搜索
            //    l = m + 1;
            //else
            //    r = m - 1;

            pair<int, int> neighbour = getNeighbours(nums, m);
            if (nums[m] >= neighbour.first && nums[m] >= neighbour.second)//题设保证了nums[i] != nums[i + 1]，我们之所以使用等于，是为了排除nums[i] = -2^31，即INT_MIN的情况
                return m;
            else if (nums[m] >= neighbour.first && nums[m] <= neighbour.second) // 上山，向右搜索
                l = m + 1;
            else
                r = m - 1;
        }
        return 0;


    }
};