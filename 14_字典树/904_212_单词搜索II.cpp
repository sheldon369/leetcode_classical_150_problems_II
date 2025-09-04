#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
//单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
//同一个单元格内的字母在一个单词中不允许被重复使用。

//分析：一个非边界字符可以搜索上下左右四个方向，字典树+深度优先遍历+剪枝+标记还原法
//从二维网格中每个单元格出发
//深度优先搜索当前路径，如果该路径并非带搜索元素构成的前缀树的前缀，则停止搜索剪枝，每个搜过的元素重置为#，避免重复搜索（即标记还原法）

//note：同一答案可能在多条路径上出现，使用哈希集合去重
//判断前缀时，无需每次都判断当前串是否为完整前缀，只需要比对新增结点即可

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    string s;
    TrieNode() : isEnd(false), children(26),s("") {}//初始化26个nullptr孩子指针
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    unordered_set<string> ans;
public:
    void insert(string word) {
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch])//否则之前的某些串已经完成了该项构造
                pCur->children[ch] = new TrieNode();
            pCur = pCur->children[ch];
        }
        pCur->isEnd = true;
        pCur->s = word;
    }

    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* pre) {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '#')
            return;
        char ch = board[r][c];
        int pos = ch - 'a';//ch不为#
        if (!pre->children[pos])
            return;
    
        pre = pre->children[pos];//当前位置匹配成功
        if (pre->isEnd)
            ans.insert(pre->s);

        board[r][c] = '#';//标记还原法
        for (int i = 0;i < 4;i++) 
            dfs(board, r + direction[i][0], c + direction[i][1], pre);
        board[r][c] = ch;
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0)
            return res;
        for (auto word : words) 
            insert(word);
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) 
            for (int j = 0;j < n;j++)
                dfs(board, i, j, root);
        res = vector<string>{ ans.begin(), ans.end() };
        return res;

    }
};

//改进：去掉isEnd判断，仅使用s；或更好的保留isEnd，添加单词时重新把s从Trie中读出
//去掉set的使用，读出单词后将isEnd改为false避免重复读出