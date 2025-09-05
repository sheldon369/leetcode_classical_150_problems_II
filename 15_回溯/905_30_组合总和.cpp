#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//2 <= candidates[i] <= 40

//分析：可以无限制选取，则无需做标记还原法
//[2,2,3],[2,3,2],[3,2,2]算是同一个数组,我们控制组合的顺序唯一，即指针只往右走，则能避免232 322的出现
class Solution {
private:
    vector<vector<int>> res;

public:
    void dfs(vector<int>& candidates, int target,int idx, vector<int>& current) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        for (int i = idx;i < candidates.size();i++) {
            if (target >= candidates[i]) {
                current.push_back(candidates[i]);
                target -= candidates[i];
                dfs(candidates, target, i, current);
                current.pop_back();
                target += candidates[i];
            }
        }
        


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current{};
        dfs(candidates, target,0, current);

        return res;
    }
};


