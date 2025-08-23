#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

//һ֧������������ x ��Ӳ�ͬ�� ��ȫ��ֱ ������������� x �����һ֧����
//����һ�������ֱ���Ŀ�ʼ�ͽ�������Ϊ xstart��xend�� ������  xstart �� x �� xend���������ᱻ ���� ��
//��������Ĺ��������� û������ �� ����һ�������֮�󣬿������޵�ǰ����
//����һ������ points ����������������������������� ��С ������ ��

//�������Լ����������ÿ��ѡ��һ�������������ļ���͸ü���н�����ȡ���������ؿ�ʼ�¼��
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
            if (points[i][0] <= r) {//�н���
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