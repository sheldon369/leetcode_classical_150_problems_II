#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

//����һ�� ���ص��� ������������ʼ�˵�����������б� intervals������ intervals[i] = [starti, endi] ��ʾ�� i ������Ŀ�ʼ�ͽ�����
//���� intervals ���� starti �������С�
//ͬ������һ������ newInterval = [start, end] ��ʾ��һ������Ŀ�ʼ�ͽ�����
//�� intervals �в������� newInterval��ʹ�� intervals ��Ȼ���� starti �������У�������֮�䲻�ص�������б�Ҫ�Ļ������Ժϲ����䣩��
//���ز���֮��� intervals��

//�������²�������������ԭ����ϲ������� l>r[i] ���� r<l[i+1]
//����ԭ����ϲ�����l����r��������ĳ��ԭ������
//���������׸�С��l����˵㣬�Լ�����r���Ҷ˵�
//����Ӧ�Ҷ˵����l�������ϲ�������ƽ��˵�С���Ҷ˵㣬����Һϲ�

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int l = newInterval[0];
        int r = newInterval[1];
        int flag{ 0 };
        for (vector<int> vec : intervals) {
            if (vec[1] < newInterval[0]) {//ԭ����ϸ�λ���¼�����
                ans.push_back(vec);
                continue;
            }
            else if (newInterval[1] >= vec[0]) {//����������������µ���˵�Ϊ��Сֵ
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
        if (flag == 0) {//ֻ���ұ߻������䣬�Ż�����д�룬�������Ҫ�����ж�һ���Է��ұ�û������
            vector<int> merged;
            merged.push_back(l);
            merged.push_back(r);
            ans.push_back(merged);
            flag = 1;
        }
        return ans;




    }
};