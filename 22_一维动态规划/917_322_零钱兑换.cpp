#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ���������� coins ����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount ����ʾ�ܽ�
//���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��� �����û���κ�һ��Ӳ�����������ܽ����� - 1 ��
//�������Ϊÿ��Ӳ�ҵ����������޵ġ�

//����01�������⣬������ʱ��ÿ�������������ȿ۳������ܿ۳��Ľ��
//�������ǲ��ö�̬�滮�㷨����¼��ÿһ��������С����,dp[i] = dp[i-coin[j]] + 1;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for (int i = 1;i <= amount;i++) {
            int minPre{ -1 };
            for (int coin : coins) {
                int cur = i - coin >= 0 ? dp[i - coin] : -1;
                minPre = (minPre >= 0 && cur >= 0) ? min(minPre, cur) : max(minPre, cur);
            }
            dp[i] = minPre >= 0 ? minPre + 1 : -1;
        }
        return dp[amount];
    }
};

int main() {
    vector<int> coins{ 1,2,5 };
    Solution sol;
    sol.coinChange(coins, 11);
}