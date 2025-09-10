#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//一个 2D 网格中的 峰值 是指那些 严格大于 其相邻格子(上、下、左、右)的元素。
//给你一个 从 0 开始编号 的 m x n 矩阵 mat ，其中任意两个相邻格子的值都 不相同 。找出 任意一个 峰值 mat[i][j] 并 返回其位置[i, j] 。
//要求必须写出时间复杂度为 O(m log(n)) 或 O(n log(m)) 的算法

//分析：我们首先找出中心行中的最大元素，对他进行上下判别，并将搜索方向总是转向更大数的方向
class Solution {
public:
    int maxOfColumn(vector<int> vec) {//返回最大元素的索引
        int res = -1;
        int idx;
        for (int i = 0;i < vec.size();i++) {
            if (vec[i] > res) {
                res = vec[i];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> binarySearch(vector<vector<int>>& mat,int l,int r) {
        int mid = l + (r - l) / 2;//最大元素此时为mat[mid][maxOfColumn(mat[mid])]
        int cur = mat[mid][maxOfColumn(mat[mid])];
        int front = mid - 1 >= 0 ? mat[mid - 1][maxOfColumn(mat[mid])]: -1;
        int below = mid + 1 < mat.size() ? mat[mid + 1][maxOfColumn(mat[mid])] : -1;
        if (cur > front && cur > below)
            return vector<int>{mid, maxOfColumn(mat[mid])};
        else if (cur > front && cur < below)//向下走
            return binarySearch(mat, mid + 1, r);
        else
            return binarySearch(mat, l, mid - 1);
        
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        return binarySearch(mat, 0, mat.size()-1);


    }
};
