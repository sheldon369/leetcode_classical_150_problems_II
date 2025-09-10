#include <map>
#include <unordered_map>
#include <set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2, 以及一个整数 k 。
//定义一对值(u, v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
//请找到和最小的 k 个数对(u1, v1), (u2, v2)  ...  (uk, vk) 。

//分析，类似归并排序，每次取出当前指针指向的位置，然后下一位置中较小的指针更新位置； --错误，指针并不总是向右移，有可能一个向右，另一个向左

//使用小根堆，初始时把堆顶元素元素放入堆中，每次从堆中取出堆顶，然后加入在堆中加入下两个数，这样新加入的数总是比已取的更大，且之间不存在没有考虑过的情况



class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;

        using T = tuple<int, int, int>;//使用 T 代指某类型
        auto cmp = [](const T& a, const T& b) {
            return get<0>(a) > get<0>(b);
            };
        priority_queue<T, vector<T>, decltype(cmp)> minHeap(cmp);
        minHeap.push({ nums1[0] + nums2[0],0,0,});

        set<pair<int,int>> isVisited;
        //isVisited.insert({ 0,0 });
        while (!minHeap.empty() && k > 0) {

            auto cur = minHeap.top();
            res.push_back({ nums1[get<1>(cur)],nums2[get<2>(cur)] });
            minHeap.pop();
            k--;
            if (get<1>(cur) + 1 < nums1.size() && !isVisited.count({ get<1>(cur) + 1 , get<2>(cur) })) {
                minHeap.push({ nums1[get<1>(cur) + 1] + nums2[get<2>(cur)],get<1>(cur) + 1 ,get<2>(cur) });
                isVisited.insert({ get<1>(cur) + 1 , get<2>(cur) });

            }
     
            if (get<2>(cur) + 1 < nums2.size() && !isVisited.count({ get<1>(cur)  , get<2>(cur) + 1 })) {
                minHeap.push({ nums1[get<1>(cur)] + nums2[get<2>(cur) + 1],get<1>(cur) ,get<2>(cur) + 1 });
                isVisited.insert({ get<1>(cur) , get<2>(cur) + 1 });


            }
               
        }

        return res;

    }
};

int main() {
    vector<int> nums1{ 1,7,11 };
    vector<int> nums2{ 2,4,6 };
    Solution sol;
    sol.kSmallestPairs(nums1,nums2, 3);
}