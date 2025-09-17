#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
//注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
//令bool dp[i]表示到i为止结束的串是否能被匹配
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
