#include <stdio.h>
#include <stack>
#include <string>
#include <map>
#include <list>
using namespace std;

//在 Unix 风格的文件系统中规则如下：
//
//一个点 '.' 表示当前目录本身。
//此外，两个点 '..' 表示将目录切换到上一级（指向父目录）。
//任意多个连续的斜杠（即，'//' 或 '///'）都被视为单个斜杠 '/'。
//任何其他格式的点（例如，'...' 或 '....'）均被视为有效的文件 / 目录名称。
//返回的 简化路径 必须遵循下述格式：
//
//始终以斜杠 '/' 开头。
//两个目录名之间必须只有一个斜杠 '/' 。
//最后一个目录名（如果存在）不能 以 '/' 结尾。
//此外，路径仅包含从根目录到目标文件或目录的路径上的目录（即，不含 '.' 或 '..'）。
//返回简化后得到的 规范路径 。

//分析：每次从一个斜杠开始，直到检索到下一个斜杠，中间的东西合法的东西存入list（输出需要队列）
//首先需要注意多个斜杠，若之前的元素为'/'，则新的元素不写入临时str
//'/.'直接忽略,'/..'若栈不为空，则弹栈，若栈的长度不为1，则不加入尾部'/'元素

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';//强制保证path以/结尾，从而提取 /xxxx
        list<string> stack;
        int i = 0;
        string temp{};
        while (i < path.size()) {
            if (i == 0)
                temp += path[i++];// 写入/
            else if (path[i] == '/' && path[i - 1] == '/') {
                i++;
                continue;
            }
            else if (path[i] != '/' )
                temp += path[i++];
            else {//碰到下一个/,进入stack写入
                i++;
                if (temp == "/.") {
                    temp = '/';
                    continue;
                }
                else if (temp == "/..") {
                    if (stack.size())
                        stack.pop_back();
                    temp = '/';
                }
                else {
                    stack.push_back(temp);
                    temp = '/';//最后一个'/'本身就不写入stack
                }
         
            }

        }
        string ans;
        if(!stack.size())
            return temp;
        for (string s : stack) {
            ans += s;
        }
    
        return ans;
        


    }
};