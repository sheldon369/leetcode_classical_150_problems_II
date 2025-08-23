#include <stdio.h>
#include <stack>
#include <string>
#include <map>
using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

class Solution {
public:
    bool isValid(string s) {
        stack<char> l;//只记录左括号
        map<char, char> m{ {'(',')'},{'[',']'},{'{','}'} };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                l.push(c);
            else {//此时c为右括号
                if (!l.size()) return false;
                char top = l.top();
                l.pop();
                if (c != m[top]) {
                    return false;
                }
            }
        }
        if (l.size()) return false;
        return true;
    }
};