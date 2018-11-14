/*
 * Lambda.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: Administrator
 */


#include "c11.h"
#include <stdio.h>
#include "Lambda.h"

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


/*lambda 和 智能指针
 *
 * lambda的捕获列表是否会延长 共享指针的生存周期
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


    /*编译失败*/
    //    auto by_va_func = [=]()
    //        {
    //            cout << "by val lam" << obj1.m_n1 << endl;
    //            /*值传递时 必须用const*/
    //            obj1.TestFunc();
    //        };
    //    by_va_func();


    auto by_va_func2 = [=](){
        cout << "by val lam" << obj1.m_n1 << endl;
        /*值传递时 必须用const*/
        obj1.TestFuncConst();
    };

    by_va_func2();

    auto by_va_func3 = [=]() mutable {
        cout << "by val lam" << obj1.m_n1 << endl;
        /*值传递时 必须用const*/
        obj1.TestFunc();
    };

    by_va_func3();
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
