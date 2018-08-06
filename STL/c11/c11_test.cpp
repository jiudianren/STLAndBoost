#include "c11.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "c11_test.h"
#include "debug.h"

using namespace std;


void testAuto()
{
	__FUNC_LOGn();
	int a =1;
	auto b = a;

	//not ok  auto 是占位符，必须声明和定义在一块
//	auto z;
//	z= b;
	cout<<"b:"<<b<<"a:"<< a <<endl;
	__FUNC_LOGn();
}

void TestAutoInner1()
{
	vector< string > vect_Temp;
	vect_Temp.push_back("aa");
	vect_Temp.push_back("bb");
	vect_Temp.push_back("cc");
	vect_Temp.push_back("dd");

	//old
	std::vector<string >::iterator it= vect_Temp.begin();
	cout<<"old "<<endl;
	for(; it!=vect_Temp.end(); it++)
	{
	    cout<<*it<<endl;
	}

	//new
	auto autoit=vect_Temp.begin();
	cout<<"new"<<endl;
	for(;autoit != vect_Temp.end(); autoit++)
	{
	    cout<<*autoit <<endl;
	}

	cout<<"for(auto it:vect_Temp ) "<<endl;
	for(auto& it : vect_Temp )
	{
	    cout<<it <<endl;
	}

}

/*静态断言   可在编译期间进行断言
 * 动态断言，必须程序运行时候，才能知道结果*/

/*
 * http://www.cnblogs.com/QG-whz/p/4952980.html
 *
 * 如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型。
 * 此外，如果e是一个被重载的函数，则会导致编译错误。
否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&&
否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&。
否则，假设e的类型是T，则decltype（e）为T。
 * */
void testDeclType()
{
	__FUNC_LOGn();
	int a =1;
	decltype (a) b =1;
	int d=2;
    decltype( (a)) c= d;  //这里c是int &
    c = 100;
	cout<<"b:"<<b <<"c:"<<c <<endl;
}


void mainC11()
{
	cout<<"<<<<<<<<<test c++ 11 start:"<<endl;

	testAuto();
//	TestAutoInner1();


	testDeclType();
	cout<<"<<<<<<<<<test c++ 11 end"<<endl;

}
