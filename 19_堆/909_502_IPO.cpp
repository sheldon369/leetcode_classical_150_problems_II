#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//给你 n 个项目。对于每个项目 i ，它都有一个纯利润 profits[i] ，和启动该项目需要的最小资本 capital[i] 。
//最初，你的资本为 w 。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。
//总而言之，从给定项目中选择 最多 k 个不同项目的列表，以 最大化最终资本 ，并输出最终可获得的最多资本。

//分析：使用贪心法，每次从capital < w的项目中，选取profits最大的项目
//我们建立大根堆，保证堆顶元素为profit最大的项目，每次获取利润后，往堆中添加更多资本允许的项目

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;//按照资本升序排列

}

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int, int>> projects;
        int n = profits.size();
        for (int i = 0;i < n;i++) {
            projects.push_back({ profits[i],capital[i]});
        }
        sort(projects.begin(), projects.end(), cmp);
        int i = 0;
        while (k > 0) {
            for (;i < n;i++) {//每次添加新项目总要扫描全部项目，当项目较多时超时，我们可以将项目按照升序排列，每次增量的往堆中添加部分元素
                if (projects[i].second <= w)
                    pq.push(projects[i].first);
                else
                    break;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
                k--;
            }
            else
                return w;
           

        }
        return w;

    }
};


int main() {
    vector<int> profits{1,2,3 };
    vector<int> capital{ 0,1,2 };
    Solution sol;
    sol.findMaximizedCapital(2, 0, profits, capital);
}