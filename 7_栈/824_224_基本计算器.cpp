#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

//s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
//s 表示一个有效的表达式
//'-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
//输入中不存在两个连续的操作符

//分析：扫描到空格直接跳过，无需理会
//解1：每次遇到左括号就进入一个新栈，遇到右括号退栈弹出值，继续递归运算，但是递归计算的开销过大
//解2：人工去括号，判断每个数在去括号的表达式中的实际符号，
//每次遇到左括号将左括号之前的符号和栈顶符号运算后压入栈，遇到右括号后弹出

class Solution {
public:
    int calculate(string str) {
        stack<int> st;
        st.push(1);
        long res = 0;
        string s{};
        for (char c : str) {//执行去空格
            if (c != ' ')
                s += c;
        }
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(') {
                if (i == 0)//(之前几乎一定是符号，除非(为首个字符
                    st.push(1);
                else
                    st.push((s[i - 1] == '-' ? -1 : 1) * st.top());// (之前可能仍然是（，我们只需要主动留意-导致的符号翻转即可
            }
            else if (s[i] == ')') {// )直接退栈
                st.pop();
            }
            else if ('0' <= s[i] && '9' >= s[i]) {//数字，首先得到该数自己的符号，其次和栈顶运算得到去括号的符号，再直接统计到res当中
                long num = 0;
                int cur_sign = 1;
                if (i && s[i - 1] == '-')
                    cur_sign = -1;
                while ('0' <= s[i] && '9' >= s[i]) {
                    num = 10 * num + (s[i] - '0');
                    i++;
                }
                i--;//回退
                res += cur_sign * st.top() * num;

            }
            else//运算符号先不处理
                continue;

        }
        return res;

    }
};

int main() {
    Solution sol;

    // 固定测试用例
    vector<string> tests = {
        "1 + 1",
        " 2-1 + 2 ",
        "(1+(4+5+2)-3)+(6+8)",
        "2-(1+2)",
        "10-(2-(3+4))"
    };

    for (auto& expr : tests) {
        cout << "Expression: " << expr
            << " = " << sol.calculate(expr) << endl;
    }

    // 支持用户输入
    cout << "\n请输入一个表达式: ";
    string input;
    getline(cin, input);
    cout << "结果: " << sol.calculate(input) << endl;

    return 0;
}
