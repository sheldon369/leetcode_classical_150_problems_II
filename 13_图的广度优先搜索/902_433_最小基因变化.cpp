#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。
//假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。
//例如，"AACCGGTT" -- > "AACCGGTA" 就是一次基因变化。
//另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）
//给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 - 1 。
//注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

//分析：考察基因库与起始序列，若任意两个序列间只有一个字符不同，则为两结点建立一条边
//问题转化为考察两点之间的最短路径，即以一个点为源点，到另一个点的bfs长度，可以参考二叉数的层序遍历传递深度参数，也可以参考909中做法，保证对每个点按层次只访问一次，第一次的值必然是最短路径
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
        unordered_map<string, int> isVisited;//1为visit过
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