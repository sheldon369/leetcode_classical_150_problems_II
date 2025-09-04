#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定两个整数 n 和 k，返回范围[1, n] 中所有可能的 k 个数的组合。
//你可以按 任何顺序 返回答案。


class Solution {
private:
    vector<vector<int>> ans;
public:
    void dfs(int n,int k,vector<int>& arr,int pos) {//优化1：使用引用传递数组，避免数组频繁的拷贝操作
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }

        for (int i = pos;i <= n - (k - arr.size()) + 1;i++) {//优化2：已构造长度为arr.size()，还需 k-arr.size个元素，若i>n - (k - arr.size()) + 1，则后面的元素必然不够后序的遍历
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