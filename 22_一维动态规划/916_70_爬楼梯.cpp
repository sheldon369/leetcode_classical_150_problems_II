#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

//dp[1]=1,dp[2]=2,....,dp[n]=dp[n-1]+dp[n-2]

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp{ 0,1,2 };
        for (int i = 3;i <= n;i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);

        }
        return dp[n];

    }
};