#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

//一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，
//若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。
//可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
//给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

//分析：对间隔进行排序，每次选定一个间隔，若后面的间隔和该间隔有交集则取交，否则重开始新间隔
//
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int num{ 1 };
        if (!points.size())
            return 0;
        sort(points.begin(), points.end());
        int l = points[0][0];
        int r = points[0][1];
        for (int i = 1;i < points.size();i++) {
            if (points[i][0] <= r) {//有交集
                l = max(points[i][0], l);
                r = min(points[i][1], r);
            }
            else {
                num++;
                l = points[i][0];
                r = points[i][1];
            }
        }
        return num;


    }
};