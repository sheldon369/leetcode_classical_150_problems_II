#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (target == nums[m])
                return m;
            else if (target < nums[m])
                r = m - 1;
            else
                l = m + 1;

        }//����ѯʧ��ʱ��r < l,r = l-1,l����ָ��target�ñ�˳������λ��
        return l;

    }
};

int main() {
    vector<int> vec{ 1,3,5,6 };
    Solution sol;
    sol.searchInsert(vec, 5);

}