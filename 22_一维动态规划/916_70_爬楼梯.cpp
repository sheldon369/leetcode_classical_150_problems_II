#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//������������¥�ݡ���Ҫ n ������ܵ���¥����
//ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

//dp[1]=1,dp[2]=2,....,dp[n]=dp[n-1]+dp[n-2]

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp{ 0,1,2 };
        for (int i = 3;i <= n;i++) {
            dp.push_back(dp[i - 1] + dp[i - 2]);

        }
        return dp[n];

    }
};