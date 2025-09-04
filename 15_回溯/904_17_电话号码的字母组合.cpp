#include <stdio.h>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ��𰸿��԰� ����˳�� ���ء�
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

class Solution {
private:
    vector<vector<char>> phone = { {},{},{'a','b','c'},{'d','e','f'} ,{'g','h','i'} ,{'j','k','l'} ,{'m','n','o'} ,{'p','q','r','s'} ,{'t','u','v'} ,{'w','x','y','z'} };
    int n;
    vector<string> res;
public:
    void dfs(string digits,string pre,int pos) {
        if (pos == n)
            return;
        for (char ch : phone[digits[pos] - '0']) {
            string s = pre + ch;
            if (s.length() == n)
                res.push_back(s);
            dfs(digits, s, pos + 1);
        }

    }
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        dfs(digits, "", 0);
        return res;

    }
};