#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

// =delete表示“我禁止这样做”，而不是“这不存在”。
void printInt(char) = delete; // 编译时匹配到这个函数将报错
void printInt(bool) = delete; // 编译时匹配到这个函数将报错

// 改进：
// 这个函数模版将会匹配其它所有类型
// 因为这个函数模版被删除，因此匹配到它，将会导致编译失败
template <typename T>
void printInt(T x) = delete;

//函数模板
template <typename T> // 这是模版参数声明
T max(T x, T y) // 这是函数模版 max<T> 的定义
{
    return (x < y) ? y : x;
}

//具有多个类型的函数模板
template <typename T, typename U> // 使用两个模板类型参数 T 和 U
T max(T x, U y) // x 是类型 T, y 是类型 U
{
    return (x < y) ? y : x; // uh ，这里有个隐式的窄化转换
}
//在C++20后，我们可以设置返回类型为auto，以自动完成类型判断

int main()
{
    printInt(97);   // okay

    printInt('a');  // 编译失败: 匹配到的函数被删除
    printInt(true); // 编译失败: 匹配到的函数被删除

    printInt(5.0);  // 编译失败: 有多个可匹配的函数

    //使用函数模板：使用<>传入typename
    std::cout << max<int>(1, 2) << '\n'; // 实例化并调用函数 max<int>(int, int)

    return 0;
}