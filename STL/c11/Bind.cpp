/*
 * Bind.cpp
 *
 *  Created on: 2018年11月10日
 *      Author: Administrator
 */


#include <functional>
#include <iostream>
class TestBind
{

public:
	TestBind(){};

	void Func(int x, int y ){
		std::cout<< "x: "<< x  << "y: " << y  << std::endl ;
		std::cout << "++ y "<< ++y;
		};
};

void TestBind()
{

	TestBind myBind;
	std::function<void (int x, int y)> twoInt = std::bind( &TestBind::Func, & mybind );

	twoInt(1 ,2 );
	auto oneInt = std::bind( &TestBind::Func, & mybind , 3 );

	int ref= 4;
	oneInt(ref); //如果ref是一个类对象，这里存在一次拷贝的过程

	std::cout<<"none std::ref : " << ref << std::endl; //4
	ontInt( std::ref(ref)); //这里不会
	std::cout<<" std::ref : "  << ref << std::endl;  //5


	auto noneInt = std::bind( &TestBind::Func, & mybind , 5, 6);

}
