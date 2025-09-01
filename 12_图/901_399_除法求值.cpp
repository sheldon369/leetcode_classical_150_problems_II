#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

//给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
//另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
//返回 所有问题的答案 。如果存在某个无法确定的答案，则用 - 1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 - 1.0 替代这个答案。

//分析：使用并查集（Disjoint Set Union）维护连通的区域，并且进行路径压缩

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int equationSize = equations.size();
        // at most 2*size variables
        // 最坏情况下有2*size个变量
        UnionFind unionFind(2 * equationSize);

        // 1st: pre-processing
        // 第一步：预处理
        unordered_map<string, int> hashmap(2 * equationSize);//并查集使用int型索引下标访问元素
        int id = 0;
        for (int i = 0; i < equationSize; i++) {
            // get two variables
            // 提取变量
            string var1 = equations[i][0];
            string var2 = equations[i][1];

            // map variable to its ID
            // 建立变量到ID的映射
            if (!hashmap.count(var1)) {
                hashmap[var1] = id++;
            }
            if (!hashmap.count(var2)) {
                hashmap[var2] = id++;
            }
            unionFind.unite(hashmap[var1], hashmap[var2], values[i]);
        }

        // 2nd: inquiring
        // 第二步：查询
        int querieSize = queries.size();
        // result
        // 结果数组
        vector<double>res(querieSize);
        for (int i = 0; i < querieSize; i++) {
            // get two variables
            // 提取变量
            string var1 = queries[i][0];
            string var2 = queries[i][1];

            // compute the result
            // 计算结果，若有未出现的变量则结果为-1
            if (!hashmap.count(var1) || !hashmap.count(var2))
                res[i] = -1.0;
            else
                res[i] = unionFind.isConnected(hashmap[var1], hashmap[var2]);
        }

        return res;
    }

private:
    // disjoint-set-union data structure
    class UnionFind {
    private:
        // 父节点
        vector<int> parent;
        // 指向父节点的权重
        vector<double> weight;

    public:
        // initialize
        // 初始化
        UnionFind(int n) : parent(n), weight(n, 1.0) {//初始化所有结点为根节点
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // 将 x 所在的子树连接到 y 所在的子树，对应equation
        void unite(int x, int y, double value) {//并查集边合边查
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)//根相同则无需合并
                return;
            parent[rootX] = rootY;//否则将x所在树合并到y上（不考虑按秩合并）
            weight[rootX] = weight[y] * value / weight[x];
            /*
               rx---ry
              /     /
             x --- y
            */
        }

        // find parent node 找父节点并压缩路径
        int find(int x) {
            if (x != parent[x]) {
                int origin = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];//新权值 = 到父的权值*父到根的权值
            }
            return parent[x];
        }

        // compute the result 计算结果，对应query
        double isConnected(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)//若可计算，则必在同一集合，则代表元必然相同
                return weight[x] / weight[y];
            else return -1.0;
        }
    };
};