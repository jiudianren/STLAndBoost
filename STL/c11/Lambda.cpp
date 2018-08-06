/*
 * Lambda.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: Administrator
 */


#include "c11.h"
#include <stdio.h>


/*
 * 语法：
 * [capture] (paraments) mutalbe -> reutrn type { statement}
 * */



using namespace std;
#include <iostream>

/*c++ primer 5th 353 */
void TestMutalbe()
{

    int t = 42;
    //f中自己存储了一份 t，所以f（）外的 t改变，对 f内没有影响
    auto f =[ t]() mutable{
         return ++t;
    };
    auto f2 =[ &t]() mutable{
         return ++t;
    };
    t =0;
    cout <<f(); //输出43 ，这个问题。。。
    cout <<f2(); //输出1 ，这个问题。。。

}

int mainLa()
{

	int arry[5] ={1,3,2,4,5};

//	for_each() 中使用lambda


	//先定义后使用
	auto myLam= []
				 {
						 std::cout<<"hello my Lam"<<std::endl;
				 };


	myLam();

	//直接使用

	[]
	 {
			 std::cout<<"using lam directly"<<std::endl;
	 }
	();





	return 0;
}
