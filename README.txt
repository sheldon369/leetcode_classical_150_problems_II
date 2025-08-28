上接原来的项目，但是目录过于混乱故重新编排

包括区间，栈，链表，二叉树，二叉树层次遍历，二叉搜索树，图，图的广度优先搜索，字典树，回溯，分治等。

git维护代码

git init 
git add . 
git commit -m "第一次提交"
git remote add origin https://github.com/你的用户名/仓库名.git
git remote -v
git branch -M main
git push -u origin main

git status
git add .
git commit -m "说明你修改了什么"
git push origin main
git config --global --unset http.proxy 
git config --global --unset https.proxy
Test-NetConnection github.com -Port 443
git config --global http.proxy http://127.0.0.1:7890
git config --global https.proxy http://127.0.0.1:7890

std::cerr << "getUserInput() called\n"; //用于调试代码
#include <climits> INT_MIN INT_MAX
bool b{} //默认初始化为false
static_cast<int>(5.5);//显式类型转换
const double gravity { 9.8 };  // 使用 const 修饰常变量
std::getline(std::cin >> std::ws, name); // 将一整行输入读取到 name
std::unorder_map O(1)查找元素 count / find (map和set的使用基本一致，map的值字段可以设为结构体存储更多信息)
char数组实际上等价于一个%s类型的串
