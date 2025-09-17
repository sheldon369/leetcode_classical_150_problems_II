#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������
//����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�

//��iΪ͵��i�ŷ����������棬dp[i] = max{dp[i-2],dp[i-3]}+n[i]
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp{  };
        for (int i = 0;i < nums.size();i++) {
            int pre2 = i - 2 >= 0 ? dp[i - 2] : 0;
            int pre3 = i - 3 >= 0 ? dp[i - 3] : 0;
            dp.push_back( nums[i] + max(pre2, pre3));
        }
        return max(dp[nums.size() - 1], dp[nums.size() - 2]);
    }
};

int main() {
    vector<int> nums{ 1,2,3,1 };
    Solution sol;
    sol.rob(nums);


}