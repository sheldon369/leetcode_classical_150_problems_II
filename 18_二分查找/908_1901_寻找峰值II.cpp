#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//һ�� 2D �����е� ��ֵ ��ָ��Щ �ϸ���� �����ڸ���(�ϡ��¡�����)��Ԫ�ء�
//����һ�� �� 0 ��ʼ��� �� m x n ���� mat �����������������ڸ��ӵ�ֵ�� ����ͬ ���ҳ� ����һ�� ��ֵ mat[i][j] �� ������λ��[i, j] ��
//Ҫ�����д��ʱ�临�Ӷ�Ϊ O(m log(n)) �� O(n log(m)) ���㷨

//���������������ҳ��������е����Ԫ�أ��������������б𣬲���������������ת��������ķ���
class Solution {
public:
    int maxOfColumn(vector<int> vec) {//�������Ԫ�ص�����
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
        int mid = l + (r - l) / 2;//���Ԫ�ش�ʱΪmat[mid][maxOfColumn(mat[mid])]
        int cur = mat[mid][maxOfColumn(mat[mid])];
        int front = mid - 1 >= 0 ? mat[mid - 1][maxOfColumn(mat[mid])]: -1;
        int below = mid + 1 < mat.size() ? mat[mid + 1][maxOfColumn(mat[mid])] : -1;
        if (cur > front && cur > below)
            return vector<int>{mid, maxOfColumn(mat[mid])};
        else if (cur > front && cur < below)//������
            return binarySearch(mat, mid + 1, r);
        else
            return binarySearch(mat, l, mid - 1);
        
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        return binarySearch(mat, 0, mat.size()-1);


    }
};
