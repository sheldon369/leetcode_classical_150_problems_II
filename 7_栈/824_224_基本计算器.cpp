#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
#include <vector>
#include <iostream>
using namespace std;

//����һ���ַ������ʽ s ������ʵ��һ�����������������㲢��������ֵ��

//s �����֡�'+'��'-'��'('��')'���� ' ' ���
//s ��ʾһ����Ч�ı��ʽ
//'-' ��������һԪ����(�� "-1" �� "-(2 + 3)" ����Ч��)
//�����в��������������Ĳ�����

//������ɨ�赽�ո�ֱ���������������
//��1��ÿ�����������žͽ���һ����ջ��������������ջ����ֵ�������ݹ����㣬���ǵݹ����Ŀ�������
//��2���˹�ȥ���ţ��ж�ÿ������ȥ���ŵı��ʽ�е�ʵ�ʷ��ţ�
//ÿ�����������Ž�������֮ǰ�ķ��ź�ջ�����������ѹ��ջ�����������ź󵯳�

class Solution {
public:
    int calculate(string str) {
        stack<int> st;
        st.push(1);
        long res = 0;
        string s{};
        for (char c : str) {//ִ��ȥ�ո�
            if (c != ' ')
                s += c;
        }
        for (int i = 0;i < s.size();i++) {
            if (s[i] == '(') {
                if (i == 0)//(֮ǰ����һ���Ƿ��ţ�����(Ϊ�׸��ַ�
                    st.push(1);
                else
                    st.push((s[i - 1] == '-' ? -1 : 1) * st.top());// (֮ǰ������Ȼ�ǣ�������ֻ��Ҫ��������-���µķ��ŷ�ת����
            }
            else if (s[i] == ')') {// )ֱ����ջ
                st.pop();
            }
            else if ('0' <= s[i] && '9' >= s[i]) {//���֣����ȵõ������Լ��ķ��ţ���κ�ջ������õ�ȥ���ŵķ��ţ���ֱ��ͳ�Ƶ�res����
                long num = 0;
                int cur_sign = 1;
                if (i && s[i - 1] == '-')
                    cur_sign = -1;
                while ('0' <= s[i] && '9' >= s[i]) {
                    num = 10 * num + (s[i] - '0');
                    i++;
                }
                i--;//����
                res += cur_sign * st.top() * num;

            }
            else//��������Ȳ�����
                continue;

        }
        return res;

    }
};

int main() {
    Solution sol;

    // �̶���������
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

    // ֧���û�����
    cout << "\n������һ�����ʽ: ";
    string input;
    getline(cin, input);
    cout << "���: " << sol.calculate(input) << endl;

    return 0;
}
