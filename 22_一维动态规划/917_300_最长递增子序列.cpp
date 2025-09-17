#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ���������� nums ���ҵ�������ϸ���������еĳ��ȡ�
//������ ���������������������У�ɾ������ɾ���������е�Ԫ�ض����ı�����Ԫ�ص�˳�����磬[3, 6, 2, 7] ������[0, 3, 1, 6, 2, 2, 7] �������С�

//���� dp[i]��¼��iΪֹ����������г��ȣ�dp[i]Ϊnums[i] > nums[j]������£�ȡmax dp[j] + 1,O(n2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res{0};
        vector<int> dp(nums.size());
        for (int i = 0;i < nums.size();i++) {
            int maxPre{ 0 };
            for (int j = 0;j < i;j++) {
                if (nums[i] > nums[j] && maxPre < dp[j])
                    maxPre = dp[j];
            }
            dp[i] = maxPre + 1;
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> nums {10, 9, 2, 5, 3, 7, 101, 18};
    Solution sol;
    sol.lengthOfLIS(nums);
}