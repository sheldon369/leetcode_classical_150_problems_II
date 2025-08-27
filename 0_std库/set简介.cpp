#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector> 
#include <set> 
#include <unordered_set>
using namespace std;

//set自动排序，底层是红黑树，unordered_set可实现O（1）时间的查询
//set和map用法基本一致
int main() {
	//构造
	set<int> set1 = { 1,3,5 };
	multiset<int> set2 = { 1,3,5,1,3,5 };
	unordered_set<int> set3 = { 2,4,6 };
	unordered_multiset<int> set4 = { 2,4,6,2,4,6 };

	//新增元素
	set1.insert(2);
	set1.insert(1);//set不允许重复，所以该语句无效  ——>set可用于去重
	set2.insert(2);
	set2.insert(1);//multiset允许重复，该语句有效

	//删除元素(不需要使用迭代器指明其位置)
	set1.erase(1);
	set2.erase(2);//所有的1都被删掉了

	//遍历set4
	unordered_multiset<int>::iterator it;
	for (it = set4.begin(); it != set4.end(); it++) {
		printf("%d ", *it);
	}

	//查找
	//find 查找元素位置（返回值为迭代器），找不到返回尾后迭代器——迭代器没什么用，因为set不关心存储位置
	if (set3.find(1) == set3.end()) {
		printf("1 is not in set\n");
	}
	else {
		printf("1 is in set\n");
	}
	//count 获取元素数量，用于查找元素
	printf("2 occurs %d times\n", set3.count(2));

	//set不允许直接修改,如不能把set中的1改成2，可以先删除，后插入



}
