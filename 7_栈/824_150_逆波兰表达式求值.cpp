#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <vector>
using namespace std;

//给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
//请你计算该表达式。返回一个表示表达式值的整数。
//tokens[i] 是一个算符（"+"、"-"、"*" 或 "/"），或是在范围[-200, 200] 内的一个整数

class Solution {
public:
    int calculate(int y, int x, string op) {//注意操作数顺序
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