#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

//给你一个 无重叠的 ，按照区间起始端点排序的区间列表 intervals，其中 intervals[i] = [starti, endi] 表示第 i 个区间的开始和结束，
//并且 intervals 按照 starti 升序排列。
//同样给定一个区间 newInterval = [start, end] 表示另一个区间的开始和结束。
//在 intervals 中插入区间 newInterval，使得 intervals 依然按照 starti 升序排列，且区间之间不重叠（如果有必要的话，可以合并区间）。
//返回插入之后的 intervals。

//分析：新插入区间若不和原区间合并，则有 l>r[i] 并且 r<l[i+1]
//若和原区间合并，则l或者r被包含在某段原区间中
//我们首先首个小于l的左端点，以及大于r的右端点
//若对应右端点大于l，则和左合并；若对平左端点小于右端点，则和右合并

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0];
        int r = newInterval[1];
        int flag{ 0 };
        for (vector<int> vec : intervals) {
            if (vec[1] < newInterval[0]) {//原间隔严格位于新间隔左侧
                ans.push_back(vec);
                continue;
            }
            else if (newInterval[1] >= vec[0]) {//产生交集，则更新新的左端点为较小值
                l = min(vec[0], l);
                r = max(vec[1], r);
            }
            else {
                if (flag == 0) {
                    vector<int> merged;
                    merged.push_back(l);
                    merged.push_back(r);
                    ans.push_back(merged);
                    flag = 1;
                }
                ans.push_back(vec);
            }
        }
        if (flag == 0) {//只有右边还有区间，才会重新写入，因此我们要额外判断一次以防右边没有区间
            vector<int> merged;
            merged.push_back(l);
            merged.push_back(r);
            ans.push_back(merged);
            flag = 1;
        }
        return ans;




    }
};