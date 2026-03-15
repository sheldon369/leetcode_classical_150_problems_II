#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定一个三角形 triangle ，找出自顶向下的最小路径和。
//每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
//也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

//分析：dp(i,j)记录到ij的最小路径，dp(i,j) = min(dp(i-1,j),dp(i-1,j-1))+nums(i,j)
//考虑数组越界索引，首先加入三角形第一个元素，之后越界则返回INT_MAX
//n行的三角形每层至多n个元素

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        dp.push_back({ triangle[0][0] });
        int i = 1;
        while (i < triangle.size()) {//第i层共i+1个元素
            vector<int> curLevel{};
            for (int j = 0;j < i + 1;j++) {
                int cur{};
                if (j == 0)
                    cur = dp[i - 1][0];
                else if (j == i)
                    cur = dp[i - 1][i - 1];
                else
                    cur = min(dp[i - 1][j], dp[i - 1][j - 1]);
                curLevel.push_back(cur + triangle[i][j]);
            }
            dp.push_back(curLevel);
            i++;
        }
        int res = INT_MAX;
        for (int ele : dp[dp.size() - 1]) {
            res = min( res,ele );
        }
        return res;
  

    }
};

int main() {
    vector<vector<int>> triangle{ {2},{3,4},{6,5,7},{4,1,8,3} };
    Solution sol;
    sol.minimumTotal(triangle);
}
//你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
//f[i][j] 只与 f[i−1][..] 有关，而与 f[i−2][..] 及之前的状态无关，因此我们不必存储这些无关的状态。
//具体地，我们使用两个长度为 n 的一维数组进行转移，将 i 根据奇偶性映射到其中一个一维数组，那么 i−1 就映射到了另一个一维数组。这样我们使用这两个一维数组，交替地进行状态转移。
