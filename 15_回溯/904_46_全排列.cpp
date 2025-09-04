#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�

class Solution {
private:
    vector<vector<int>> res;

public:
    void dfs(vector<int>& nums,vector<int>& arr) {
        if (arr.size() == nums.size()) {
            res.push_back(arr);
            return;
        }
        //for (int n : nums) {//n��ʵ����numsԪ�ص�һ���������������޸�n=11�޷����ݵ�nums��
        //    int val = n;
        //    if (n != 11) {//��Ǹ�ԭ��
        //        arr.push_back(n);
        //        n = 11;
        //        dfs(nums, arr);
        //        arr.pop_back();
        //        n = val;
        //    }

        //}
        for (int i = 0;i < nums.size();i++) {//n��ʵ����numsԪ�ص�һ���������������޸�n=11�޷����ݵ�nums��
            int val = nums[i];
            if (val != 11) {//��Ǹ�ԭ��
                arr.push_back(val);
                nums[i] = 11;
                dfs(nums, arr);
                arr.pop_back();
                nums[i] = val;
            }

        }

    }



    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr{};
        dfs(nums, arr);
        return res;

    }
};

int main() {
    vector<int> nums = { 1,2,3 };
    Solution sol;
    vector<vector<int>> vec = sol.permute(nums);
    return 0;
}