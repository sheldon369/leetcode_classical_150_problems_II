#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {

	//1.����ջ
	stack<int> myStack;


	//2.ѹջ
	for (int i = 0; i < 10; i++) {
		myStack.push(i);
	}

	//3.��ջ
	for (int i = 0; i < 10; i++) {
		myStack.pop();
	}

	//4.��ȡջ��Ԫ�ء���top
	printf("top = %d\n", myStack.top());

	//5.�ж϶����Ƿ�Ϊ�ա���empty
	if (myStack.empty()) {
		printf("myStack is empty\n");
	}

	return 0;
}