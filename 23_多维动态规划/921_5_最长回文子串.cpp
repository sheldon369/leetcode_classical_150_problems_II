#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你一个字符串 s，找到 s 中最长的 回文 子串。
//回文 指 字符串的转置等于其自身，子串要求位置连续

//回文串的性质：若删除回文串的首尾字符，则剩余字符串仍是回文串
//从 i = 1 到 i = n-2枚举回文中心，每次至多向外扩展 min(i,n-1-i)次，一旦非回文串则提前中止 ->只能处理奇数长度的回文串



class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int resLength = 1;
        string res{};
        res += s[0];
        for (int i = 1;i <= n - 2;++i) {//i为回文中心
            for (int j = 1;j <= min(i, n - 1 - i);++j) {//j为串向外扩展的次数，考察奇数长度回文串
                if (s[i - j] != s[i + j])
                    break;
                if (1 + 2 * j > resLength) {
                    resLength = 1 + 2 * j;
                    res = s.substr(i - j, 1 + 2 * j);
                }

            }
        }
        for (double i = 0.5;i < n - 1;++i) {//考察偶数长度回文串
            for (int j = 1;j <= min(i + 0.5, n - 0.5 - i);++j) {
                if (s[i +0.5 - j] != s[i - 0.5 + j])
                    break;
                if ( 2 * j > resLength) {
                    resLength =  2 * j;
                    res = s.substr(i + 0.5 - j,  2 * j);
                }

            }
        }



        return res;

    }
};

int main() {
    string s{ "a" };
    Solution sol;
    cout << sol.longestPalindrome(s);
}