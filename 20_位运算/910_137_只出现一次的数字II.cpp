#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

//分析：不同于905_136,我们没有合适的运算来直接解决该问题，但却又类似的思路
//统计每一位上1出现的次数，如果不是单独元素，必然出现3k次，因此每位mod 3k即可

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{ 0 };
        for (int i = 0;i < 32;i++) {
            int numOf1 = 0;
            for (int num : nums) {
                numOf1 += (num >> i) & 1;
            }
            numOf1 = numOf1 % 3;
            res |= numOf1 << i;


        }
        return res;

    }
};