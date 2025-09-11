#include <cmath>
#include <iostream>
using namespace std;

//����һ���Ǹ����� x �����㲢���� x �� ����ƽ���� ��
//���ڷ������������������ֻ���� �������� ��С�����ֽ��� ��ȥ ��

//����������1����������int��Χ�����к����ƽ��
//�Ż������ֲ��ң��� sqrt(x),��Ȼ�� 1<= sqrt(x) <= x

//���ֲ���ʧ��ʱ��lָ��Ӧ�ò����λ�ã�����l-1
class Solution {
public:
    int mySqrt(int x) {
        int l = 1;
        int r = x;
        while (l <= r) {
            int mid = l + (r - l) / 2;
       
            if (mid > 46340 || mid * mid > x)  //int�ܱ�ʾ���������С�� 2^31,�򿪸�С�� 2^15 * sqrt 2 =32768 * 1.414 =  46340.9 ��ע����б�Ҫ�ڼ��� mid * mid֮ǰ
                r = mid - 1;
            else if (mid * mid == x)
                return mid;
            else
                l = mid + 1;
           
           

        }
        return l - 1;

    }
};
