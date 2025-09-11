#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//������������ left �� right ����ʾ����[left, right] �����ش��������������� ��λ�� �Ľ�������� left ��right �˵㣩��
//0 <= left <= right <= 231 - 1

//��λ��ֻҪ��һ��Ϊ0����ȫ��Ϊ0�������ڵ��������ڵ�λ��Ȼ��ͬ���������ת��Ϊ�ҵ���󹫹�ǰ׺
//���Ǵӵ�30λ�ѵ�0λ�����ȶ�һ�£����� res |=  x << i һ���ȶԲ�һ�£������res

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res{ 0 };
        for (int i = 30;i >= 0;--i) {
            if (((left >> i) & 1) == ((right >> i) & 1))
                res |= ((left >> i) & 1) << i;
            else
                return res;

        }
        return res;

    }
};

