
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <assert.h>
#include <ctype.h>
#include <vector>
//#include <Windows.h>
#include <chrono>
#include <iomanip>
#include <stdint.h>
#include <time.h>


using namespace std;
using namespace chrono;
/*
 * https://kheresy.wordpress.com/2013/12/27/c-stl-chrono/
 * */

class A
{
public:
	int i_;
};

int64_t Factorial(int gene)
{
	return (gene == 1)? 1: gene*Factorial(gene-1);
}


void TestChrono()
{
	// 计算函数执行时间.
	auto start = std::chrono::steady_clock::now();
	std::vector<A*> v;
	for (int i = 1; i <= 1000000; ++i)
	{
		v.push_back(new A());
	}

	for (auto a : v)
	{
		delete a;
	}

	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end-start;
	auto  durations = duration_cast<microseconds>(end - start);
	std::cout << "=>Time Elapse " << diff.count() << " s" << std::endl;
	std::cout<<"time keep "<< durations.count()<<endl;

	// 获取过去24小时的时间
	std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
	char buf[32];
	strftime(buf,32,"%Y-%m-%d %H:%M:%S",std::localtime(&now_c));
	std::cout << buf << std::endl;


	std::chrono:: system_clock :: time_point now2 = std::chrono:: system_clock ::now();
	std::time_t now_c2 = std::chrono:: system_clock ::to_time_t( now2 );
	std::cout << std::ctime( &now_c2 ) << std::endl;

	//如何表示 自定义的时间长度 比如半天

	typedef std::chrono::duration<int ,ratio<3600> >  TMyHours;
	TMyHours halfday(12);

	std::cout<<"halpfday: "<<halfday.count()<< std::endl;

	// time_t t;
	// t = time(NULL);
	// std::stringstream ss;
	// ss << put_time(localtime(&t),"%Y-%m-%d %H:%M:%S");
	// std::string str = ss.str();
	// std::cout << "str: " << str << std::endl;
}

int mainTime()
{


    time_t iExpTime; /*绝对超时时间*/
    iExpTime=  time(NULL);
    printf ("time %ld \n ",iExpTime);
    iExpTime += 1000;
    printf ("time %ld \n",iExpTime);
    return 0;
}

void  mainChrono()
{
	TestChrono();

}
