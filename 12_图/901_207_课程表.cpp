#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//�����ѧ�ڱ���ѡ�� numCourses �ſγ̣���Ϊ 0 �� numCourses - 1 ��
//��ѡ��ĳЩ�γ�֮ǰ��ҪһЩ���޿γ̡� ���޿γ̰����� prerequisites ���������� prerequisites[i] = [ai, bi] ����ʾ���Ҫѧϰ�γ� ai �� ���� ��ѧϰ�γ�  bi ��
//���磬���޿γ̶�[0, 1] ��ʾ����Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��
//�����ж��Ƿ����������пγ̵�ѧϰ��������ԣ����� true �����򣬷��� false ��

//��������������ͼ���ж��޻�-->��������.�����Ǵ�һ�����Ϊ0�ĵ㿪ʼɾ�����ܿ�������ɾ����ȫ���㣬�����л�

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> neighbours(numCourses);
        unordered_map<int, int> inDegree;
        for (auto prerequisite : prerequisites) {
            neighbours[prerequisite[0]].push_back(prerequisite[1]);//��¼������Ϣ
            inDegree[prerequisite[1]]++;
        }
        for (int i = 0;i < numCourses;i++) {//����ɾ������
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

//ʱ��ռ临�Ӷȶ����ߣ�Ϊ��������indegree = 0����Ҫ�ظ���������
//�Ż�����ƹ������У������Ϊ0�Ľ����뵽���У�������Ϊ���һ�����δ���뵽���еĽ�㣬����ѧϰ�Ŀγ���С���ܿγ���ʱ�����л� 
