#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е����������
//�������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ����� / ����ֱ���������ڵ�½�������γɡ�
//���⣬����Լ��������������߾���ˮ��Χ��

//����:ÿ������ '1'���Ͱ����������춼����û��Ϊ0�������ظ�������
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')//�߽緵��
            return;
        grid[i][j] = '0'; 
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }


    int numIslands(vector<vector<char>>& grid) {
        int ans{};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;

    }
};
