#include <iostream>

void printInt(int x)
{
    std::cout << x << '\n';
}

// =delete��ʾ���ҽ�ֹ���������������ǡ��ⲻ���ڡ���
void printInt(char) = delete; // ����ʱƥ�䵽�������������
void printInt(bool) = delete; // ����ʱƥ�䵽�������������

// �Ľ���
// �������ģ�潫��ƥ��������������
// ��Ϊ�������ģ�汻ɾ�������ƥ�䵽�������ᵼ�±���ʧ��
template <typename T>
void printInt(T x) = delete;

//����ģ��
template <typename T> // ����ģ���������
T max(T x, T y) // ���Ǻ���ģ�� max<T> �Ķ���
{
    return (x < y) ? y : x;
}

//���ж�����͵ĺ���ģ��
template <typename T, typename U> // ʹ������ģ�����Ͳ��� T �� U
T max(T x, U y) // x ������ T, y ������ U
{
    return (x < y) ? y : x; // uh �������и���ʽ��խ��ת��
}
//��C++20�����ǿ������÷�������Ϊauto�����Զ���������ж�

int main()
{
    printInt(97);   // okay

    printInt('a');  // ����ʧ��: ƥ�䵽�ĺ�����ɾ��
    printInt(true); // ����ʧ��: ƥ�䵽�ĺ�����ɾ��

    printInt(5.0);  // ����ʧ��: �ж����ƥ��ĺ���

    //ʹ�ú���ģ�壺ʹ��<>����typename
    std::cout << max<int>(1, 2) << '\n'; // ʵ���������ú��� max<int>(int, int)

    return 0;
}