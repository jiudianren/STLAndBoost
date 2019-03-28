/*
 * coutControl.cpp
 *
 *  Created on: 2019��3��26��
 *      Author: lian.pengfei
 */




#include <sstream>
#include <locale>
#include <iostream>
#include <iomanip>
int main()
{
    // showbase Ӱ��˽��ƺ�ʮ�����Ƶ����
    std::cout << std::hex
              << "showbase: " << std::showbase << 42 << '\n'
              << "noshowbase: " << std::noshowbase << 42 << '\n';

    // ������ֵ����������
    std::locale::global(std::locale("en_US.utf8"));
    long double val = 0;
    std::istringstream is("3.14");
    is >> std::showbase >> std::get_money(val);
    std::cout << "With showbase, parsing 3.14 as money gives " << val << '\n';
    is.seekg(0);
    is >> std::noshowbase >> std::get_money(val);
    std::cout << "Without showbase, parsing 3.14 as money gives " << val << '\n';
}

/*
 * showbase: 0x2a
noshowbase: 2a
With showbase, parsing 3.14 as money gives 0
Without showbase, parsing 3.14 as money gives 314
*/
