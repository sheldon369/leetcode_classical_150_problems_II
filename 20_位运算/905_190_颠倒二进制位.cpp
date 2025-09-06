#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//颠倒给定的 32 位无符号整数的二进制位。

//分析：位操作中，即使我们操作的是整数，但是实际上在操作对应的二进制数
class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        for (int i = 0;i < 32;i++) {
            res <<= 1;//res左移一位，最后一位腾个0出来
            res |= (n & 1);//res腾出的一位0取 n的末位
            n >>= 1;

        }
        return res;

    }
};