#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

int main() {

	//string类似内置类型的操作
	//1.string支持 = 赋值
	string str1 = "Hello,";
	string str2 = "World!";
	string str3;
	str3 = "Hello,";
	str3 = str2;

	string name0{}; // 空 string
	string name{ "Fly" }; // 列表初始化变量 name，值为 "Fly"
	name = "John";               // 赋值"John"给变量 name ，string可以用于保存不同大小的字符串
	string myID{ "45" };//string可以用数字赋值

	//2.string支持 == 判断内容是否相同
	bool isSame = false;
	isSame = (str3 == str2);

	//3.string支持 + 做连接操作
	str3 = str1 + str2;

	//4.string支持 < <= > >= 比较大小——比较字典序，abandon字典序比较小
	bool isLarger = false;
	isLarger = (str1 > str2);


	//string类似vector<char>的操作
	//1.使用[]通过下标访问字符
	string str4 = "abcdef";
	char ch;
	ch = str4[0];
	ch = str4[1];

	//2.push_back 在末尾插入字符
	str4.push_back('g');

	//3.pop_back 删除末尾字符
	str4.pop_back();

	//4.迭代器
	string::iterator it;
	for (it = str4.begin(); it != str4.end(); it++) {//打印字符串
		printf("it = %c\n", *it);
	}
	//插入与删除
	it = str4.begin();
	str4.insert(it, 'A');
	it = str4.begin();
	str4.erase(it);


	//string额外功能
	//1.string 对比 vector 拓展了insert和erase的用法
	//string 使用整数下标，插入删除多个字符
	str4.insert(0, "xyz");//插入字符串（多个字符）
	str4.erase(0, 3);//使用两个整数下标(起点，长度)，删除的范围[0,3)

	//2.string 获取子串——substr
	string str5;
	str5 = str4.substr(0, 3);//（起点，长度）——从0开始，长度为3

	//3.string 字符串匹配——find
	string str6 = "howdoyoudo";
	int pos = str6.find("do", 0);//find("待找元素",寻找的起始位置),返回值为第一个匹配串的第一个字符的下标
	if (pos == string::npos) {//没找到，string::npos=-1
		printf("not found\n");
	}

	//4.string 和 数值 互相转换
	int i = 1234;
	string str7 = to_string(i);//to_string 能变整型和浮点型
	float f = 3.14;
	string str7 = to_string(i);

	string str8 = "3.14159";
	f = stof(str8);
	str8 = "314159";
	i = stoi(str8);

	//5.string 的输入输出问题
	//方案一，string——>char，推荐，无性能问题
	//输入
	char arr[100];
	scanf("%s", arr);//先读到字符数组
	string str9;
	str9 = arr;//再转到string
	//输出
	printf("str9 = %s\n", str9.c_str());//使用.c_str()函数，从string中提取字符串

	//方案二，c++的cin和cout，不推荐
	//包含头文件<iostream>,注意cin和cout和scanf，printf不能混用
	string str10;
	cin >> str10;//注意std::cin读取到 空白字符，就会停止
	getline(cin >> ws, name); // 将一整行输入读取到 name，std::ws用于忽略前导空格，即之前的其他输入末尾的空格或回车
	cout << "str10 =" << str10 << "\n";

	return 0;
}