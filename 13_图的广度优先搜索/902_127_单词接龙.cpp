#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord->s1->s2 -> ...->sk：
//每一对相邻的单词只差一个字母。
//对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
//sk == endWord
//给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

//分析：和902_433_最小基因变化一模一样，单源最短路径，dijkstra算法

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
        unordered_map<string, int> isVisited;//1为visit过
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

//依据朴素的思路，我们可以枚举每一对单词的组合，判断它们是否恰好相差一个字符，以判断这两个单词对应的节点是否能够相连。
// 但是这样效率太低，我们可以优化建图。

//优化思路：对于单词 hit，我们创建三个虚拟节点 *it、h*t、hi*，并让 hit 向这三个虚拟节点分别连一条边即可。
//如果一个单词能够转化为 hit，那么该单词必然会连接到这三个虚拟节点之一。
//对于每一个单词，我们枚举它连接到的虚拟节点，把该单词对应的 id 与这些虚拟节点对应的 id 相连即可。
//在构造虚拟指针时，虚拟结点的创建复杂度较高，我们考虑设计id的映射减小复杂度

//当单词本的大小较小时，我们可以直接依据单词本建图，然而若数量较大时，不如依据每个单词的长度，每次变换一位找匹配的元素
//然而这仍然和字母表的大小相关，创造虚拟结点，让差一位的字符通过结点自行相连是个好办法

//法二：双向广度优先搜索
//假设beginWord的BFS构成树形结构，则搜索空间为指数级
//如果使用两个同时进行的广搜可以有效地减少搜索空间。
//一边从 beginWord 开始，另一边从 endWord 开始。
//我们每次从两边各扩展一层节点，当发现某一时刻两边都访问过同一顶点时就停止搜索。
//这就是双向广度优先搜索，它可以可观地减少搜索空间大小，从而提高代码运行效率。


