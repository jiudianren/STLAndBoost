/*
 * rawString.cpp
 *
 *  Created on: 2019��3��29��
 *      Author: lian.pengfei
 */


//https://blog.csdn.net/wangshubo1989/article/details/50507674

#include <iostream>
#include <string>

int main()
{
    // һ����ͨ���ַ�����'\n'��������ת���ַ�����ʾһ�����з���
    std::string normal_str = "First line.\nSecond line.\nEnd of message.\n";

    // һ��raw string��'\'���ᱻת�崦����ˣ�"\n"��ʾ�����ַ����ַ���б�� �� ��ĸn��
    std::string raw_str = R"(First line.\nSecond line.\nEnd of message.\n)";

    std::cout << normal_str << std::endl;
    std::cout << raw_str << std::endl;
    std::cout << R"foo(Hello, world!)foo" << std::endl;

    // raw string���Կ�Խ���У����еĿհ׺ͻ��з��������ַ�����һ���֡�
    std::cout <<R"(
                   Hello,
                   world!
                   )" << std::endl;

    return 0;
}
