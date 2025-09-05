#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

//����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target ���ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �� ���� ��ͬ��� �������б���ʽ���ء�����԰� ����˳�� ������Щ��ϡ�
//candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ ���������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ�ġ�
//���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ����
//2 <= candidates[i] <= 40

//����������������ѡȡ������������ǻ�ԭ��
//[2,2,3],[2,3,2],[3,2,2]����ͬһ������,���ǿ�����ϵ�˳��Ψһ����ָ��ֻ�����ߣ����ܱ���232 322�ĳ���
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


