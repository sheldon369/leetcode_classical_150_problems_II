#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ�������� n����дһ����������ȡһ���������Ķ�������ʽ������������Ʊ��ʽ�� ����λ �ĸ�����Ҳ����Ϊ�������������������Ʊ�ʾ��1�ĸ�������
class Solution {
public:
    int hammingWeight1(int n) {
        int count = 0;
        int m = 1;
        while (m <= n) {
            count += (n & m);
            m *= 2;//m���׳���int�ı�ʾ��Χ
        }
        return count;

    }
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0) {
            count += (n & 1);
            n >>= 1;
            
        }
        return count;

    }
};