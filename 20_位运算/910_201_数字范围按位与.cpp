#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你两个整数 left 和 right ，表示区间[left, right] ，返回此区间内所有数字 按位与 的结果（包含 left 、right 端点）。
//0 <= left <= right <= 231 - 1

//按位与只要有一个为0，则全部为0，而相邻的两个数在低位必然不同，因此问题转化为找到最大公共前缀
//我们从第30位搜到0位，若比对一致，则令 res |=  x << i 一旦比对不一致，就输出res

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res{ 0 };
        for (int i = 30;i >= 0;--i) {
            if (((left >> i) & 1) == ((right >> i) & 1))
                res |= ((left >> i) & 1) << i;
            else
                return res;

        }
        return res;

    }
};

