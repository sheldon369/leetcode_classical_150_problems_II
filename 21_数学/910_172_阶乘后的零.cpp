#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给定一个整数 n ，返回 n! 结果中尾随零的数量。

//分析：若结果产生0，假设将 n! 写作 素因子分解，则 一次 2*5 产生 一个10，即结尾的0
//因子2可由全部偶数因子提供，n! 中有 n/2个 2
//因子5只能由5的倍数因子提供,n! 中有 n/5个 5
//因此对于任意n，制约尾随0的个数的因素只是5因子的个数
//其中,5的幂各自贡献幂次的因子数，5 ,25,125,625,3125,15625....由于n在10000以内，我们仅考虑3125以内的幂次

class Solution {
public:
    int trailingZeroes(int n) {
        return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;

    }
};