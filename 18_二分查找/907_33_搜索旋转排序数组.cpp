#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//整数数组 nums 按升序排列，数组中的值 互不相同 。
//在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 向左旋转，使数组变为[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]]（下标 从 0 开始 计数）。
//例如，[0, 1, 2, 4, 5, 6, 7] 下标 3 上向左旋转后可能变为[4, 5, 6, 7, 0, 1, 2] 。

//给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 - 1 。
//你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

//分析：现在数组中最小的几个元素都在数组的最右端了，新数组形如[0,...,k,k+1,..,n-1]，其中n[0]>n[n-1]
//当前搜索元素为m，若n[m] > n[0],则说明m位于左半,若target > n[m],只可能向右搜索，若target < n[m], 当target > n[0]时，向左搜，否则向右搜
//若 n[m] < n[0]，则m位于右半，若target < n[m],只可能向左搜索，若target > n[m], 当target < n[0]时，向右搜，否则向左搜

//总结下来，我们向右搜索时，有n[m] > n[0] && target > n[m] ,n[m] > n[0] && target < n[m] &&  target < n[0] , n[m] < n[0] && target > n[m] && target < n[0]

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
                nums[m] <= nums[0] && target > nums[m] && target < nums[0])//注意这里实际上n[m] 与 n[0]的判别实际上要取等,因为 m 可能等于0
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;

    }
};