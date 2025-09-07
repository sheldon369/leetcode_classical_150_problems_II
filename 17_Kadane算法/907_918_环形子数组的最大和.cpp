#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

//分析：理想情况下， 最大可能和至多包含数组中的全部元素
//之所以不能包含所有元素，是因为里面存在负数，任何一段区间都能将整个数组分为两部分，由于数组的和固定，故当一段取得最大和时，另一段必然取得最小和
//我们正常求解非环形数组[0,n-1]中的最大和，以及[1,n-2]最小和，刨除后者，则计算了首尾相连部分的最大和

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
  
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int sum = 0;
        int pre = 0;
        int maximum = nums[0];
        for (int i = 0;i < n;i++) {
            sum += nums[i];
            pre = max(nums[i], pre + nums[i]);
            maximum = max(pre, maximum);
        }
        pre = 0;
        int minimum = nums[1];
        for (int i = 1;i < n - 1;i++) {
            pre = min(nums[i], pre + nums[i]);
            minimum = min( pre , minimum);
        }
        return max( maximum , sum - minimum);

    }
};