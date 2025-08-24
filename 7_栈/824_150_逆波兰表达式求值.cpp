#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

//����һ���ַ������� tokens ����ʾһ������ �沨����ʾ�� ��ʾ���������ʽ��
//�������ñ��ʽ������һ����ʾ���ʽֵ��������
//tokens[i] ��һ�������"+"��"-"��"*" �� "/"���������ڷ�Χ[-200, 200] �ڵ�һ������

class Solution {
public:
    int calculate(int y, int x, string op) {//ע�������˳��
        if (op == "+")  return x + y;
        else if (op == "-")  return x - y;
        else if (op == "*")  return x * y;
        else  return x / y;

    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string op : tokens) {
            if (op == "+" || op == "-" || op == "*" || op == "/") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                st.push(calculate(op1, op2, op));
            }
            else 
                st.push(stoi(op));
        
        }
        return st.top();
    }
};