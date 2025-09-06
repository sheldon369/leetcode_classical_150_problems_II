#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣

//������λ���㡪�����
//�κ����� 0 ��������㣬�����Ȼ��ԭ���������� a��0 = a��
//�κ�������������������㣬����� 0���� a��a = 0��
//����������㽻���ɺͽ���ɣ��� a��b��a = b��a��a = b��(a��a) = b��0 = b��
//������������Ԫ����������㣬���Ϊ�Ǹ�ֻ����һ�ε�Ԫ��

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res{0};
        for (int n : nums) {
            res ^= n;
        }
        return res;
    }
};