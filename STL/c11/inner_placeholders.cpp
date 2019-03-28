/*
 * inner_placeholders.cpp
 *
 *  Created on: 2019年3月19日
 *      Author: lian.pengfei
 */




#include<functional>
#include <iostream>
#include <string>

int  add( int a, int b)
{
    auto c = a+b;
    std::cout << "a+b= " << c;
    return c;
}

int  Complate ( std::string p, int q, std::function<int(int)> && funcAdd)
{

    std::cout<< p << q;
    int c  = funcAdd(q);
    std::cout<<"c:" << c;
    return c;
}

int main()
{

    int a= 10;
    auto funcAdd = std::bind(add, a,std::placeholders::_2 );

    std::string p("i am p");
      int q=1;

    //placeholders不能嵌套使用
    auto funcPlace = std::bind(Complate,std::placeholders::_1,std::placeholders::_2, std::move(funcAdd));
    funcPlace(p,q);

    auto funcComplate = std::bind(Complate,std::placeholders::_1,std::placeholders::_2,
                                [](int a){return a+10;});

    funcComplate(p, q);

    return 0;
}
