#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

//分析：位运算——异或
//任何数和 0 做异或运算，结果仍然是原来的数，即 a⊕0 = a。
//任何数和其自身做异或运算，结果是 0，即 a⊕a = 0。
//异或运算满足交换律和结合律，即 a⊕b⊕a = b⊕a⊕a = b⊕(a⊕a) = b⊕0 = b。
//则数组中所有元素做异或运算，结果为那个只出现一次的元素

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{0};
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};