#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord->s1->s2 -> ...->sk��
//ÿһ�����ڵĵ���ֻ��һ����ĸ��
//���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList �С�
//sk == endWord
//������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ �����������������ת�����У����� 0 ��

//��������902_433_��С����仯һģһ������Դ���·����dijkstra�㷨

class Solution {
private:
    unordered_map<string, vector<string>> change;
public:
    bool isLeagalChange(string a, string b) {
        int count = 0;
        int n = a.size();
        for (int i = 0;i < n;i++) {
            if (a[i] == b[i])
                count++;
        }
        if (count == n - 1)
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> step;
        unordered_map<string, int> isVisited;//1Ϊvisit��
        buildLeagalChange(beginWord, wordList);
        if (!change.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        isVisited[beginWord] = 1;
        step[beginWord] = 1;
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto neighbour : change[cur]) {
                if (!isVisited[neighbour]) {
                    isVisited[neighbour] = 1;
                    step[neighbour] = step[cur] + 1;
                    if (neighbour == endWord)
                        return step[neighbour];
                    q.push(neighbour);
                }
            }

        }
        return 0;

    }
};

//�������ص�˼·�����ǿ���ö��ÿһ�Ե��ʵ���ϣ��ж������Ƿ�ǡ�����һ���ַ������ж����������ʶ�Ӧ�Ľڵ��Ƿ��ܹ�������
// ��������Ч��̫�ͣ����ǿ����Ż���ͼ��

//�Ż�˼·�����ڵ��� hit�����Ǵ�����������ڵ� *it��h*t��hi*������ hit ������������ڵ�ֱ���һ���߼��ɡ�
//���һ�������ܹ�ת��Ϊ hit����ô�õ��ʱ�Ȼ�����ӵ�����������ڵ�֮һ��
//����ÿһ�����ʣ�����ö�������ӵ�������ڵ㣬�Ѹõ��ʶ�Ӧ�� id ����Щ����ڵ��Ӧ�� id �������ɡ�
//�ڹ�������ָ��ʱ��������Ĵ������ӶȽϸߣ����ǿ������id��ӳ���С���Ӷ�

//�����ʱ��Ĵ�С��Сʱ�����ǿ���ֱ�����ݵ��ʱ���ͼ��Ȼ���������ϴ�ʱ����������ÿ�����ʵĳ��ȣ�ÿ�α任һλ��ƥ���Ԫ��
//Ȼ������Ȼ����ĸ��Ĵ�С��أ����������㣬�ò�һλ���ַ�ͨ��������������Ǹ��ð취

//������˫������������
//����beginWord��BFS�������νṹ���������ռ�Ϊָ����
//���ʹ������ͬʱ���еĹ��ѿ�����Ч�ؼ��������ռ䡣
//һ�ߴ� beginWord ��ʼ����һ�ߴ� endWord ��ʼ��
//����ÿ�δ����߸���չһ��ڵ㣬������ĳһʱ�����߶����ʹ�ͬһ����ʱ��ֹͣ������
//�����˫�������������������Կɹ۵ؼ��������ռ��С���Ӷ���ߴ�������Ч�ʡ�


