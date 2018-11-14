/*
 * Bind.cpp
 *
 *  Created on: 2018��11��10��
 *      Author: Administrator
 */


#include <functional>
#include "Bind.h"

    using namespace std::placeholders;
void TestBind()
{

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "TestBind" <<std::endl;


    TTestBind mybind;
	std::function<void (int x, int y)> twoInt = std::bind( &TTestBind::Func, & mybind , _1 ,_2);
	twoInt(1 ,2 );

	auto oneInt = std::bind( &TTestBind::Func, & mybind , 3 , _1);
	int ref = 4;
	oneInt(ref); //���ref��һ��������������һ�ο����Ĺ���

	std::cout<<"none std::ref : " << ref << std::endl; //4
	oneInt( std::ref(ref)); //���ﲻ��
	std::cout<<" std::ref : "  << ref << std::endl;  //5


	auto noneInt = std::bind( &TTestBind::Func, & mybind , 5, 6);
	noneInt();
}
