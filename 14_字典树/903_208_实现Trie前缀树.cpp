#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//Trie���������� "try"������˵ ǰ׺�� ��һ���������ݽṹ�����ڸ�Ч�ش洢�ͼ����ַ������ݼ��еļ���
//��һ���ݽṹ���൱���Ӧ���龰�������Զ���ȫ��ƴд��顣
//
//����ʵ�� Trie �ࣺ
//Trie() ��ʼ��ǰ׺������
//void insert(String word) ��ǰ׺���в����ַ��� word ��
//boolean search(String word) ����ַ��� word ��ǰ׺���У����� true�������ڼ���֮ǰ�Ѿ����룩�����򣬷��� false ��
//boolean startsWith(String prefix) ���֮ǰ�Ѿ�������ַ��� word ��ǰ׺֮һΪ prefix ������ true �����򣬷��� false ��

//������������ÿ���ַ���26��Сд��ĸ��Ϊ��㣬����26���������а��������ս�㣩���������������ʽ�㣬ͬʱ���isEnd�ֶα�ǵ�ǰ�����ַ��Ƿ��ǵ��ʵĽ�β

