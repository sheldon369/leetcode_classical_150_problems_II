#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//同901_207，课程表
//返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

//分析：这里加入工作队列的优化

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbours(numCourses);
        unordered_map<int, int> inDegree;
        vector<int> ans;
        for (auto prerequisite : prerequisites) {
            neighbours[prerequisite[1]].push_back(prerequisite[0]);//记录有向信息
            inDegree[prerequisite[0]]++;
        }
        queue<int> q;
        for (int i = 0;i < numCourses;i++) {//控制删除次数
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            ans.push_back(cur);
            for (int n : neighbours[cur]) {
                inDegree[n]--;
                if (inDegree[n] == 0)
                    q.push(n);
            }
        }
        if (ans.size() < numCourses)
            ans.clear();   
        return ans;
    }
};