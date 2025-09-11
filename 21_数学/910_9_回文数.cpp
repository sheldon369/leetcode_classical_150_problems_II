#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

//分析：实现一个数的逆置算法，回文数则逆置数等于自身

class Solution {
public:
    //报错，因为int的逆置有可能超过int 
    int reverseInt(int x) {
        int res{0};
        while (x > 0) {
            int remain = x % 10;
            res = 10 * res + remain;
            x /= 10;
        }
        return res;
    }

    //改进，采用串的匹配
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i = 0, j = s.size() - 1;i < j;++i, --j) {//这里必须用i <j,因为i和j可能相遇，也可能直接错过,如11
            if (s[i] != s[j])
                return false;
    
        }
        return true;

    }
};
