/*
 * Lambda.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: Administrator
 */


#include "c11.h"
#include <stdio.h>


/*
 * �﷨��
 * [capture] (paraments) mutalbe -> reutrn type { statement}
 * */



using namespace std;
#include <iostream>

/*c++ primer 5th 353 */
void TestMutalbe()
{

    int t = 42;
    //f���Լ��洢��һ�� t������f������� t�ı䣬�� f��û��Ӱ��
    auto f =[ t]() mutable{
         return ++t;
    };
    auto f2 =[ &t]() mutable{
         return ++t;
    };
    t =0;
    cout <<f(); //���43 ��������⡣����
    cout <<f2(); //���1 ��������⡣����

}

int mainLa()
{

	int arry[5] ={1,3,2,4,5};

//	for_each() ��ʹ��lambda


	//�ȶ����ʹ��
	auto myLam= []
				 {
						 std::cout<<"hello my Lam"<<std::endl;
				 };


	myLam();

	//ֱ��ʹ��

	[]
	 {
			 std::cout<<"using lam directly"<<std::endl;
	 }
	();





	return 0;
}
