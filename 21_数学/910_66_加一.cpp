#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给定一个表示 大整数 的整数数组 digits，其中 digits[i] 是整数的第 i 位数字。这些数字按从左到右，从最高位到最低位排列。这个大整数不包含任何前导 0。
//将大整数加 1，并返回结果的数字数组。

//分析，类似824_2_两数相加

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 1;
        while (carry && n >= 0 ) {
            digits[n] += carry;
            carry = digits[n] / 10;
            digits[n] %= 10;
            n--;
        }//退出循环时 carry == 0 或者 carry = 1 &&  n = -1
        if (carry == 0)
            return digits;
        else {//若carry 为 1退出，则发生在999 ->1000时
            vector<int> res{ 1 };
            for (int i = 0;i < digits.size();i++)
                res.push_back(0);
            return res;
        }
            
    }
};