#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

//���� n ����Ŀ������ÿ����Ŀ i ��������һ�������� profits[i] ������������Ŀ��Ҫ����С�ʱ� capital[i] ��
//���������ʱ�Ϊ w ���������һ����Ŀʱ���㽫��ô����������󽫱���ӵ�������ʱ��С�
//�ܶ���֮���Ӹ�����Ŀ��ѡ�� ��� k ����ͬ��Ŀ���б��� ��������ʱ� ����������տɻ�õ�����ʱ���

//������ʹ��̰�ķ���ÿ�δ�capital < w����Ŀ�У�ѡȡprofits������Ŀ
//���ǽ�������ѣ���֤�Ѷ�Ԫ��Ϊprofit������Ŀ��ÿ�λ�ȡ�������������Ӹ����ʱ��������Ŀ

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;//�����ʱ���������

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
            for (;i < n;i++) {//ÿ���������Ŀ��Ҫɨ��ȫ����Ŀ������Ŀ�϶�ʱ��ʱ�����ǿ��Խ���Ŀ�����������У�ÿ����������������Ӳ���Ԫ��
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