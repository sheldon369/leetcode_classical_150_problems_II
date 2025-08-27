#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <map>
#include <unordered_map>
using namespace std;
int main() {
	////构造map
	//map<char, int> map1;// 有序，不允许键重复
	////map<键,值>
	//multimap<char, int>  map2;//有序，允许键重复
	//unordered_map<char, int> map3;// 无序，不允许重复——经常使用，时间开销小
	//unordered_multimap<char, int> map4;// 无序，允许重复

	//// 键值对
	//pair<char, int> pair1 = {'w',0};
	////first 提出键  second 提出值
	//printf("key = %c,value = %d\n", pair1.first, pair1.second);

	////在map中新增
	//map1.insert(pair1);
	//map2.insert(pair1);
	//map2.insert({ 'o',1 });

	////在map中删除
	//map1.erase('w');//参数只需要键

	//map的遍历
	map<char, int> map1 = { {'w',0},{'0',1},{'r',2},{'l',3},{'d',4} };
	map<char, int>::iterator it;
	for (it = map1.begin(); it != map1.end(); it++) {
		printf("key = %c,value = %d\n", it->first, it->second);
	}

	//map的查找——依据键map[i]查找值
	printf("value = % d\n", map1['o']);
	printf("value = % d\n", map1['a']);//a并不存在，则map会自动新增a键，默认初始值为0

	//如果不想实现 “不存在自动新增”
	if (map1.find('a') == map1.end()) {//如果a不存在，end指向最后一个值的后一个位置
		printf("key is not in map");
	}
	if (!map1.count('a'))//map 同样支持count检索，count相较于find，无法获取值的信息，只能判断存在性
		printf("key is not in map");
	else {
		printf("value = % d\n", map1['a']);
	}

	//map的修改
	map1['o'] = 6;



	//multimap的查找——multimap不支持[]
	//low_bound(key) 返回key对应的第一个值的位置——类begin
	//upper_bound(key) 返回key对应的最后一个值的后一个值的位置——类end
	for (it = map1.lower_bound('o'); it != map1.upper_bound('o'); it++) {
		printf("key = %c,value = %d\n", it->first, it->second);
	}


	return 0;
}