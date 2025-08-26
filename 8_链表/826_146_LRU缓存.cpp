#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//������Ʋ�ʵ��һ������  LRU(�������ʹ��) ���� Լ�������ݽṹ��ʵ�� LRUCache �ࣺ
//LRUCache(int capacity) �� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
//int get(int key) ����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� - 1 ��
//void put(int key, int value) ����ؼ��� key �Ѿ����ڣ�����������ֵ value ��
//��������ڣ����򻺴��в������ key - value ���������������¹ؼ����������� capacity ����Ӧ�� ��� ���δʹ�õĹؼ��֡�
//���� get �� put ������ O(1) ��ƽ��ʱ�临�Ӷ����С�

//������ get O(1)���Ӷ� ->ʹ�ù�ϣ�� unordered_map��ѯ���ڵ㣬�����ڵ��ƶ�������Ŀ�ͷ
//put O(1)���Ӷ� ->ʹ��˫������list,

struct DLinkedNode{//˫������
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private://������ڲ����õı���
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;
    unordered_map<int, DLinkedNode*> cache;


public:
    LRUCache(int _capacity){ //�� ������ ��Ϊ���� capacity ��ʼ�� LRU ����
        capacity = _capacity;
        size = 0;
        head = new  DLinkedNode;
        tail = new  DLinkedNode;
        head->next = tail;
        tail->prev = head;
    }

    void toTop(DLinkedNode* p) {
        //���ȴ�ɾ��p
        p->prev->next = p->next;
        p->next->prev = p->prev;
        //������ͷ������p
        p->next = head->next;
        head->next->prev = p;
        head->next = p;
        p->prev = head;
    }

    void deleteTail() {
        DLinkedNode* p = tail->prev;
        p->prev->next = tail;
        tail->prev = p->prev;
        cache.erase(p->key);
    }

    void insert(int key, int value) {
        DLinkedNode* p = new DLinkedNode(key, value);
        p->next = head->next;
        head->next->prev = p;
        head->next = p;
        p->prev = head;
        cache[key] = p;

    }

    int get(int key) { //����ؼ��� key �����ڻ����У��򷵻عؼ��ֵ�ֵ�����򷵻� - 1 ��
        if (cache.count(key)) {//�ؼ����ڻ����У�����λ���ö�
            DLinkedNode* p = cache[key];
            toTop(p);
            return p->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {//�ؼ����ڻ����У�����λ���ö�
            DLinkedNode* p = cache[key];
            toTop(p);
            p->value = value;
        }
        else { //�����ڣ����������
            if (size == capacity) {//���ˣ�ɾ������β������
                deleteTail();
                size--;
            }
            size++;//��������
            insert(key, value);
        }

    }
};