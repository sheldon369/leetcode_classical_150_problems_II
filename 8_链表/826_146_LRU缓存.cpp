#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;

//请你设计并实现一个满足  LRU(最近最少使用) 缓存 约束的数据结构。实现 LRUCache 类：
//LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
//int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 - 1 。
//void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；
//如果不存在，则向缓存中插入该组 key - value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
//函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

//分析： get O(1)复杂度 ->使用哈希表 unordered_map查询到节点，并将节点移动到链表的开头
//put O(1)复杂度 ->使用双向链表list,

struct DLinkedNode{//双向链表
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private://存放类内部共用的变量
    DLinkedNode* head;
    DLinkedNode* tail;
    int capacity;
    int size;
    unordered_map<int, DLinkedNode*> cache;


public:
    LRUCache(int _capacity){ //以 正整数 作为容量 capacity 初始化 LRU 缓存
        capacity = _capacity;
        size = 0;
        head = new  DLinkedNode;
        tail = new  DLinkedNode;
        head->next = tail;
        tail->prev = head;
    }

    void toTop(DLinkedNode* p) {
        //首先从删除p
        p->prev->next = p->next;
        p->next->prev = p->prev;
        //接着在头部插入p
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

    int get(int key) { //如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 - 1 。
        if (cache.count(key)) {//关键字在缓存中，链表位置置顶
            DLinkedNode* p = cache[key];
            toTop(p);
            return p->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.count(key)) {//关键字在缓存中，链表位置置顶
            DLinkedNode* p = cache[key];
            toTop(p);
            p->value = value;
        }
        else { //不存在，插入该数据
            if (size == capacity) {//满了，删除链表尾部数据
                deleteTail();
                size--;
            }
            size++;//插入数据
            insert(key, value);
        }

    }
};