/*
 * Lambda.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: Administrator
 */


#include "c11.h"
#include <stdio.h>
#include "Lambda.h"

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


/*lambda �� ����ָ��
 *
 * lambda�Ĳ����б��Ƿ���ӳ� ����ָ�����������
 *
 * */

void TestLambdaWithSmartPtr()
{




}

void TestLambdaOjb()
{

    LambdaObj obj1;
    obj1.m_n1 =1;

    auto by_ref_func = [&]()
                        {
        cout << "by ref lam" << obj1.m_n1 << endl;
        obj1.TestFunc();
                        };
    by_ref_func();


    /*����ʧ��*/
    //    auto by_va_func = [=]()
    //        {
    //            cout << "by val lam" << obj1.m_n1 << endl;
    //            /*ֵ����ʱ ������const*/
    //            obj1.TestFunc();
    //        };
    //    by_va_func();


    auto by_va_func2 = [=](){
        cout << "by val lam" << obj1.m_n1 << endl;
        /*ֵ����ʱ ������const*/
        obj1.TestFuncConst();
    };

    by_va_func2();

    auto by_va_func3 = [=]() mutable {
        cout << "by val lam" << obj1.m_n1 << endl;
        /*ֵ����ʱ ������const*/
        obj1.TestFunc();
    };

    by_va_func3();
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
