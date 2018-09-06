/*
 * SmartPoint.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: Administrator
 */


#include "c11.h"
#include "SmartPoint.h"
#include <string.h>

/*
 * auto_ptr被c11弃用
 *
 * */
#if __cplusplus < 201103L

#include <auto_ptr.h>
void TestAutoPtr()
{

    auto_ptr<Test> ptest(new Test("123"));
    ptest->setStr("hello ");
    ptest->print();


    //获取原始指针
    ptest.get()->print();

    ptest->getStr() += "world !";

    //获取指针的实体
    (*ptest).print();
    ptest.reset(new Test("1234"));
    ptest->print();
}

void TestAutoPtr2()
{

    /*
     *
     * 当我们对智能指针进行赋值时，如ptest2 = ptest，ptest2会接管ptest原来的内存管理权，
     * ptest会变为空指针，如果ptest2原来不为空，则它会释放原来的资源，基于这个原因，
     * 应该避免把auto_ptr放到容器中，因为算法对容器操作时，很难避免STL内部对容器实现了赋值传递操作，这样会使容器中很多元素被置为NULL。
     * 判断一个智能指针是否为空不能使用if(ptest == NULL)，应该使用if(ptest.get() == NULL)，如下代码
     * */

    auto_ptr<Test> ptest(new Test("123"));
    auto_ptr<Test> ptest2(new Test("456"));
    ptest2 = ptest;
    ptest2->print();
    if(ptest.get() == NULL)cout<<"ptest = NULL\n";
}

#else

void TestAutoPtr()
{
};

void TestAutoPtr2(){


};

#endif

/*
 *
 *
 * STL中的智能指针(Smart Pointer)及其源码剖析： std::unique_ptr
 *
 * https://blog.csdn.net/yanglingwell/article/details/56682591
 *
 *
 * unique_ptr,是用于取代c++98的auto_ptr的产物,在c++98的时候还没有移动语义(move semantics)的支持,
 * 因此对于auto_ptr的控制权转移的实现没有核心元素的支持,但是还是实现了auto_ptr的移动语义,
 * 这样带来的一些问题是拷贝构造函数和复制操作重载函数不够完美,具体体现就是把auto_ptr作为函数参数,
 * 传进去的时候控制权转移,转移到函数参数,当函数返回的时候并没有一个控制权移交的过程,所以过了函数调用则原先的auto_ptr已经失效了.
 * 在c++11当中有了移动语义,使用move()把unique_ptr传入函数,这样你就知道原先的unique_ptr已经失效了.
 * 移动语义本身就说明了这样的问题,比较坑爹的是标准描述是说对于move之后使用原来的内容是未定义行为,并非抛出异常,
 * 所以还是要靠人肉遵守游戏规则.再一个,auto_ptr不支持传入deleter,所以只能支持单对象(delete object),
 * 而unique_ptr对数组类型有偏特化重载,并且还做了相应的优化,比如用[]访问相应元素等.

unique_ptr 是一个独享所有权的智能指针，它提供了严格意义上的所有权，包括：
1、拥有它指向的对象
2、无法进行复制构造，无法进行复制赋值操作。即无法使两个unique_ptr指向同一个对象。但是可以进行移动构造和移动赋值操作
3、保存指向某个对象的指针，当它本身被删除释放的时候，会使用给定的删除器释放它指向的对象

unique_ptr 可以实现如下功能：
1、为动态申请的内存提供异常安全
2、讲动态申请的内存所有权传递给某函数
3、从某个函数返回动态申请内存的所有权
4、在容器中保存指针
5、auto_ptr 应该具有的功能
 * */


unique_ptr<Test> fun()
        {
    return unique_ptr<Test>(new Test("789"));
        }


void Test_unique_ptr()
{

    unique_ptr<Test> ptest(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));
    ptest->print();
    ptest2 = std::move(ptest);//不能直接ptest2 = ptest


    if(ptest == NULL)cout<<"ptest = NULL\n";

    Test* p = ptest2.release();
    p->print();

    ptest.reset(p);
    ptest->print();

    ptest2 = fun(); //这里可以用=，因为使用了移动构造函数
    ptest2->print();

}

void Test_shared_ptr()
{

    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout<<ptest2->getStr()<<endl;
    cout<<ptest2.use_count()<<endl;

    ptest = ptest2;//"456"引用次数加1，“123”销毁

    ptest->print();
    cout<<ptest2.use_count()<<endl;//2
    cout<<ptest.use_count()<<endl;//2
    ptest.reset();

    ptest2.reset();//此时“456”销毁
    cout<<"done !\n";
}



template <typename T>
shared_ptr<T> make_shared_array(size_t size)
{
    //default_delete是STL中的默认删除器
    return shared_ptr<T>(new T[size], default_delete<T[]>());
}

void  Test_shared_array()
{
    auto sp_array = make_shared_array<char>(100);
    strcpy(sp_array.get(), "hello smart pointer");
    sp_array.get()[0] = 'a';
    cout << sp_array << endl;

    //使用原始指针完成相同的功能:
    auto str_array = new char[100];
    strcpy(str_array, "hello old pointer");
    str_array[0] = 'a';
    cout << str_array << endl;
}

/*
 * weak_ptr是用来解决shared_ptr相互引用时的死锁问题,如果说两个shared_ptr相互引用,
 * 那么这两个指针的引用计数永远不可能下降为0,资源永远不会释放。它是对对象的一种弱引用，
 * 不会增加对象的引用计数，和shared_ptr之间可以相互转化，
 * shared_ptr可以直接赋值给它，它可以通过调用lock函数来获得shared_ptr
 * */
void Test_weak_ptr()
{
    shared_ptr<int> orig ( new int(20));
    cout<<"orig: "<< *orig.get()<<endl;
    cout<<"orig: "<< orig.get()<<endl;

    weak_ptr<int> wp(orig);
    cout<< "wp :"<< wp.use_count() <<endl;;
    cout<<  "oring: "<<orig.use_count() <<endl;;

    if( ! wp.expired())
    {
        shared_ptr<int> or2 = wp.lock();
        cout<< "wp :"<< wp.use_count() <<endl;
        cout<<  "oring: "<<orig.use_count() <<endl;
        cout<<  "or2: "<< or2.use_count() <<endl;
    }

    /*拷贝构造函数*/
    shared_ptr<int> orig3 = orig;

    cout<< "wp :"<< wp.use_count() <<endl;
    cout<<  "oring: "<<orig.use_count() <<endl;
    cout<<  "orig3: "<< orig3.use_count() <<endl;
}

/*shared_ptr相互引用  */
void EachRef()
{

    /*可以看到fun函数中pa ，pb之间互相引用，两个资源的引用计数为2，当要跳出函数时，智能指针pa，
     * pb析构时两个资源引用计数会减一，但是两者引用计数还是为1，导致跳出函数时资源没有被释放（A B的析构函数没有被调用），
     * 如果把其中一个改为weak_ptr就可以了，我们把类A里面的shared_ptr<B> pb_; 改为weak_ptr<B> pb_;
     * 运行结果如下，这样的话，
     * 资源B的引用开始就只有1，当pb析构时，B的计数变为0，B得到释放，
     * B释放的同时也会使A的计数减一，同时pa析构时使A的计数减一，
     * 那么A的计数为0，A得到释放。
     *
     *
     * 注意的是我们不能通过weak_ptr直接访问对象的方法，比如B对象中有一个方法print(),我们不能这样访问，pa->pb_->print();
     * 英文pb_是一个weak_ptr，应该先把它转化为shared_ptr,如：shared_ptr<B> p = pa->pb_.lock();    p->print();
     * */
    shared_ptr<B> pb(new B());
    shared_ptr<A> pa(new A());
    pb->pa_ = pa;
    pa->pb_ = pb;
    cout<<pb.use_count()<<endl;
    cout<<pa.use_count()<<endl;
}



int mainSp()
{
    TestAutoPtr();
    TestAutoPtr2();
    Test_unique_ptr();
    EachRef();

    Test_shared_ptr();
    Test_weak_ptr();

    return 0;

}
