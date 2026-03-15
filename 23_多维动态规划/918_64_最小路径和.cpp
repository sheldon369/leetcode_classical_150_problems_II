#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//说明：每次只能向下或者向右移动一步。

//同样使用dp（i，j）记录到达该点的最小路径和，与120累似
// dp(i,j) = min(dp(i,j-1),dp(i-1,j))+nums(i,j)
// 边界情况： 若i = 0，则只能由左移动而来;若j=0，只能由上移动而来
// 我们先计算出左上两条边界，再顺序建立dp

class Solution {
public:
    int minPathSum0(vector<vector<int>>& grid) {
        vector<vector<int>> dp{ {grid[0][0]} };
        for (int i = 1;i < grid[0].size();++i)
            dp[0].push_back(dp[0][i - 1] + grid[0][i]);
        for (int j = 1;j < grid.size();++j)
            dp.push_back({ dp[j-1][0]+ grid[j][0] });
        for (int i = 1;i < grid.size();++i) {
            for (int j = 1;j < grid[0].size();++j)
                dp[i].push_back ( min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]);
            

        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
//优化：直接分配好空间，push_back开销较大，内存需要重新分配，vector<vector<int>> dp(m, vector<int>(n)); // 直接分配好空间
//优化2：每一层实际上需要用到上一层的数据和本层的数据，因此我们只需要O(n)空间就可以完成存储。
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);
        dp[0] = grid[0][0];
        for (int i = 1;i < n;++i)
            dp[i] = dp[i - 1] + grid[0][i];
        int i = 1;
        while (i < m) {
            for (int j = 0;j < grid[0].size();++j)
                dp[j] = (j == 0) ? (dp[0] + grid[i][0]) :( min(dp[j], dp[j - 1]) + grid[i][j]);
            i++;
        }
        return dp[n-1];
    }

};




int main() {
    vector<vector<int>> triangle{ {1,2,3},{4,5,6} };
    Solution sol;
    cout << sol.minPathSum(triangle);
}