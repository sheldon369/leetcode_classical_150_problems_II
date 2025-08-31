#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ��ɣ����� ���� ��Χ�Ƶ�����
//���ӣ�һ����Ԫ����ˮƽ��ֱ���������ڵĵ�Ԫ�����ӡ�
//������������ 'O' �ĵ�Ԫ�����γ�һ������
//Χ�ƣ������������ 'X' ��Ԫ�� ����������򣬲���������û���κε�Ԫ��λ�� board ��Ե��������� 'X' ��Ԫ��Χ�ơ�
//ͨ�� ԭ�� ����������е����� 'O' �滻Ϊ 'X' �� ����Χ�Ƶ������㲻��Ҫ�����κ�ֵ��

//������ͨ����831_200���Ƶļ�������ȡһ����ͨ��'O'���򣬲�ͬ���ǲ�����������������߽�
//����ÿ�� 'O' ��������ǲ��Ǳ���Χ�������Ӷȸ��ߣ����ұ߽紦�����׳���
//����ӱ߽��ϵ�'O'��������������ͨ������Ϊ���ᷭת���ٱ�����ת����'O'
class Solution {
    
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 'O')//�߽緵��
            return;
         grid[i][j] = '#';//�����ǲ��ᷭת��'O'
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