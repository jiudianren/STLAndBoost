/*
 * Example.cpp
 *
 *  Created on: 2018年5月11日
 *      Author: Administrator
 */


#include <iostream>
#include <vector>
#include <string.h>
#include <functional>
#include <typeinfo>
#include <math.h>

using namespace std;

int sum(const vector<int>  aim)
{

    int iR=0;
    for(auto ele : aim)
    {
        iR+=ele;
    }

    return iR;
}


string  concat (const vector<string>  aim)
{

    string  iR;
    for(auto ele : aim)
    {
        iR.append(ele);
    }
    return iR;
}


/*抽象*/


template<class T>

T reduce( function<void(T & ,T)> f, T init, const vector<T> xs )
{
    T res = init;

    for(auto t :xs)
    {
        f(res ,t);
    }
    return res;
}



int sumT(const vector<int>  aim)
{

    return  reduce<int> (
            [](int & x , int y)
            { x+=y;
            },
            0,
            aim
    );
}

auto add=[](int & x, int y ){ x+=y;};
auto sumTT= std::bind( &reduce<int>, add , 0 , std::placeholders::_1 );


/*
 *平方跟
 * */

double sqrt(double x ,double eps)
{
    double cur=1.0;
    for(;;)
    {

        double next =( cur + x/cur) /2;
        if( fabs(next -cur) < eps) break;
        cur =next;
    }
    return cur;
}

/*
 *求导
 * */


double diff(   function< double (double)> f , double x ,double eps )
{
    double h =1.0;
    double cur = (f(x+h) - f(x)) /h;
    for(;;)
    {
        h /=2;
        double nxt = (f(x+h) - f(x)) /h;
        if( fabs(nxt -cur) < eps) break;
        cur =nxt;
    }

    return cur;

}

double with1(double  eps, function <double (double)>  appearance, function <double (double)> transation)
{
    double curStat =1.0;
    double curValue = appearance(curStat);

    for(;;)
    {
        double nextStat =  transation(curStat);
        double nextVal =  appearance(nextStat);
        if( fabs(nextVal -curValue) < eps) break;
        curStat  =nextStat;
        curValue =nextVal;
    }

    return  curValue;
}


auto nextNR = [](double x ,double an){ return (an + x/an)/2;};

/* lamba 表达式中药使用 nextNR
 * 所以这里用   [=]
 * */
auto sqrt1= [=](double x ,double eps)
                                                                        {

    return  with1( eps,
                   [](double y){return y;},
                   [=](double an ){

                       return  nextNR (x,an);
                   }
    );

                                                                        };

/*
 * diff = []
 * */
auto sin_= [](double x){ return sin(x);};

auto slop =[](  function <double (double)> f , double x ,double h )
                                                                                {
    return (f(x+h)-f(x))/h;
                                                                                };




auto diff1 = [=]( function <double (double)> f, double x ,double eps )
                                                                {
    return with1(
            eps,
            [ =](double y){  return slop(f,x ,y ); },
            [=](double h ){
                return h /=2;
            }
    );

                                                                };



auto diff2 = []( function <double (double)> f, double x ,double eps )
                                                                {
    return with1(
            eps,
            [ =](double y){  return slop(f,x ,y ); },
            [=](double h ){
                return h /=2;
            }
    );

                                                                };


/*c++ primer 5th p350
 * lamba 中
 * 与参数不同，
 * 被捕获的变量的值
 * 是在创建 lamba时拷贝
 * 而不是在调用时拷贝
 *
 * */
auto iiter =[]( function<double (double)> f, double init){
    double  an =init;
    return [=]() mutable{
        cout<<"inner 1 an "<<an <<endl;
        double x =an;
        an = f(an);
        cout<<"inner 2 an "<< an<<endl;
        cout<<"inner 2 x "<< x ;
        return x;
    };
};


auto within2 = [=]( function <double ()> seq, double eps){
    auto last = seq();
    for(;;)
    {
        auto cur = seq();
        if(fabs( cur - last) <eps ) break;
        last =cur;
    }
    return last;
};

auto sqrt2 =[=](double x, double eps){

    auto next =[=](double an){
        return nextNR( x,an);
    };

    auto seq= iiter(next ,x);
    return within2( seq, eps);
};


int main()
{
    vector<int> aim;
    aim.push_back(1);
    aim.push_back(2);
    aim.push_back(3);
    cout<<sumT(aim)<<endl;
    cout<<sumTT(aim)<<endl;

    cout<< sqrt1(10, 0.01)<<endl;
    cout<< diff2(sin_, 0,0.01)<<endl;
    cout<< diff1(sin_, 0,0.01)<<endl;

    auto seq = iiter( [](double x){ return x*2 ;},1);
    for (int i=1;i<20;i++)
    {
        cout<<" ,seq "<<seq() <<" ";
        cout<<endl;
    }

    cout<< sqrt2(10, 0.01) ;
    cout<<endl;
}


