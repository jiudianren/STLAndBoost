/*
 * SmartPoint.h
 *
 *  Created on: 2018Äê5ÔÂ4ÈÕ
 *      Author: Administrator
 */

#ifndef C11_SMARTPOINT_H_
#define C11_SMARTPOINT_H_

/*
 * https://www.cnblogs.com/wxquare/p/4759020.html
 *
 * */

#include <string>
#include <iostream>
#include <memory>


using namespace std;
class Test
{
public:
    Test(string s)
    {
        str = s;
       cout<<"Test creat\n";
    }
    ~Test()
    {
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr()
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout<<str<<endl;
    }
private:
    string str;
};



class B;
class A
{
public:
    shared_ptr<B> pb_;
    ~A()
    {
        cout<<"A delete\n";
    }
};
class B
{
public:
    shared_ptr<A> pa_;
    ~B()
    {
        cout<<"B delete\n";
    }
};

void EachRef();


unique_ptr<Test> fun();

void TestAutoPtr2();
void TestAutoPtr();
void Test_shared_ptr();
void Test_unique_ptr();
void Test_weak_ptr();

int mainSp();
#endif /* C11_SMARTPOINT_H_ */
