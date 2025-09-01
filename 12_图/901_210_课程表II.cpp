#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//ͬ901_207���γ̱�
//������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳����ֻҪ���� ����һ�� �Ϳ����ˡ����������������пγ̣����� һ�������� ��

//������������빤�����е��Ż�

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbours(numCourses);
        unordered_map<int, int> inDegree;
        vector<int> ans;
        for (auto prerequisite : prerequisites) {
            neighbours[prerequisite[1]].push_back(prerequisite[0]);//��¼������Ϣ
            inDegree[prerequisite[0]]++;
        }
        queue<int> q;
        for (int i = 0;i < numCourses;i++) {//����ɾ������
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