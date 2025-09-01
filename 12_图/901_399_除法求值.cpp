#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
using namespace std;

//����һ������������ equations ��һ��ʵ��ֵ���� values ��Ϊ��֪���������� equations[i] = [Ai, Bi] �� values[i] ��ͬ��ʾ��ʽ Ai / Bi = values[i] ��ÿ�� Ai �� Bi ��һ����ʾ�����������ַ�����
//����һЩ������ queries ��ʾ�����⣬���� queries[j] = [Cj, Dj] ��ʾ�� j �����⣬���������֪�����ҳ� Cj / Dj = ? �Ľ����Ϊ�𰸡�
//���� ��������Ĵ� ���������ĳ���޷�ȷ���Ĵ𰸣����� - 1.0 �������𰸡���������г����˸�������֪������û�г��ֵ��ַ�����Ҳ��Ҫ�� - 1.0 �������𰸡�

//������ʹ�ò��鼯��Disjoint Set Union��ά����ͨ�����򣬲��ҽ���·��ѹ��

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int equationSize = equations.size();
        // at most 2*size variables
        // ��������2*size������
        UnionFind unionFind(2 * equationSize);

        // 1st: pre-processing
        // ��һ����Ԥ����
        unordered_map<string, int> hashmap(2 * equationSize);//���鼯ʹ��int�������±����Ԫ��
        int id = 0;
        for (int i = 0; i < equationSize; i++) {
            // get two variables
            // ��ȡ����
            string var1 = equations[i][0];
            string var2 = equations[i][1];

            // map variable to its ID
            // ����������ID��ӳ��
            if (!hashmap.count(var1)) {
                hashmap[var1] = id++;
            }
            if (!hashmap.count(var2)) {
                hashmap[var2] = id++;
            }
            unionFind.unite(hashmap[var1], hashmap[var2], values[i]);
        }

        // 2nd: inquiring
        // �ڶ�������ѯ
        int querieSize = queries.size();
        // result
        // �������
        vector<double>res(querieSize);
        for (int i = 0; i < querieSize; i++) {
            // get two variables
            // ��ȡ����
            string var1 = queries[i][0];
            string var2 = queries[i][1];

            // compute the result
            // ������������δ���ֵı�������Ϊ-1
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
        // ���ڵ�
        vector<int> parent;
        // ָ�򸸽ڵ��Ȩ��
        vector<double> weight;

    public:
        // initialize
        // ��ʼ��
        UnionFind(int n) : parent(n), weight(n, 1.0) {//��ʼ�����н��Ϊ���ڵ�
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // �� x ���ڵ��������ӵ� y ���ڵ���������Ӧequation
        void unite(int x, int y, double value) {//���鼯�ߺϱ߲�
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)//����ͬ������ϲ�
                return;
            parent[rootX] = rootY;//����x�������ϲ���y�ϣ������ǰ��Ⱥϲ���
            weight[rootX] = weight[y] * value / weight[x];
            /*
               rx---ry
              /     /
             x --- y
            */
        }

        // find parent node �Ҹ��ڵ㲢ѹ��·��
        int find(int x) {
            if (x != parent[x]) {
                int origin = parent[x];
                parent[x] = find(parent[x]);
                weight[x] *= weight[origin];//��Ȩֵ = ������Ȩֵ*��������Ȩֵ
            }
            return parent[x];
        }

        // compute the result ����������Ӧquery
        double isConnected(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY)//���ɼ��㣬�����ͬһ���ϣ������Ԫ��Ȼ��ͬ
                return weight[x] / weight[y];
            else return -1.0;
        }
    };
};