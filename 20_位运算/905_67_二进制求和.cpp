#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())//保证a的长度大于等于b的长度
            swap(a, b);
        string s;
        for (int i = 0;i < a.length() - b.length();i++) {
            s += '0';
        }
        s += b;
        b = s;//给b高位补0,并多补一个0
        deque<char> dq;
        int carry = 0;
        for (int i = a.length() - 1;i >= 0;i--) {
            
            int sum = ((a[i] - '0') + (b[i] - '0') + carry) % 2;
            carry = ((a[i] - '0') + (b[i] - '0') + carry)/ 2;
            dq.push_front('0'+ sum);
        }
        if (carry == 1)
            dq.push_front('1');

        a = string(dq.begin(),dq.end() );
        return a;

    }
};