#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��
//�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log(m + n)) ��

//����ת��ΪѰ������ϲ����k��Ԫ�أ� ��nums.sizeΪn����nΪż����Ѱ�� n/2 -1 .n/2,��nΪ������Ѱ�� n/2
//ֱ�ӽ�����ϲ������ӷ�O(m+n)����ʱ
//log���Ƕ��֣�ÿ������ȡ������������С�� k��Ԫ�أ�һ������ȡk/2����һ������ȡk - k/2
//�Ƚ���ĩ������Ԫ�أ���С��Ԫ���������Ԫ��֮ǰ�������������ǵ�k���Ԫ�أ�ȫ���ų���������k
//ʵ������� ȡ������С��k�����㷨��Ȼ���ã���Ӧ�������������޵����

class Solution {
public:
    int findKthElement(vector<int>& nums1, vector<int>& nums2, int k) {
        int res;
        int begin1 = 0;
        int begin2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (k >= 2 && begin1 != n1 && begin2 != n2) {
            int a = k / 2;
            int b = k - a;
            int end1 = begin1 + a - 1 < n1 ? begin1 + a -1 : n1 - 1;
            int end2  = begin2 + b - 1 < n2 ? begin2 + b - 1 : n2 - 1;
            if (nums1[end1] < nums2[end2]) {//�ų�a
                  k = k - end1 + begin1 - 1;
                  begin1 = end1 + 1;
           
            }
            else {
                k = k - end2 + begin2 - 1;
                begin2 = end2 + 1;
        
            }   
        }//���˳�ѭ��ʱk = 1�������������д���һ������Ϊ��
        if (begin1 == n1) 
            return nums2[begin2 + k - 1];
        else if (begin2 == n2)
            return nums1[begin1 + k - 1];
        else
            return min(nums1[begin1], nums2[begin2]);

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if (n % 2)
            return (double)findKthElement(nums1, nums2, n / 2 + 1);
        else
            return (double)(findKthElement(nums1, nums2, n / 2) + findKthElement(nums1, nums2, n / 2 + 1))/2;

    }
};

int main() {
    vector<int> num1{ 1,3 };
    vector<int> num2{ 2 };
    Solution sol;
    sol.findMedianSortedArrays(num1, num2);



}