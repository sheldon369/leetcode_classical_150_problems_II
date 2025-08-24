#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
using namespace std;

//���һ��֧�� push ��pop ��top �����������ڳ���ʱ���ڼ�������СԪ�ص�ջ��
//ʵ�� MinStack �� :
//MinStack() ��ʼ����ջ����
//void push(int val) ��Ԫ��val�����ջ��
//void pop() ɾ����ջ������Ԫ�ء�
//int top() ��ȡ��ջ������Ԫ�ء�
//int getMin() ��ȡ��ջ�е���СԪ�ء�

//����������ջ�е�ÿ��Ԫ�أ���������ʱջ��״̬�̶�����ӦΨһ��СԪ�أ�����ά��һ������ջ���ɣ�
//����Ԫ��ʵ�֣�����ջ�е�ÿ��Ԫ�ع���һ��������Ԫ�顣
class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }

    void push(int val) {
        if (!st.size())
            st.push({ val,val });
        else
            st.push({ val,val < st.top().second ? val : st.top().second });
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};