#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。


class Solution {
private:
    vector<string> res;


public:
    void dfs(int n, int left, int right,string s) {
        if (s.size() == 2 * n) {
            res.push_back(s);
            return;
        }
        if (left < n) 
            dfs(n, left + 1, right, s + '(');
        if (right < left)
            dfs(n, left, right + 1, s + ')');
    

    }



    vector<string> generateParenthesis(int n) {
        string s;
        dfs(n, 0, 0,s);
        return res;

    }
};