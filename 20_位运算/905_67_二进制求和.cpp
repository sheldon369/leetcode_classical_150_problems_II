#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//���������������ַ��� a �� b ���Զ������ַ�������ʽ�������ǵĺ͡�

class Solution {
public:
    string addBinary(string a, string b) {
        if (a.length() < b.length())//��֤a�ĳ��ȴ��ڵ���b�ĳ���
            swap(a, b);
        string s;
        for (int i = 0;i < a.length() - b.length();i++) {
            s += '0';
        }
        s += b;
        b = s;//��b��λ��0,���ಹһ��0
        deque<char> dq;
        int carry = 0;
        for (int i = a.length() - 1;i >= 0;i--) {
            
            int sum = ((a[i] - '0') + (b[i] - '0') + carry) % 2;
            carry = ((a[i] - '0') + (b[i] - '0') + carry)/ 2;
            dq.push_front('0'+ sum);
        }
        if (carry == 1)
            dq.push_front('1');

        a = string(dq.begin(),dq.end() );
        return a;

    }
};