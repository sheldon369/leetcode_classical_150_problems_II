#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给你一个大小为 n x n 的整数矩阵 board ，方格按从 1 到 n2 编号，编号遵循 转行交替方式 ，从左下角开始 （即，从 board[n - 1][0] 开始）的每一行改变方向。
//你一开始位于棋盘上的方格  1。每一回合，玩家需要从当前方格 curr 开始出发，按下述要求前进：
//选定目标方格 next ，目标方格的编号在范围[curr + 1, min(curr + 6, n2)] 。
//该选择模拟了掷 六面体骰子 的情景，无论棋盘大小如何，玩家最多只能有 6 个目的地。
//传送玩家：如果目标方格 next 处存在蛇或梯子，那么玩家会传送到蛇或梯子的目的地。否则，玩家传送到目标方格 next 。
//当玩家到达编号 n2 的方格时，游戏结束。
//如果 board[r][c] != -1 ，位于 r 行 c 列的棋盘格中可能存在 “蛇” 或 “梯子”。那个蛇或梯子的目的地将会是 board[r][c]。编号为 1 和 n2 的方格不是任何蛇或梯子的起点。
//注意，玩家在每次掷骰的前进过程中最多只能爬过蛇或梯子一次：就算目的地是另一条蛇或梯子的起点，玩家也 不能 继续移动。
//举个例子，假设棋盘是 [[-1, 4], [-1, 3]] ，第一次移动，玩家的目标方格是 2 。那么这个玩家将会顺着梯子到达方格 3 ，但 不能 顺着方格 3 上的梯子前往方格 4 。（简单来说，类似飞行棋，玩家掷出骰子点数后移动对应格数，遇到单向的路径（即梯子或蛇）可以直接跳到路径的终点，但如果多个路径首尾相连，也不能连续跳多个路径）
//返回达到编号为 n2 的方格所需的最少掷骰次数，如果不可能，则返回 - 1。

//分析：BFS构建了任一点到根结点的最短路径，因此当我们首次访问一个结点时，必然是从起始点到该结点的最快路径，设计isVisited保存访问情况，这里用default值 0 代替

class Solution {
public:
    void reverse(vector<int>& vec) {
        int n = vec.size();
        for (int i = 0;i < n/2;i++) {
            int temp = vec[n - 1 - i];
            vec[n - 1 - i] = vec[i];
            vec[i] = temp;
        }

    }
    vector<int> boardToLine(vector<vector<int>>& board) {//建立二维矩阵到一维列表的映射，从1开始
        int n = board.size();
        vector<int> ans;
        ans.push_back(0);//空元素
        //n为偶，则偶数行翻转，n为奇，则奇数行翻转
        for (int i = n - 1;i >= 0;i--) {
            if (n % 2) {//n为奇
                if (i % 2)
                    reverse(board[i]);
                ans.insert(ans.end(), board[i].begin(), board[i].end());//批量插入用insert
            }
            else {
                if (!(i % 2)) //注意：!的优先级非常高
                    reverse(board[i]);
                ans.insert(ans.end(), board[i].begin(), board[i].end());
            }

        }
        return ans;
    }



    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> line = boardToLine(board);
        int n = board.size();
        map<int, int> step;
        for (int i = 1;i <= n * n;i++) {
            step[i] = -1;
        }
        queue<int> q;
        step[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 1;i <= 6;i++) {
                if (cur + i > n * n) break;
                int new_cur = (line[cur + i] == -1) ? (cur + i) : line[cur + i];//新的访问地址
                if (step[new_cur] != -1)//非首次访问
                    continue;
                step[new_cur] = step[cur] + 1;
                if (new_cur == n * n)
                    return step[new_cur];
                q.push(new_cur);
 
            }
        }
        return -1;
        
    }
};

int main() {
    Solution sol;

    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}
    };

    int result = sol.snakesAndLadders(board);
    cout << "Result: " << result << endl;

    return 0;
}