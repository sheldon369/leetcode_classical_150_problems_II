#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <list> 
using namespace std;
//list�ײ���˫���б������ڴ���ɾ���Ͳ��������list��Ч�ʸ���

int main() {
	list<int> ls1 = { 1,3,5,7,9 };
	//list����Ԫ��
	ls1.back();
	ls1.end();

	//list����Ԫ��(˫��)
	ls1.pop_back();
	ls1.push_back(2);


	list<int>::iterator it = ls1.begin();
	it++;
	it++;//list��֧��it = it + 2;
	printf("*it=%d\n", *it);
	ls1.erase(it);
	for (it = ls1.begin(); it != ls1.end(); it++) {
		printf("after erase,*it = %d\n", *it);
	}

}