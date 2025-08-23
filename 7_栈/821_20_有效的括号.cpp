#include <stdio.h>
#include <stack>
#include <string>
#include <map>
using namespace std;

//����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

class Solution {
public:
    bool isValid(string s) {
        stack<char> l;//ֻ��¼������
        map<char, char> m{ {'(',')'},{'[',']'},{'{','}'} };
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[')
                l.push(c);
            else {//��ʱcΪ������
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