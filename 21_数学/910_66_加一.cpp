#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ����ʾ ������ ���������� digits������ digits[i] �������ĵ� i λ���֡���Щ���ְ������ң������λ�����λ���С�����������������κ�ǰ�� 0��
//���������� 1�������ؽ�����������顣

//����������824_2_�������

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        int carry = 1;
        while (carry && n >= 0 ) {
            digits[n] += carry;
            carry = digits[n] / 10;
            digits[n] %= 10;
            n--;
        }//�˳�ѭ��ʱ carry == 0 ���� carry = 1 &&  n = -1
        if (carry == 0)
            return digits;
        else {//��carry Ϊ 1�˳���������999 ->1000ʱ
            vector<int> res{ 1 };
            for (int i = 0;i < digits.size();i++)
                res.push_back(0);
            return res;
        }
            
    }
};