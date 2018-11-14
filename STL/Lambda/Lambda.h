/*
 * Lambda.h
 *
 *  Created on: 2018Äê11ÔÂ14ÈÕ
 *      Author: lian.pengfei
 */

#ifndef STL_LAMBDA_LAMBDA_H_
#define STL_LAMBDA_LAMBDA_H_
#include <iostream>

class LambdaObj
{
public:
    int m_n1;
    void TestFunc() { std::cout << "TestFunc" << std::endl; }
    void TestFuncConst()  const { std::cout << "TestFunc const" << std::endl; }

};
void TestLambdaOjb();
void TestMutalbe();
int mainLa();

#endif /* STL_LAMBDA_LAMBDA_H_ */
