#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。

//实现词典类 WordDictionary ：
//WordDictionary() 初始化词典对象
//void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
//bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些 '.' ，每个.都可以表示任何一个字母。

//分析：对于通配符.的匹配，还是用903_208_前缀树的匹配较好


struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode() : isEnd(false), children(26) {}//初始化26个nullptr孩子指针
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {//即之前的insert函数
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch])//否则之前的某些串已经完成了该项构造
                pCur->children[ch] = new TrieNode();
            pCur = pCur->children[ch];     
        }
        pCur->isEnd = true;
    }
    bool dfs(string word, TrieNode* pCur,int index) {
        if (index == word.size())//注意pCur始终指向index对应的上一个结点
            return pCur->isEnd;
        char c = word[index];
        if (c == '.') {
            for (TrieNode* child : pCur->children) {
                if (child && dfs(word, child, index + 1)) {//只要有一个搜索成功就成功
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

    bool search(string word) {//即之前的search函数
        return dfs(word, root, 0);
       
    }
};