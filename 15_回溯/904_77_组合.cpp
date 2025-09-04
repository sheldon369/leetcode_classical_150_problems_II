#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//������������ n �� k�����ط�Χ[1, n] �����п��ܵ� k ��������ϡ�
//����԰� �κ�˳�� ���ش𰸡�


class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(int n,int k,vector<int>& arr,int pos) {//�Ż�1��ʹ�����ô������飬��������Ƶ���Ŀ�������
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }

        for (int i = pos;i <= n - (k - arr.size()) + 1;i++) {//�Ż�2���ѹ��쳤��Ϊarr.size()������ k-arr.size��Ԫ�أ���i>n - (k - arr.size()) + 1��������Ԫ�ر�Ȼ��������ı���
            arr.push_back(i);
            dfs(n ,k,arr, i + 1);
            arr.pop_back();
        }

    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> arr{};
        dfs(n, k, arr, 1);
        return ans;
    }
};