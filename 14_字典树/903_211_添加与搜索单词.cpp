#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//�������һ�����ݽṹ��֧�� ����µ��� �� �����ַ����Ƿ����κ���ǰ��ӵ��ַ���ƥ�� ��

//ʵ�ִʵ��� WordDictionary ��
//WordDictionary() ��ʼ���ʵ����
//void addWord(word) �� word ��ӵ����ݽṹ�У�֮����Զ�������ƥ��
//bool search(word) ������ݽṹ�д����ַ����� word ƥ�䣬�򷵻� true �����򣬷���  false ��word �п��ܰ���һЩ '.' ��ÿ��.�����Ա�ʾ�κ�һ����ĸ��

//����������ͨ���.��ƥ�䣬������903_208_ǰ׺����ƥ��Ϻ�


struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : isEnd(false), children(26) {}//��ʼ��26��nullptr����ָ��
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {//��֮ǰ��insert����
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch])//����֮ǰ��ĳЩ���Ѿ�����˸����
                pCur->children[ch] = new TrieNode();
            pCur = pCur->children[ch];     
        }
        pCur->isEnd = true;
    }
    bool dfs(string word, TrieNode* pCur,int index) {
        if (index == word.size())//ע��pCurʼ��ָ��index��Ӧ����һ�����
            return pCur->isEnd;
        char c = word[index];
        if (c == '.') {
            for (TrieNode* child : pCur->children) {
                if (child && dfs(word, child, index + 1)) {//ֻҪ��һ�������ɹ��ͳɹ�
                    return true;
                }
            }
            return false;
        }
        else {
            int pos = c - 'a';
            if (!pCur->children[pos]) return false;
            return dfs(word, pCur->children[pos], index + 1);
        }
            
    }

    bool search(string word) {//��֮ǰ��search����
        return dfs(word, root, 0);
       
    }
};