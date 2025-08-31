#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
//连接：一个单元格与水平或垂直方向上相邻的单元格连接。
//区域：连接所有 'O' 的单元格来形成一个区域。
//围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
//通过 原地 将输入矩阵中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。你不需要返回任何值。

//分析：通过与831_200类似的技术来获取一块联通的'O'区域，不同的是不允许该区域碰触到边界
//「从每个 'O' 出发检查是不是被包围」，复杂度更高，而且边界处理容易出错。
//建议从边界上的'O'出发，将所在联通区域标记为不会翻转，再遍历翻转其余'O'
class Solution {
    
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'O')//边界返回
            return;
         grid[i][j] = '#';//特殊标记不会翻转的'O'
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }


    void solve(vector<vector<char>>& board) {
        int ans{};
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][n-1] == 'O')
                dfs(board, i, n-1);
        }
        for (int j = 0;j < n;j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[m-1][j] == 'O')
                dfs(board, m-1, j);
        }
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
                
            }
        }
        

    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'O','O'},
        {'O','O'}
    };


    sol.solve(board);
    return 0;
}