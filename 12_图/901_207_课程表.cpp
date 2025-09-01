#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
//在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
//例如，先修课程对[0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
//请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

//分析：构建有向图，判断无环-->拓扑排序.即我们从一个入度为0的点开始删除，总可以最终删除完全部点，否则有环

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbours(numCourses);
        unordered_map<int, int> inDegree;
        for (auto prerequisite : prerequisites) {
            neighbours[prerequisite[0]].push_back(prerequisite[1]);//记录有向信息
            inDegree[prerequisite[1]]++;
        }
        for (int i = 0;i < numCourses;i++) {//控制删除次数
            int j{};
            for (j = 0;j < numCourses;j++) {
                if (inDegree[j] == 0) {
                    inDegree[j] = -1;
                    for (int n : neighbours[j])
                        inDegree[n]--;
                    break;
                }

            }
            if (j == numCourses)
                return false;
        }
        return true;
    }
};

//时间空间复杂度都过高，为了索引到indegree = 0，总要重复遍历数组
//优化：设计工作队列，将入度为0的结点加入到队列，若队列为空且还有尚未加入到队列的结点，即已学习的课程数小于总课程数时，则有环 
