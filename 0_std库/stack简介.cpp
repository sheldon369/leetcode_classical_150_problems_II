#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {

	//1.创建栈
	stack<int> myStack;


	//2.压栈
	for (int i = 0; i < 10; i++) {
		myStack.push(i);
	}

	//3.弹栈
	for (int i = 0; i < 10; i++) {
		myStack.pop();
	}

	//4.获取栈顶元素——top
	printf("top = %d\n", myStack.top());

	//5.判断队列是否为空——empty
	if (myStack.empty()) {
		printf("myStack is empty\n");
	}

	return 0;
}