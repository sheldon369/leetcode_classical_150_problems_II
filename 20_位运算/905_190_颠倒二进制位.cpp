#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//�ߵ������� 32 λ�޷��������Ķ�����λ��

//������λ�����У���ʹ���ǲ�����������������ʵ�����ڲ�����Ӧ�Ķ�������
class Solution {
public:
    int reverseBits(int n) {
        unsigned int res = 0;
        for (int i = 0;i < 32;i++) {
            res <<= 1;//res����һλ�����һλ�ڸ�0����
            res |= (n & 1);//res�ڳ���һλ0ȡ n��ĩλ
            n >>= 1;

        }
        return res;

    }
};