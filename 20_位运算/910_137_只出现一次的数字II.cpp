#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ���������� nums ����ĳ��Ԫ�ؽ����� һ�� �⣬����ÿ��Ԫ�ض�ǡ���� ���� �������ҳ��������Ǹ�ֻ������һ�ε�Ԫ�ء�
//�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨��ʹ�ó������ռ�����������⡣

//��������ͬ��905_136,����û�к��ʵ�������ֱ�ӽ�������⣬��ȴ�����Ƶ�˼·
//ͳ��ÿһλ��1���ֵĴ�����������ǵ���Ԫ�أ���Ȼ����3k�Σ����ÿλmod 3k����

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{ 0 };
        for (int i = 0;i < 32;i++) {
            int numOf1 = 0;
            for (int num : nums) {
                numOf1 += (num >> i) & 1;
            }
            numOf1 = numOf1 % 3;
            res |= numOf1 << i;


        }
        return res;

    }
};