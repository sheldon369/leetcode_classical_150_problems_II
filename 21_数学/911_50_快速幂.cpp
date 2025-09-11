#include <cmath>
#include <iostream>
using namespace std;



//ʵ��Pow(x,n)����x����

//������ʹ�ÿ������㷨������ x��77 �η�   1 - 2 - 4 - 9 - 19 - 38 -77
//����4 - 9��˵�x�ں���ƽ����3�Σ�������8 �� 9 - 19��˵�x������ 4 �� 38 - 77 ��˵�x������ 1
//�۲쵽 77 = 1011001������n�Ķ����Ʊ�ʾ�ж�Ӧһ���������ڼ�����ƽ�������ٳ˸�x

//��
class Solution {
public:
    double myPow(double x, int n) {
        double res{ 1 };
        double base = x;
        long int target = abs(static_cast<long>(n));//ע�⣬abs�����������������һ�£����������ֻ��target��Ϊlong,����2^31�Ի�ʧЧ
        while (target > 0) {
            if (target & 1)//�����ǰ�ݴο���ĵ�λΪ1
                res *= base;
            base *= base; //x^0 - x^1 -x^2......
            target >>= 1;
        }
        return n >= 0 ? res : 1 / res;
     


    }
};

int main(){
    Solution sol;
    cout <<sol.myPow(2.1, 3)<< '\n';

}