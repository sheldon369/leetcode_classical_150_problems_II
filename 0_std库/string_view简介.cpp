#include <iostream>
#include <string_view>

//Ϊ�˽��std::string��ʼ�������ƣ�����������⣬C++17������std::string_view��λ��<string_view>ͷ�ļ��У���
//std::string_view�ṩ�������ַ�����C��ʽ�ַ�����std::string����һ��std::string_view����ֻ�����ʣ���������������
//ֻ����ζ�����ǿ��Է��ʺ�ʹ�����ڲ鿴��ֵ���������޸�����


// str �ṩ�˴��������ֻ����������
void printSV(std::string_view str) // str������ std::string_view
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view s{ "Hello, world!" }; // s������ std::string_view
    printSV(s);

    //string_view�ַ�������ʹ�ö��񴮽��г�ʼ��
    std::string_view s1{ "Hello, world!" }; // ʹ��c��ʽ�ַ�����ʼ��
    std::cout << s1 << '\n';

    std::string s{ "Hello, world!" };
    std::string_view s2{ s };  // ʹ�� std::string ��ʼ��
    std::cout << s2 << '\n';

    std::string_view s3{ s2 }; // ʹ�� std::string_view ��ʼ��
    std::cout << s3 << '\n';

    s3 = "John";//�����std::string_view�������¸��ƣ��������޸�ԭ����stringֵ

    //ʹ�ú�׺��������ֵ����
    using namespace std::string_literals;      // ����ʹ�� s ��׺
    using namespace std::string_view_literals; // ����ʹ�� sv ��׺

    std::cout << "foo\n";   // �޺�׺�� c��ʽ�ַ�������ֵ
    std::cout << "goo\n"s;  // s ��׺�� std::string ����ֵ
    std::cout << "moo\n"sv; // sv ��׺�� std::string_view ����ֵ

    //֧��constexpr
    constexpr std::string_view sv{ "Hello, world!" }; // sv ��һ���ַ�������
    std::cout << sv << '\n'; // sv �ڱ���ʱ�ᱻ�滻Ϊ "Hello, world!"

    //�鿴���ַ���
    std::string_view str{ "Peach" };
    std::cout << str << '\n';

    // ����ͼ����Ƴ�һ���ַ�
    str.remove_prefix(1);
    std::cout << str << '\n';//each

    // ����ͼ�Ҳ��Ƴ�һ���ַ�
    str.remove_suffix(2);
    std::cout << str << '\n';//ea

    str = "Peach"; // ������ͼ
    std::cout << str << '\n';//Peach

    return 0;
}