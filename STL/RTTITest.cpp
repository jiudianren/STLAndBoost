/*
 * RTTITest.cpp
 *
 *  Created on: 2017年12月26日
 *      Author: Administrator
 */



/*运行时类型识别
 *
 *
 * */

/*
 *type_info
 *type_index:
 *type_index:该类是 type_info 对象的封装类（Wrapper），
 *type_index:该类是 可以被用来作为关联（Associative）及无序关联（Unordered associative）容器的索引（Index）。
    bad_typeid  如果 typeid 表达式中的某个参数是无效（Null）的，将会抛出的异常
    bad_cast

 * */
#define __cplusplus == 201103L

#if 0

#include "RTTITest.h"
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <string>
#include <memory>
#include <map>


void mainRTTI()
{

    //typeid(CDataTypeA).hash_code()
    RegistCreator( std::string( typeid(CDataTypeA).name())  , new CreatorForDataA);
    RegistCreator( std::string( typeid(CDataTypeB).name())  , new CreatorForDataB);

    CDataTypeA* dataA = new CDataTypeA;

    CreatorType* creator = GetCreator(dataA);

    std::unordered_map<std::type_index, std::string> type_names;

    type_names[std::type_index(typeid(int))] = "int";
    type_names[std::type_index(typeid(double))] = "double";
    type_names[std::type_index(typeid(A))] = "A";
    type_names[std::type_index(typeid(B))] = "B";
    type_names[std::type_index(typeid(C))] = "C";

    int i;
    double d;
    A a;

    // note that we're storing pointer to type A
    std::unique_ptr<A> b(new B);
    std::unique_ptr<A> c(new C);

    std::cout << "i is " << type_names[std::type_index(typeid(i))] << '\n';
    std::cout << "d is " << type_names[std::type_index(typeid(d))] << '\n';
    std::cout << "a is " << type_names[std::type_index(typeid(a))] << '\n';
    std::cout << "b is " << type_names[std::type_index(typeid(*b))] << '\n';
    std::cout << "c is " << type_names[std::type_index(typeid(*c))] << '\n';

}

#endif
