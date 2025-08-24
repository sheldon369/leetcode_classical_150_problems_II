#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
using namespace std;

//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//实现 MinStack 类 :
//MinStack() 初始化堆栈对象。
//void push(int val) 将元素val推入堆栈。
//void pop() 删除堆栈顶部的元素。
//int top() 获取堆栈顶部的元素。
//int getMin() 获取堆栈中的最小元素。

//分析：对于栈中的每个元素，当它存在时栈的状态固定，对应唯一最小元素，我们维护一个辅助栈即可，
//或用元组实现，对于栈中的每个元素构造一个关联的元组。
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