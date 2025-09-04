#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
private:
    vector<vector<char>> phone = { {},{},{'a','b','c'},{'d','e','f'} ,{'g','h','i'} ,{'j','k','l'} ,{'m','n','o'} ,{'p','q','r','s'} ,{'t','u','v'} ,{'w','x','y','z'} };
    int n;
    vector<string> res;
public:
    void dfs(string digits,string pre,int pos) {
        if (pos == n)
            return;
        for (char ch : phone[digits[pos] - '0']) {
            string s = pre + ch;
            if (s.length() == n)
                res.push_back(s);
            dfs(digits, s, pos + 1);
        }

    }
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        dfs(digits, "", 0);
        return res;

    }
};