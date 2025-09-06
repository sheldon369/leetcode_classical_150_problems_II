#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给定一个正整数 n，编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 设置位 的个数（也被称为汉明重量）（即二进制表示中1的个数）。
class Solution {
public:
    int hammingWeight1(int n) {
        int count = 0;
        int m = 1;
        while (m <= n) {
            count += (n & m);
            m *= 2;//m容易超出int的表示范围
        }
        return count;

    }
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
            
        }
        return count;

    }
};