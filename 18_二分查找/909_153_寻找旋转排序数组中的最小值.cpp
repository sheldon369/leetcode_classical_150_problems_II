#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//��֪һ������Ϊ n �����飬Ԥ�Ȱ����������У����� 1 �� n �� ��ת �󣬵õ��������顣���磬ԭ���� nums = [0, 1, 2, 4, 5, 6, 7] �ڱ仯����ܵõ���
//����ת 4 �Σ�����Եõ�[4, 5, 6, 7, 0, 1, 2]
//����ת 7 �Σ�����Եõ�[0, 1, 2, 4, 5, 6, 7]
//ע�⣬����[a[0], a[1], a[2], ..., a[n - 1]] ��תһ�� �Ľ��Ϊ����[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] ��

//����һ��Ԫ��ֵ ������ͬ ������ nums ����ԭ����һ���������е����飬�����������ν����˶����ת�������ҳ������������е� ��СԪ�� ��
//��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

//������������������907_33_������ת�������飬�������Ϊ����СԪ�� ����ָ��Ԫ��
//˼·���� ,���м�Ԫ�أ��� n[m] ���� n[0] ,��˵��m�Դ���������䣬����������
//��n[m] < n[0],��˵���ѵ��Ұ������ˣ���ʱ����n[0] Ϊ n[m],��������������

class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r) {
        int res = nums[0];
        while (l <= r) {
            int midIdx = l + (r - l) / 2;
            int mid = nums[midIdx];
            if (mid >= res) {
                l = midIdx+ 1;
            }
            else {
                r = midIdx - 1;
                res = mid;
            }

        }
        return res;

    }




    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};


int main() {
    vector<int> num1{ 3,4,5,1,2 };
    Solution sol;
    sol.findMin(num1);



}