#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m - 1][n - 1]）。机器人每次只能向下或者向右移动一步。
//网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
//返回机器人能够到达右下角的不同路径数量。

//分析：在918_64最小路径和的基础上增加了障碍物判定，并且返回路径数量而不是路径长度，不影响大致代码整体逻辑

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n);
		dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int i = 1;i < n;++i) {//第一行，只能从左方到达
            if (obstacleGrid[0][i] == 0 && dp[i-1] >= 1)//若此位置非障碍物且左方能到达
                dp[i] =  1;
            else
                dp[i] = 0;

        }

        int i = 1;
        while (i < m) {
            for (int j = 0;j < obstacleGrid[0].size();++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }

                if (j == 0) 
                    dp[j] = (dp[j] == 0 ) ? 0 : 1;
                else {
                    int up = dp[j];
                    int left = dp[j - 1];
                    if (up == 0 && left == 0)
                        dp[j] = 0;
                    else if (up == 0 || left == 0)//至少有一个可达
                        dp[j] = max(up, left);
                    else //都可达
                        dp[j] = up + left;

                }
            }
            i++;
        }
        return dp[n - 1];
    }
};

int main() {
    vector<vector<int>> triangle{ {0,0,0},{0,1,0},{0,0,0} };
    Solution sol;
    cout << sol.uniquePathsWithObstacles(triangle);
}