#include <iostream>
#include <string_view>

//为了解决std::string初始化（或复制）开销大的问题，C++17引入了std::string_view（位于<string_view>头文件中）。
//std::string_view提供对现有字符串（C样式字符串、std::string或另一个std::string_view）的只读访问，而不制作副本。
//只读意味着我们可以访问和使用正在查看的值，但不能修改它。


// str 提供了传入参数的只读访问能力
void printSV(std::string_view str) // str现在是 std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // s现在是 std::string_view
    printSV(s);

    //string_view字符串可以使用多风格串进行初始化
    std::string_view s1{ "Hello, world!" }; // 使用c样式字符串初始化
    std::cout << s1 << '\n';

    std::string s{ "Hello, world!" };
    std::string_view s2{ s };  // 使用 std::string 初始化
    std::cout << s2 << '\n';

    std::string_view s3{ s2 }; // 使用 std::string_view 初始化
    std::cout << s3 << '\n';

    s3 = "John";//允许对std::string_view进行重新复制，但不会修改原来的string值

    //使用后缀构造字面值常量
    using namespace std::string_literals;      // 允许使用 s 后缀
    using namespace std::string_view_literals; // 允许使用 sv 后缀

    std::cout << "foo\n";   // 无后缀， c样式字符串字面值
    std::cout << "goo\n"s;  // s 后缀， std::string 字面值
    std::cout << "moo\n"sv; // sv 后缀， std::string_view 字面值

    //支持constexpr
    constexpr std::string_view sv{ "Hello, world!" }; // sv 是一个字符串常量
    std::cout << sv << '\n'; // sv 在编译时会被替换为 "Hello, world!"

    //查看子字符串
    std::string_view str{ "Peach" };
    std::cout << str << '\n';

    // 从视图左侧移除一个字符
    str.remove_prefix(1);
    std::cout << str << '\n';//each

    // 从视图右侧移除一个字符
    str.remove_suffix(2);
    std::cout << str << '\n';//ea

    str = "Peach"; // 重置视图
    std::cout << str << '\n';//Peach

    return 0;
}