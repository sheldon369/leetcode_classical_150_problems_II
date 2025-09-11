#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

//����һ������ points ������ points[i] = [xi, yi] ��ʾ X - Y ƽ���ϵ�һ���㡣������ж��ٸ�����ͬһ��ֱ���ϡ�

//���������������ȷ��һ��ֱ�ߣ���k,bΪ���洢��������������γ�һ��ֱ�ߣ������ n choose 2 = O(n^2)���߶�
//�Ż�������б����Ҫ�õ���������Ƚ��鷳����˴����������������ɵ�ƽ���ı��ε����������˵Ľ��Ϊ0����˵��ƽ���ı������Ϊ0��������������
//a = (ax,ay),b = (bx,by) ,a �� b = axby -aybx;
//����ÿ��ѡ��һ�㣬����ı���ֻ���������Ѱ��������һ�����ظ����������ҹ�ע����һ��ֱ�����ѳ����İ������߶�������Ȼ����С�㿪ʼ���
//��֦���ԣ�������ͬʱ������ֱ�߶�����ͼ�г��������ĵ�

int gcd(int a, int b) {  //շת������������Ծ�ȷ��ʽ����������������λ�����ޣ������Ծ�ȷ������з�����
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

//�㷨�ĸ��Ӷ�̫�ߣ��ﵽO��n^3��
//�Ľ�����ĳ����Ϊ��׼��������������������б�ʣ�ʹ������ʽ��Ϊ������hash_map��
//ÿ�������n-1��б�ʣ��ܹ�n���㣬�㷨���Ӷ� O(n^2)