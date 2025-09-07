#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//��ֵԪ����ָ��ֵ�ϸ������������ֵ��Ԫ�ء�
//����һ���������� nums���ҵ���ֵԪ�ز�������������������ܰ��������ֵ������������£����� �κ�һ����ֵ ����λ�ü��ɡ�
//�����ʵ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨����������⡣
//����������Ч�� i ���� nums[i] != nums[i + 1]������Լ��� nums[-1] = nums[n] = -�� 
//��Ѱ��/\Ԫ�أ�һ��������/���Ǿ������ѣ�һ��������\���Ǿ������ѣ���Ȼ�����ҵ���ֵԪ��

class Solution {
public:
    pair<int, int> getNeighbours(vector<int>& nums, int idx) {
        pair<int, int> ans;
        int pre = (idx - 1 >= 0) ? nums[idx - 1] : INT_MIN;
        int suc = (idx + 1 < nums.size()) ? nums[idx + 1] : INT_MIN;
        ans.first = pre;
        ans.second = suc;
        return ans;

    }



    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int m = (l + r) >> 1;

            //����ֱ��ʹ��nums�������������飬���ܻ���ʵ���Ԫ��nums[-1],nums[-2]
            //if (nums[m] > nums[m - 1] && nums[m] > nums[m + 1])
            //    return m;
            //else if (nums[m] > nums[m - 1] && nums[m] < nums[m + 1]) // ��ɽ����������
            //    l = m + 1;
            //else
            //    r = m - 1;

            pair<int, int> neighbour = getNeighbours(nums, m);
            if (nums[m] >= neighbour.first && nums[m] >= neighbour.second)//���豣֤��nums[i] != nums[i + 1]������֮����ʹ�õ��ڣ���Ϊ���ų�nums[i] = -2^31����INT_MIN�����
                return m;
            else if (nums[m] >= neighbour.first && nums[m] <= neighbour.second) // ��ɽ����������
                l = m + 1;
            else
                r = m - 1;
        }
        return 0;


    }
};