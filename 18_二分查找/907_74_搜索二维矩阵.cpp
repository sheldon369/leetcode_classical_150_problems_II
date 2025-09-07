#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你一个满足下述两条属性的 m x n 整数矩阵：

//每行中的整数从左到右按非严格递增顺序排列。
//每行的第一个整数大于前一行的最后一个整数。
//给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

//分析：找到首个大于target的行i，在行i-1中搜索target
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
 
        int row;
        for (row = 0;row < m;row++) {
            if (matrix[row][0] > target)
                break;
        }
        if(row)
            row--;
        for (int ele : matrix[row]) {
            if (ele == target)
                return true;
        }
        return false;

    }
};