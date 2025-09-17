#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 - 1 。
//你可以认为每种硬币的数量是无限的。

//累似01背包问题，当够减时，每次我们总是优先扣除最大的能扣除的金额
//或者我们采用动态规划算法，记录到每一个面额的最小步数,dp[i] = dp[i-coin[j]] + 1;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (int i = 1;i <= amount;i++) {
            int minPre{ -1 };
            for (int coin : coins) {
                int cur = i - coin >= 0 ? dp[i - coin] : -1;
                minPre = (minPre >= 0 && cur >= 0) ? min(minPre, cur) : max(minPre, cur);
            }
            dp[i] = minPre >= 0 ? minPre + 1 : -1;
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins{ 1,2,5 };
    Solution sol;
    sol.coinChange(coins, 11);
}