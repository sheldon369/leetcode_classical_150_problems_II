#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ������ x ����� x ��һ���������������� true �����򣬷��� false ��

//������ʵ��һ�����������㷨������������������������

class Solution {
public:
    //������Ϊint�������п��ܳ���int 
    int reverseInt(int x) {
        int res{0};
        while (x > 0) {
            int remain = x % 10;
            res = 10 * res + remain;
            x /= 10;
        }
        return res;
    }

    //�Ľ������ô���ƥ��
    bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i = 0, j = s.size() - 1;i < j;++i, --j) {//���������i <j,��Ϊi��j����������Ҳ����ֱ�Ӵ��,��11
            if (s[i] != s[j])
                return false;
    
        }
        return true;

    }
};
