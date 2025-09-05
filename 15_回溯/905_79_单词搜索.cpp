#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//分析：904_212_单词搜索2的简化版，本题只要求搜索唯一的单词，则我们无需构造前缀树，且只从单词首字母开始搜索即可

class Solution {
private:
    bool res{ false };
public:
    void dfs(vector<vector<char>>& board, string& word, int i, int j,int curIdx) {

        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[curIdx] ) {//当前搜索失败
            return;
        }
        //否则当前搜索成功；
        curIdx++;
        char ch = board[i][j];
        board[i][j] = '#';
        if (curIdx == word.size())
            res = true;
        else {
            dfs(board, word, i-1, j, curIdx);
            dfs(board, word, i+1, j, curIdx);
            dfs(board, word, i, j-1, curIdx);
            dfs(board, word, i, j+1, curIdx);

        }
        board[i][j] = ch;
        


    }




    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> first;
        char ch = word[0];
        for (int i = 0;i < board.size();i++) 
            for (int j = 0;j < board[0].size();j++) 
                if (board[i][j] == ch)
                    first.push_back({ i,j });
            
        
        for (auto p : first) {
            dfs(board, word, p.first, p.second, 0);
        }
        return res;

       
    }
};