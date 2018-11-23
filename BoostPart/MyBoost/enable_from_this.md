enable_from_this ��ʹ����ʵ��ԭ��˵����

shared_from_this()��enable_shared_from_this�ĳ�Ա����������shared_ptr;
ע����ǣ������������shared_ptr�Ĺ��캯��������֮�����ʹ�á�
ԭ����enable_shared_from_this::weak_ptr�����ڹ��캯�������ã�������shared_ptr�Ĺ��캯�������á�

ʹ�ó��ϣ���ǰ��A��ʵ����������share_ptr����������A�ĳ�Ա��������Ҫ�ѵ�ǰ�������Ϊ����������������ʱ������Ҫ����һ��ָ�����A��ʵ�����������share_ptr��

�����ʹ�ô���һ��

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


�������ͨ����ִ�н�����£�
D::D()
terminate called after throwing an instance of 'boost::exception_detail::clone_impl >'
  what():  tr1::bad_weak_ptr
Aborted

˵����D�Ĺ��캯���е���shared_from_this(), ��ʱD��ʵ��������δ����ɹ���weak_ptrҲ����δ����,���Գ����׳�tr1::bad_weak_ptr�쳣��


�����ʹ�ô������


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


�������ͨ����ִ�н�����£�
D::D()
D::func()
terminate called after throwing an instance of 'boost::exception_detail::clone_impl >'
  what():  tr1::bad_weak_ptr
Aborted

ʧ��ԭ�������

��������main�У�D��ʵ������ջ�Ϲ��죬û��ʹ��boost::shared_ptr �Ĺ��췽ʽ��
����boost::enable_shared_from_this�е�weak_ptr��ָ�ĺ�������Ҳ��û�б���ֵ��
�ڵ���d.func()��ʹ��shared_from_this()����ʱ

----ע��shared_from_this�ĺ���ʵ�� ------
    shared_ptr shared_from_this()
    {
        shared_ptr p( weak_this_ );
        BOOST_ASSERT( p.get() == this );
        return p;
    }
----ע��shared_from_this�ĺ���ʵ�� ------

����BOOST_ASSERT( p.get() == this );  ʧ�ܣ��׳������쳣��


������Ǹ���share_from_this()����ȷʹ������:



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


ִ�н��:
D::D()
D::func()