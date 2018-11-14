/*
 * Bind.h
 *
 *  Created on: 2018Äê11ÔÂ14ÈÕ
 *      Author: lian.pengfei
 */

#ifndef STL_C11_BIND_H_
#define STL_C11_BIND_H_
#include <iostream>
class TTestBind
{

public:
    TTestBind(){};

    void Func(int x, int y ){
        std::cout<< "x: "<< x  << "y: " << y  << std::endl ;
        std::cout << "++ y "<< ++y;
        };
};

void TestBind();

#endif /* STL_C11_BIND_H_ */
