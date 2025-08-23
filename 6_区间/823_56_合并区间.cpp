#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
//请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

//分析:我们可以使用插旗法，则问题转化为228_汇总区间,但是问题过于复杂
//对间隔进行按照左端点进行排序，得到一系列左端点递增的区间
//设置指针l,r分别指向当前区间的左右端点，若新的左端点大于此时右端点，则重启一段新区间
//否则新的左端点必然在原区间内部，更新右端点为较大值即可

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (!intervals.size())
            return ans;
        sort(intervals.begin(), intervals.end());
        int l, r{ -1 };
        for (vector<int> vec : intervals) {
            if (vec[0] > r) {//开启新的区间
                if (r != -1) {//存老区间
                    vector<int> temp;
                    temp.push_back(l);
                    temp.push_back(r);
                    ans.push_back(temp);
                }
                l = vec[0];
                r = vec[1];
            }
            else//更新右端点为较大值
                r = max(r, vec[1]);
        }
        if (r != -1) {//最后一个区间总是需要额外存储
            vector<int> temp;
            temp.push_back(l);
            temp.push_back(r);
            ans.push_back(temp);
        }
        return ans;

    }
};