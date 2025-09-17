#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//����һ���ַ��� s ��һ���ַ����б� wordDict ��Ϊ�ֵ䡣������������ֵ��г��ֵ�һ����������ƴ�ӳ� s �򷵻� true��
//ע�⣺��Ҫ���ֵ��г��ֵĵ���ȫ����ʹ�ã������ֵ��еĵ��ʿ����ظ�ʹ�á�
//��bool dp[i]��ʾ��iΪֹ�����Ĵ��Ƿ��ܱ�ƥ��
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hash;
        for (string s : wordDict) {
            hash.insert(s);
        }
        vector<int> truePos{};
        vector<bool> dp{}; 
    
        for (int i = 0;i < s.size();i++) {
            if (hash.count(s.substr(0, i + 1))) {
                dp.push_back(true);
                truePos.push_back(i);
                continue;
            }
            bool flag{ false };
            for (int j = 0;j < truePos.size();j++) {
                if (hash.count(s.substr(truePos[j]+1, i - truePos[j]))) {
                    flag = true;
                    truePos.push_back(i);
                    break;
                }
            }
            dp.push_back(flag);

        }
        return dp[s.size()-1];

    }
};


int main() {
    vector<string> wordDict{ "leet","code" };
    Solution sol;
    sol.wordBreak("leetcode", wordDict);


}
