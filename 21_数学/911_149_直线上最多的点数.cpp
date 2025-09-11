#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//给你一个数组 points ，其中 points[i] = [xi, yi] 表示 X - Y 平面上的一个点。求最多有多少个点在同一条直线上。

//分析：两个点可以确定一条直线，以k,b为键存储，任意两点可以形成一条直线，则计算 n choose 2 = O(n^2)条线段
//优化：计算斜率需要用到除法，这比较麻烦，叉乘代表了两个向量构成的平行四边形的面积，若叉乘的结果为0，则说明平行四边形面积为0，即两向量共线
//a = (ax,ay),b = (bx,by) ,a × b = axby -aybx;
//我们每次选定一点，后序的遍历只往更大点搜寻，能削减一部分重复搜索；并且关注到，一根直线所搜出来的包含的线段数，必然从最小点开始最多
//剪枝策略：不可能同时有两条直线都涵盖图中超过半数的点

int gcd(int a, int b) {  //辗转相除法，用于以精确方式表达分数（浮点数的位数有限，不足以精确表达所有分数）
    return b ? gcd(b, a % b) : a;
}

class Solution {
public:
    pair<int, int> getVector(vector<int> p1, vector<int> p2) {
        return { p1[0] - p2[0],p1[1] - p2[1] };
    }
    int getCrossProduct(pair<int, int> v1, pair<int, int> v2) {
        return v1.first * v2.second - v1.second * v2.first;
    }
        

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return n;
        int res{ 0 };
        for (int i = 0;i < n;i++) {
            for (int j = i + 1;j < n;j++) {
                pair<int, int> base = getVector(points[i], points[j]);
                int line = 1;
                for (int k = j + 1;k < n;k++) {
                    pair<int, int> other = getVector(points[i], points[k]);
                    if (!getCrossProduct(base, other)) {
                        line++;
                    }
                }
                res = max(line + 1, res);
                
            }
        }
        return res;

    }
};

//算法的复杂度太高，达到O（n^3）
//改进：以某个点为基准，其他点计算相对这个点的斜率，使用最简分式作为键存在hash_map中
//每个点计算n-1个斜率，总共n个点，算法复杂度 O(n^2)