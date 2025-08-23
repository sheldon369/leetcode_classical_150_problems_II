#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

//������ intervals ��ʾ���ɸ�����ļ��ϣ����е�������Ϊ intervals[i] = [starti, endi] ��
//����ϲ������ص������䣬������ һ�����ص����������飬��������ǡ�ø��������е��������� ��

//����:���ǿ���ʹ�ò��취��������ת��Ϊ228_��������,����������ڸ���
//�Լ�����а�����˵�������򣬵õ�һϵ����˵����������
//����ָ��l,r�ֱ�ָ��ǰ��������Ҷ˵㣬���µ���˵���ڴ�ʱ�Ҷ˵㣬������һ��������
//�����µ���˵��Ȼ��ԭ�����ڲ��������Ҷ˵�Ϊ�ϴ�ֵ����

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (!intervals.size())
            return ans;
        sort(intervals.begin(), intervals.end());
        int l, r{ -1 };
        for (vector<int> vec : intervals) {
            if (vec[0] > r) {//�����µ�����
                if (r != -1) {//��������
                    vector<int> temp;
                    temp.push_back(l);
                    temp.push_back(r);
                    ans.push_back(temp);
                }
                l = vec[0];
                r = vec[1];
            }
            else//�����Ҷ˵�Ϊ�ϴ�ֵ
                r = max(r, vec[1]);
        }
        if (r != -1) {//���һ������������Ҫ����洢
            vector<int> temp;
            temp.push_back(l);
            temp.push_back(r);
            ans.push_back(temp);
        }
        return ans;

    }
};