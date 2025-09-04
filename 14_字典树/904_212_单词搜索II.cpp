#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ�� m x n ��ά�ַ����� board ��һ�����ʣ��ַ������б� words�� �������ж�ά�����ϵĵ��� ��
//���ʱ��밴����ĸ˳��ͨ�� ���ڵĵ�Ԫ�� �ڵ���ĸ���ɣ����С����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��
//ͬһ����Ԫ���ڵ���ĸ��һ�������в������ظ�ʹ�á�

//������һ���Ǳ߽��ַ������������������ĸ������ֵ���+������ȱ���+��֦+��ǻ�ԭ��
//�Ӷ�ά������ÿ����Ԫ�����
//�������������ǰ·���������·�����Ǵ�����Ԫ�ع��ɵ�ǰ׺����ǰ׺����ֹͣ������֦��ÿ���ѹ���Ԫ������Ϊ#�������ظ�����������ǻ�ԭ����

//note��ͬһ�𰸿����ڶ���·���ϳ��֣�ʹ�ù�ϣ����ȥ��
//�ж�ǰ׺ʱ������ÿ�ζ��жϵ�ǰ���Ƿ�Ϊ����ǰ׺��ֻ��Ҫ�ȶ�������㼴��

struct TrieNode {
    bool isEnd;
    vector<TrieNode*> children;
    string s;
    TrieNode() : isEnd(false), children(26),s("") {}//��ʼ��26��nullptr����ָ��
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    unordered_set<string> ans;
public:
    void insert(string word) {
        TrieNode* pCur = root;
        int n = word.length();
        for (int i = 0;i < n;i++) {
            int ch = word[i] - 'a';
            if (!pCur->children[ch])//����֮ǰ��ĳЩ���Ѿ�����˸����
                pCur->children[ch] = new TrieNode();
            pCur = pCur->children[ch];
        }
        pCur->isEnd = true;
        pCur->s = word;
    }

    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* pre) {
        int m = board.size();
        int n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == '#')
            return;
        char ch = board[r][c];
        int pos = ch - 'a';//ch��Ϊ#
        if (!pre->children[pos])
            return;
    
        pre = pre->children[pos];//��ǰλ��ƥ��ɹ�
        if (pre->isEnd)
            ans.insert(pre->s);

        board[r][c] = '#';//��ǻ�ԭ��
        for (int i = 0;i < 4;i++) 
            dfs(board, r + direction[i][0], c + direction[i][1], pre);
        board[r][c] = ch;
    }



    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.size() == 0)
            return res;
        for (auto word : words) 
            insert(word);
        int m = board.size();
        int n = board[0].size();
        for (int i = 0;i < m;i++) 
            for (int j = 0;j < n;j++)
                dfs(board, i, j, root);
        res = vector<string>{ ans.begin(), ans.end() };
        return res;

    }
};

//�Ľ���ȥ��isEnd�жϣ���ʹ��s������õı���isEnd����ӵ���ʱ���°�s��Trie�ж���
//ȥ��set��ʹ�ã��������ʺ�isEnd��Ϊfalse�����ظ�����