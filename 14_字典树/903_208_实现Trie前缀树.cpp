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

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : isEnd(false), children(26) {}//��ʼ��26��nullptr����ָ��
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch])//����֮ǰ��ĳЩ���Ѿ�����˸����
                pCur->children[ch] = new TrieNode();
            pCur = pCur->children[ch];
            if (i == n - 1)
                pCur->isEnd = true;
        }
    }

    bool search(string word) {
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch] )
                return false;
            pCur = pCur->children[ch];
            if (i == n - 1 && !pCur->isEnd)
                return false;
        }
            return true;
    }

    bool startsWith(string prefix) {
        TrieNode* pCur = root;
        int n = prefix.length();
        for (int i = 0;i < n;i++) {
            int ch = prefix[i] - 'a';
            if (!pCur->children[ch] )
                return false;
            pCur = pCur->children[ch];
        }
        return true;
    }
};