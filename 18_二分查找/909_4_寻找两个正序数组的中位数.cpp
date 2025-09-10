#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//算法的时间复杂度应该为 O(log(m + n)) 。

//问题转化为寻找数组合并后第k个元素， 令nums.size为n，若n为偶数，寻找 n/2 -1 .n/2,若n为奇数，寻找 n/2
//直接将数组合并，复杂夫O(m+n)，超时
//log考虑二分，每次我们取两个数组中最小的 k个元素，一个数组取k/2，另一个数组取k - k/2
//比较最末的两个元素，则小的元素中数组该元素之前的数都不可能是第k大的元素，全部排除，并更新k
//实际上如果 取的总数小于k，该算法依然适用，以应对数组索引超限的情况

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
            if (nums1[end1] < nums2[end2]) {//排除a
                  k = k - end1 + begin1 - 1;
                  begin1 = end1 + 1;
           
            }
            else {
                k = k - end2 + begin2 - 1;
                begin2 = end2 + 1;
        
            }   
        }//令退出循环时k = 1，或两个数组中存在一个数组为满
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