#include <cmath>
#include <iostream>
using namespace std;

//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
//由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

//分析：方法1，打表，计算出int范围内所有合理的平方
//优化：二分查找，求 sqrt(x),必然有 1<= sqrt(x) <= x

//二分查找失败时，l指向应该插入的位置，返回l-1
class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
       
            if (mid > 46340 || mid * mid > x)  //int能表示的最大整数小于 2^31,则开根小于 2^15 * sqrt 2 =32768 * 1.414 =  46340.9 ，注意此判别要在计算 mid * mid之前
                r = mid - 1;
            else if (mid * mid == x)
                return mid;
            else
                l = mid + 1;
           
           

        }
        return l - 1;

    }
};
