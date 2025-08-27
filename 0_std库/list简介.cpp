#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <list> 
using namespace std;
//list底层是双向列表，若存在大量删除和插入操作，list的效率更高

int main() {
	list<int> ls1 = { 1,3,5,7,9 };
	//list访问元素
	ls1.back();
	ls1.end();

	//list操纵元素(双向)
	ls1.pop_back();
	ls1.push_back(2);


	list<int>::iterator it = ls1.begin();
	it++;
	it++;//list不支持it = it + 2;
	printf("*it=%d\n", *it);
	ls1.erase(it);
	for (it = ls1.begin(); it != ls1.end(); it++) {
		printf("after erase,*it = %d\n", *it);
	}

}