enable_from_this 的使用与实现原理说明：

shared_from_this()是enable_shared_from_this的成员函数，返回shared_ptr;
注意的是，这个函数仅在shared_ptr的构造函数被调用之后才能使用。
原因是enable_shared_from_this::weak_ptr并不在构造函数中设置，而是在shared_ptr的构造函数中设置。

使用场合：当前类A的实例对象正被share_ptr管理，且在类A的成员函数里需要把当前类对象作为参数传给其他函数时，就需要传递一个指向此类A的实例对象自身的share_ptr。

错误的使用代码一：

#include<boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <iostream>
using namespace std;

class D: public boost::enable_shared_from_this<D>
{
public:
    D()
    {
        cout<<"D::D()"<<endl;
        boost::shared_ptr<D> p= shared_from_this();
    }    
};

int main()
{
    boost::shared_ptr<D> a(new D);
    return 0;    
}


程序编译通过，执行结果如下：
D::D()
terminate called after throwing an instance of 'boost::exception_detail::clone_impl >'
  what():  tr1::bad_weak_ptr
Aborted

说明在D的构造函数中调用shared_from_this(), 此时D的实例本身尚未构造成功，weak_ptr也就尚未设置,所以程序抛出tr1::bad_weak_ptr异常。


错误的使用代码二：


#include<boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <iostream>
using namespace std;

class D: public boost::enable_shared_from_this<D>
{
public:
    D()
    {
        cout<<"D::D()"<<endl;
    }
    
    void func()
    {
        cout<<"D::func()"<<endl;
        boost::shared_ptr<D> p= shared_from_this();
    }    
};

int main()
{
    D d;
    d.func();
    return 0;    
}


程序编译通过，执行结果如下：
D::D()
D::func()
terminate called after throwing an instance of 'boost::exception_detail::clone_impl >'
  what():  tr1::bad_weak_ptr
Aborted

失败原因分析：

在主函数main中，D的实例是在栈上构造，没有使用boost::shared_ptr 的构造方式，
所以boost::enable_shared_from_this中的weak_ptr所指的函数对象也就没有被赋值，
在调用d.func()中使用shared_from_this()函数时

----注：shared_from_this的函数实现 ------
    shared_ptr shared_from_this()
    {
        shared_ptr p( weak_this_ );
        BOOST_ASSERT( p.get() == this );
        return p;
    }
----注：shared_from_this的函数实现 ------

调用BOOST_ASSERT( p.get() == this );  失败，抛出以上异常。


最后，我们给出share_from_this()的正确使用例子:



#include<boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <iostream>
using namespace std;

class D: public boost::enable_shared_from_this<D>
{
public:
    D()
    {
        cout<<"D::D()"<<endl;
    }
    
    void func()
    {
        cout<<"D::func()"<<endl;
        boost::shared_ptr<D> p= shared_from_this();
    }    
};

int main()
{
    boost::shared_ptr<D> p(new D);
    p->func();
    return 0;    
}    


执行结果:
D::D()
D::func()