#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

//n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
//给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

//分析：皇后之间不攻击，要求行，列，双斜线都不能存在另一个皇后，故我们设计数组存现在已有的皇后信息
//我们按行添加皇后，存储列，主对角线，副对角线上的皇后信息
//假设当前元素为(i,j),则对应列 column[j],diagonals1[i-j](可能为负),diagonals2[i+j] 对角线有2n-1条

class Solution {
private:
    set<int> column;
    set<int> diagonals1;
    set<int> diagonals2;//只需要查找存在性，并且有负元素，不便使用数组索引，故使用集合
    int ans{};

public:
    void dfs(int n, int currentRow) {
        if (currentRow == n) {
            ans++;
            return;
        }
        for (int j = 0;j < n;j++) {
            if (!column.count(j) && !diagonals1.count(currentRow - j) && !diagonals2.count(currentRow +j)) {//当前位置允许插入
                column.insert(j);
                diagonals1.insert(currentRow - j);
                diagonals2.insert(currentRow + j);
                dfs(n, currentRow + 1);
                column.erase(j);
                diagonals1.erase(currentRow - j);
                diagonals2.erase(currentRow + j);

            }
        }


    }



    int totalNQueens(int n) {
        dfs(n, 0);
        return ans;

    }
};
