#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

int main() {

	//string�����������͵Ĳ���
	//1.string֧�� = ��ֵ
	string str1 = "Hello,";
	string str2 = "World!";
	string str3;
	str3 = "Hello,";
	str3 = str2;

	string name0{}; // �� string
	string name{ "Fly" }; // �б��ʼ������ name��ֵΪ "Fly"
	name = "John";               // ��ֵ"John"������ name ��string�������ڱ��治ͬ��С���ַ���
	string myID{ "45" };//string���������ָ�ֵ

	//2.string֧�� == �ж������Ƿ���ͬ
	bool isSame = false;
	isSame = (str3 == str2);

	//3.string֧�� + �����Ӳ���
	str3 = str1 + str2;

	//4.string֧�� < <= > >= �Ƚϴ�С�����Ƚ��ֵ���abandon�ֵ���Ƚ�С
	bool isLarger = false;
	isLarger = (str1 > str2);


	//string����vector<char>�Ĳ���
	//1.ʹ��[]ͨ���±�����ַ�
	string str4 = "abcdef";
	char ch;
	ch = str4[0];
	ch = str4[1];

	//2.push_back ��ĩβ�����ַ�
	str4.push_back('g');

	//3.pop_back ɾ��ĩβ�ַ�
	str4.pop_back();

	//4.������
	string::iterator it;
	for (it = str4.begin(); it != str4.end(); it++) {//��ӡ�ַ���
		printf("it = %c\n", *it);
	}
	//������ɾ��
	it = str4.begin();
	str4.insert(it, 'A');
	it = str4.begin();
	str4.erase(it);


	//string���⹦��
	//1.string �Ա� vector ��չ��insert��erase���÷�
	//string ʹ�������±꣬����ɾ������ַ�
	str4.insert(0, "xyz");//�����ַ���������ַ���
	str4.erase(0, 3);//ʹ�����������±�(��㣬����)��ɾ���ķ�Χ[0,3)

	//2.string ��ȡ�Ӵ�����substr
	string str5;
	str5 = str4.substr(0, 3);//����㣬���ȣ�������0��ʼ������Ϊ3

	//3.string �ַ���ƥ�䡪��find
	string str6 = "howdoyoudo";
	int pos = str6.find("do", 0);//find("����Ԫ��",Ѱ�ҵ���ʼλ��),����ֵΪ��һ��ƥ�䴮�ĵ�һ���ַ����±�
	if (pos == string::npos) {//û�ҵ���string::npos=-1
		printf("not found\n");
	}

	//4.string �� ��ֵ ����ת��
	int i = 1234;
	string str7 = to_string(i);//to_string �ܱ����ͺ͸�����
	float f = 3.14;
	string str7 = to_string(i);

	string str8 = "3.14159";
	f = stof(str8);
	str8 = "314159";
	i = stoi(str8);

	//5.string �������������
	//����һ��string����>char���Ƽ�������������
	//����
	char arr[100];
	scanf("%s", arr);//�ȶ����ַ�����
	string str9;
	str9 = arr;//��ת��string
	//���
	printf("str9 = %s\n", str9.c_str());//ʹ��.c_str()��������string����ȡ�ַ���

	//��������c++��cin��cout�����Ƽ�
	//����ͷ�ļ�<iostream>,ע��cin��cout��scanf��printf���ܻ���
	string str10;
	cin >> str10;//ע��std::cin��ȡ�� �հ��ַ����ͻ�ֹͣ
	getline(cin >> ws, name); // ��һ���������ȡ�� name��std::ws���ں���ǰ���ո񣬼�֮ǰ����������ĩβ�Ŀո��س�
	cout << "str10 =" << str10 << "\n";

	return 0;
}