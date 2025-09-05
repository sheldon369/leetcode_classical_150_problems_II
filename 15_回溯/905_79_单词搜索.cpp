#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ�� m x n ��ά�ַ����� board ��һ���ַ������� word ����� word �����������У����� true �����򣬷��� false ��
//���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����Ԫ���ڵ���ĸ�������ظ�ʹ�á�

//������904_212_��������2�ļ򻯰棬����ֻҪ������Ψһ�ĵ��ʣ����������蹹��ǰ׺������ֻ�ӵ�������ĸ��ʼ��������

class Solution {
private:
    bool res{ false };
public:
    void dfs(vector<vector<char>>& board, string& word, int i, int j,int curIdx) {

        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != word[curIdx] ) {//��ǰ����ʧ��
            return;
        }
        //����ǰ�����ɹ���
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