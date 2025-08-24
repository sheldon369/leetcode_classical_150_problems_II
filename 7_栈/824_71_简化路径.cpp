#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
using namespace std;

//�� Unix �����ļ�ϵͳ�й������£�
//
//һ���� '.' ��ʾ��ǰĿ¼����
//���⣬������ '..' ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼����
//������������б�ܣ�����'//' �� '///'��������Ϊ����б�� '/'��
//�κ�������ʽ�ĵ㣨���磬'...' �� '....'��������Ϊ��Ч���ļ� / Ŀ¼���ơ�
//���ص� ��·�� ������ѭ������ʽ��
//
//ʼ����б�� '/' ��ͷ��
//����Ŀ¼��֮�����ֻ��һ��б�� '/' ��
//���һ��Ŀ¼����������ڣ����� �� '/' ��β��
//���⣬·���������Ӹ�Ŀ¼��Ŀ���ļ���Ŀ¼��·���ϵ�Ŀ¼���������� '.' �� '..'����
//���ؼ򻯺�õ��� �淶·�� ��

//������ÿ�δ�һ��б�ܿ�ʼ��ֱ����������һ��б�ܣ��м�Ķ����Ϸ��Ķ�������list�������Ҫ���У�
//������Ҫע����б�ܣ���֮ǰ��Ԫ��Ϊ'/'�����µ�Ԫ�ز�д����ʱstr
//'/.'ֱ�Ӻ���,'/..'��ջ��Ϊ�գ���ջ����ջ�ĳ��Ȳ�Ϊ1���򲻼���β��'/'Ԫ��

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';//ǿ�Ʊ�֤path��/��β���Ӷ���ȡ /xxxx
        list<string> stack;
        int i = 0;
        string temp{};
        while (i < path.size()) {
            if (i == 0)
                temp += path[i++];// д��/
            else if (path[i] == '/' && path[i - 1] == '/') {
                i++;
                continue;
            }
            else if (path[i] != '/' )
                temp += path[i++];
            else {//������һ��/,����stackд��
                i++;
                if (temp == "/.") {
                    temp = '/';
                    continue;
                }
                else if (temp == "/..") {
                    if (stack.size())
                        stack.pop_back();
                    temp = '/';
                }
                else {
                    stack.push_back(temp);
                    temp = '/';//���һ��'/'����Ͳ�д��stack
                }
         
            }

        }
        string ans;
        if(!stack.size())
            return temp;
        for (string s : stack) {
            ans += s;
        }
    
        return ans;
        


    }
};