#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//�������п��Ա�ʾΪһ���� 8 ���ַ���ɵ��ַ���������ÿ���ַ����� 'A'��'C'��'G' �� 'T' ֮һ��
//����������Ҫ����ӻ������� start ��Ϊ end �������Ļ���仯��һ�λ���仯����ζ��������������е�һ���ַ������˱仯��
//���磬"AACCGGTT" -- > "AACCGGTA" ����һ�λ���仯��
//����һ������� bank ��¼��������Ч�Ļ���仯��ֻ�л�����еĻ��������Ч�Ļ������С����仯��Ļ������λ�ڻ���� bank �У�
//���������������� start �� end ���Լ�һ������� bank �������ҳ��������ܹ�ʹ start �仯Ϊ end ��������ٱ仯����������޷���ɴ˻���仯������ - 1 ��
//ע�⣺��ʼ�������� start Ĭ������Ч�ģ�����������һ��������ڻ�����С�

//������������������ʼ���У��������������м�ֻ��һ���ַ���ͬ����Ϊ����㽨��һ����
//����ת��Ϊ��������֮������·��������һ����ΪԴ�㣬����һ�����bfs���ȣ����Բο��������Ĳ������������Ȳ�����Ҳ���Բο�909����������֤��ÿ���㰴���ֻ����һ�Σ���һ�ε�ֵ��Ȼ�����·��
class Solution {
private:
    unordered_map<string, vector<string>> change;
public:
    bool isLeagalChange(string a, string b) {
        int count = 0;
        for (int i = 0;i < 8;i++) {
            if (a[i] == b[i])
                count++;
        }
        if (count == 7)
            return true;
        return false;
    }


    void buildLeagalChange(string startGene, vector<string>& bank) {
        bank.push_back(startGene);
        int n = bank.size();
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                if (isLeagalChange(bank[i], bank[j])) {
                    change[bank[i]].push_back(bank[j]);
                    change[bank[j]].push_back(bank[i]);
                }
            }
        }
    }


    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> step;
        unordered_map<string, int> isVisited;//1Ϊvisit��
        buildLeagalChange(startGene, bank);
        queue<string> q;
        q.push(startGene);
        while (!q.empty()) {
            string cur = q.front();
            isVisited[cur] = 1;
            q.pop();
            for (auto neighbour : change[cur]) {
                if (!isVisited[neighbour]) {
                    isVisited[neighbour] = 1;
                    step[neighbour] = step[cur] + 1;
                    if (neighbour == endGene)
                        return step[neighbour];
                    q.push(neighbour);
                }
            }

        }
        return -1;

    }
};