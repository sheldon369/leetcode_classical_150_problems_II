#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

//你可以对一个单词进行如下三种操作：
//插入一个字符
//删除一个字符
//替换一个字符

//分析：非常的困难
//表格法：以horse 和 ros 为例
//   "" r o s
//"" 0  1 2 3
//h  1
//o  2
//r  3
//s  4
//e  5
//dp[i][j]表示 0-i构成的字符串 与 0-j构成的字符串之间的转换距离，我们不考虑某个特定方向
//初始化第一行，第一列
//dp[i][j]可从三个方向转换而来，以dp[1][1]为例
//1.左边：在左边的基础上插入当前字符即可（相对行而言） h->""->r，距离+1
//2.上边：在上边的基础上插入当前字符 r->""->h，距离+1
//3.左上方：在各去掉一位匹配的基础上，修改当前的字符，距离+1；若此时i，j对应字符一致，则无需修改，距离不变
//最终三者取小

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0;i < n + 1;++i) //第一行
            dp[0][i] = i;
        for (int i = 1;i < m + 1;++i)//第一列
            dp[i][0] = i;
        for (int i = 1;i < m + 1;++i) {
            for (int j = 1;j < n + 1;++j) {
                int left = dp[i][j - 1] + 1;
                int top = dp[i - 1][j ] + 1;
                int left_top = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(min(left, top),left_top);

            }
        }
        return dp[m][n];


        

    }
   };

