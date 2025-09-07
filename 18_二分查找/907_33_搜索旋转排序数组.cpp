#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//�������� nums ���������У������е�ֵ ������ͬ ��
//�ڴ��ݸ�����֮ǰ��nums ��Ԥ��δ֪��ĳ���±� k��0 <= k < nums.length���Ͻ����� ������ת��ʹ�����Ϊ[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]���±� �� 0 ��ʼ ��������
//���磬[0, 1, 2, 4, 5, 6, 7] �±� 3 ��������ת����ܱ�Ϊ[4, 5, 6, 7, 0, 1, 2] ��

//���� ��ת�� ������ nums ��һ������ target ����� nums �д������Ŀ��ֵ target ���򷵻������±꣬���򷵻� - 1 ��
//��������һ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��������⡣

//������������������С�ļ���Ԫ�ض�����������Ҷ��ˣ�����������[0,...,k,k+1,..,n-1]������n[0]>n[n-1]
//��ǰ����Ԫ��Ϊm����n[m] > n[0],��˵��mλ�����,��target > n[m],ֻ����������������target < n[m], ��target > n[0]ʱ�������ѣ�����������
//�� n[m] < n[0]����mλ���Ұ룬��target < n[m],ֻ����������������target > n[m], ��target < n[0]ʱ�������ѣ�����������

//�ܽ�������������������ʱ����n[m] > n[0] && target > n[m] ,n[m] > n[0] && target < n[m] &&  target < n[0] , n[m] < n[0] && target > n[m] && target < n[0]

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m] == target)
                return m;
            else if (nums[m] >= nums[0] && target > nums[m] ||
                nums[m] >= nums[0] && target < nums[m] && target < nums[0] ||
                nums[m] <= nums[0] && target > nums[m] && target < nums[0])//ע������ʵ����n[m] �� n[0]���б�ʵ����Ҫȡ��,��Ϊ m ���ܵ���0
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;

    }
};