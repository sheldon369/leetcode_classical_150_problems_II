#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ�����������������Ե� m x n ��������

//ÿ���е����������Ұ����ϸ����˳�����С�
//ÿ�еĵ�һ����������ǰһ�е����һ��������
//����һ������ target ����� target �ھ����У����� true �����򣬷��� false ��

//�������ҵ��׸�����target����i������i-1������target
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