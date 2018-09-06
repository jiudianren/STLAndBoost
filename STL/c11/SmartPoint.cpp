/*
 * SmartPoint.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: Administrator
 */


#include "c11.h"
#include "SmartPoint.h"
#include <string.h>

/*
 * auto_ptr��c11����
 *
 * */
#if __cplusplus < 201103L

#include <auto_ptr.h>
void TestAutoPtr()
{

    auto_ptr<Test> ptest(new Test("123"));
    ptest->setStr("hello ");
    ptest->print();


    //��ȡԭʼָ��
    ptest.get()->print();

    ptest->getStr() += "world !";

    //��ȡָ���ʵ��
    (*ptest).print();
    ptest.reset(new Test("1234"));
    ptest->print();
}

void TestAutoPtr2()
{

    /*
     *
     * �����Ƕ�����ָ����и�ֵʱ����ptest2 = ptest��ptest2��ӹ�ptestԭ�����ڴ����Ȩ��
     * ptest���Ϊ��ָ�룬���ptest2ԭ����Ϊ�գ��������ͷ�ԭ������Դ���������ԭ��
     * Ӧ�ñ����auto_ptr�ŵ������У���Ϊ�㷨����������ʱ�����ѱ���STL�ڲ�������ʵ���˸�ֵ���ݲ�����������ʹ�����кܶ�Ԫ�ر���ΪNULL��
     * �ж�һ������ָ���Ƿ�Ϊ�ղ���ʹ��if(ptest == NULL)��Ӧ��ʹ��if(ptest.get() == NULL)�����´���
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
 * STL�е�����ָ��(Smart Pointer)����Դ�������� std::unique_ptr
 *
 * https://blog.csdn.net/yanglingwell/article/details/56682591
 *
 *
 * unique_ptr,������ȡ��c++98��auto_ptr�Ĳ���,��c++98��ʱ��û���ƶ�����(move semantics)��֧��,
 * ��˶���auto_ptr�Ŀ���Ȩת�Ƶ�ʵ��û�к���Ԫ�ص�֧��,���ǻ���ʵ����auto_ptr���ƶ�����,
 * ����������һЩ�����ǿ������캯���͸��Ʋ������غ�����������,�������־��ǰ�auto_ptr��Ϊ��������,
 * ����ȥ��ʱ�����Ȩת��,ת�Ƶ���������,���������ص�ʱ��û��һ������Ȩ�ƽ��Ĺ���,���Թ��˺���������ԭ�ȵ�auto_ptr�Ѿ�ʧЧ��.
 * ��c++11���������ƶ�����,ʹ��move()��unique_ptr���뺯��,�������֪��ԭ�ȵ�unique_ptr�Ѿ�ʧЧ��.
 * �ƶ����屾���˵��������������,�ȽϿӵ����Ǳ�׼������˵����move֮��ʹ��ԭ����������δ������Ϊ,�����׳��쳣,
 * ���Ի���Ҫ������������Ϸ����.��һ��,auto_ptr��֧�ִ���deleter,����ֻ��֧�ֵ�����(delete object),
 * ��unique_ptr������������ƫ�ػ�����,���һ�������Ӧ���Ż�,������[]������ӦԪ�ص�.

unique_ptr ��һ����������Ȩ������ָ�룬���ṩ���ϸ������ϵ�����Ȩ��������
1��ӵ����ָ��Ķ���
2���޷����и��ƹ��죬�޷����и��Ƹ�ֵ���������޷�ʹ����unique_ptrָ��ͬһ�����󡣵��ǿ��Խ����ƶ�������ƶ���ֵ����
3������ָ��ĳ�������ָ�룬��������ɾ���ͷŵ�ʱ�򣬻�ʹ�ø�����ɾ�����ͷ���ָ��Ķ���

unique_ptr ����ʵ�����¹��ܣ�
1��Ϊ��̬������ڴ��ṩ�쳣��ȫ
2������̬������ڴ�����Ȩ���ݸ�ĳ����
3����ĳ���������ض�̬�����ڴ������Ȩ
4���������б���ָ��
5��auto_ptr Ӧ�þ��еĹ���
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
    ptest2 = std::move(ptest);//����ֱ��ptest2 = ptest


    if(ptest == NULL)cout<<"ptest = NULL\n";

    Test* p = ptest2.release();
    p->print();

    ptest.reset(p);
    ptest->print();

    ptest2 = fun(); //���������=����Ϊʹ�����ƶ����캯��
    ptest2->print();

}

void Test_shared_ptr()
{

    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout<<ptest2->getStr()<<endl;
    cout<<ptest2.use_count()<<endl;

    ptest = ptest2;//"456"���ô�����1����123������

    ptest->print();
    cout<<ptest2.use_count()<<endl;//2
    cout<<ptest.use_count()<<endl;//2
    ptest.reset();

    ptest2.reset();//��ʱ��456������
    cout<<"done !\n";
}



template <typename T>
shared_ptr<T> make_shared_array(size_t size)
{
    //default_delete��STL�е�Ĭ��ɾ����
    return shared_ptr<T>(new T[size], default_delete<T[]>());
}

void  Test_shared_array()
{
    auto sp_array = make_shared_array<char>(100);
    strcpy(sp_array.get(), "hello smart pointer");
    sp_array.get()[0] = 'a';
    cout << sp_array << endl;

    //ʹ��ԭʼָ�������ͬ�Ĺ���:
    auto str_array = new char[100];
    strcpy(str_array, "hello old pointer");
    str_array[0] = 'a';
    cout << str_array << endl;
}

/*
 * weak_ptr���������shared_ptr�໥����ʱ����������,���˵����shared_ptr�໥����,
 * ��ô������ָ������ü�����Զ�������½�Ϊ0,��Դ��Զ�����ͷš����ǶԶ����һ�������ã�
 * �������Ӷ�������ü�������shared_ptr֮������໥ת����
 * shared_ptr����ֱ�Ӹ�ֵ������������ͨ������lock���������shared_ptr
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

    /*�������캯��*/
    shared_ptr<int> orig3 = orig;

    cout<< "wp :"<< wp.use_count() <<endl;
    cout<<  "oring: "<<orig.use_count() <<endl;
    cout<<  "orig3: "<< orig3.use_count() <<endl;
}

/*shared_ptr�໥����  */
void EachRef()
{

    /*���Կ���fun������pa ��pb֮�以�����ã�������Դ�����ü���Ϊ2����Ҫ��������ʱ������ָ��pa��
     * pb����ʱ������Դ���ü������һ�������������ü�������Ϊ1��������������ʱ��Դû�б��ͷţ�A B����������û�б����ã���
     * ���������һ����Ϊweak_ptr�Ϳ����ˣ����ǰ���A�����shared_ptr<B> pb_; ��Ϊweak_ptr<B> pb_;
     * ���н�����£������Ļ���
     * ��ԴB�����ÿ�ʼ��ֻ��1����pb����ʱ��B�ļ�����Ϊ0��B�õ��ͷţ�
     * B�ͷŵ�ͬʱҲ��ʹA�ļ�����һ��ͬʱpa����ʱʹA�ļ�����һ��
     * ��ôA�ļ���Ϊ0��A�õ��ͷš�
     *
     *
     * ע��������ǲ���ͨ��weak_ptrֱ�ӷ��ʶ���ķ���������B��������һ������print(),���ǲ����������ʣ�pa->pb_->print();
     * Ӣ��pb_��һ��weak_ptr��Ӧ���Ȱ���ת��Ϊshared_ptr,�磺shared_ptr<B> p = pa->pb_.lock();    p->print();
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
