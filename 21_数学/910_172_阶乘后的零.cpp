#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ������ n ������ n! �����β�����������

//���������������0�����轫 n! д�� �����ӷֽ⣬�� һ�� 2*5 ���� һ��10������β��0
//����2����ȫ��ż�������ṩ��n! ���� n/2�� 2
//����5ֻ����5�ı��������ṩ,n! ���� n/5�� 5
//��˶�������n����Լβ��0�ĸ���������ֻ��5���ӵĸ���
//����,5���ݸ��Թ����ݴε���������5 ,25,125,625,3125,15625....����n��10000���ڣ����ǽ�����3125���ڵ��ݴ�

class Solution {
public:
    int trailingZeroes(int n) {
        return n / 5 + n / 25 + n / 125 + n / 625 + n / 3125;

    }
};