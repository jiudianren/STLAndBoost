hpp�ļ� �� .h .cpp������ �Լ�ע������


http://blog.chinaunix.net/uid-24118190-id-75239.html

hpp,��ʵ�ʾ��ǽ�.cpp��ʵ�ִ������.hͷ�ļ����У�������ʵ�ֶ�������ͬһ�ļ��������ĵ�����ֻ��Ҫinclude��hpp�ļ����ɣ������� ��cpp���뵽project�н��б��롣
��ʵ�ִ��뽫ֱ�ӱ��뵽�����ߵ�obj�ļ��У��������ɵ�����obj,����hpp������ȼ��ٵ��� project�е�cpp�ļ�������������Ҳ�����ٷ������˵�lib��dll,��˷ǳ��ʺ�������д���õĿ�Դ�⡣

1����Header Plus Plus �ļ�д��  
2����*.h���ƣ�hpp��C++����ͷ�ļ� ��  
3����VCL ר�õ�ͷ�ļ�,��Ԥ���롣  
4����һ��ģ�����ͷ�ļ���  
5��һ����˵��*.h����ֻ��������û��ʵ�֣���*.hpp������ʵ�ֶ��У����߿��Լ� ��.cpp��������  
6��*.h���������using namespace std����*.hpp�����ޡ�  
7��*.hppҪע��������У�

      a)���ɰ���ȫ�ֶ����ȫ�ֺ���
     ����hpp����������Ϊ.h��������include�����Ե�hpp�ļ��д���ȫ�ֶ������ȫ�ֺ���������hpp�����������includeʱ����������ʱ���·����ض������Ҫ���������������Ҫȥ��ȫ�ֶ��󣬽�ȫ�ֺ�����װΪ��ľ�̬������

      b)��֮�䲻��ѭ������
      ��.h��.cpp�ĳ����У�����������߶����֮����ѭ�����ù�ϵʱ��ֻҪԤ����ͷ�ļ�������������������ɣ����£�

    class B;
     class A{
     public:
     void someMethod(B b);
     };
     class B{
     public:
     void someMethod(A a);
     };


��hpp�����У����ڶ�����ʵ�ֶ��Ѿ�������һ���ļ��������߱�����ȷ֪���������ߵ����ж��壬�����ܵȵ�cpp��ȥ���롣
���hpp�б���������֮����ù�ϵ�����ɲ���ѭ�����á�
ͬ�����ڵ�������A��B�ֱ����ڸ��Ե�hpp�ļ��У��������µ�ѭ������Ҳ�����±������


     //a.hpp
     #include "b.hpp"
     class A{
     public:
     void someMethod(B b);
     };
     
     //b.hpp
     #include "a.hpp"
     class B{
     public:
     void someMethod(A a);
     }


c)����ʹ�þ�̬��Ա

      ��̬��Ա��ʹ��������������ຬ�о�̬��Ա������hpp�б�����뾲̬��Ա��ʼ�����룬
      ����hpp������ĵ�includeʱ�������������ض������
      Ψ һ��������const static���ͳ�Ա����Ϊ��vs2003�У������������ڶ���ʱ��ʼ�����磺
     class A{
     public:
     const static int intValue = 123;
     };
     ���ھ�̬��Ա��ʹ���Ǻܳ����ĳ������޷�ǿ���������˿��Կ������¼��ַ�ʽ������ʾ����Ϊͬһ���з�����

   һ�����н���һ����̬��Աʱ���ҽ���һ��������ʱ������ͨ������̬����ģ��


    //����ģ���ȡ��̬��Ա

     someType getMember()
     {
     static someType value(xxx);//�������ھ�̬����

     return value;
     }


����.�����ж��������Ҫ���þ�̬��Ա�����ҿ��ܴ��ڶ����̬��Աʱ�����Խ�ÿ����̬��Ա��װһ��ģ�ⷽ�����������������á�

    someType getMemberA()
     {
     static someType value(xxx);//�������ھ�̬����

     return value;
     }
     someType getMemberB()
     {
     static someType value(xxx);//�������ھ�̬����

     return value;
     }
     void accessMemberA()
     {
     someType member = getMemberA();//��ȡ��̬��Ա

     };
     //��ȡ������̬��Ա

     void accessStaticMember()
     {
     someType a = getMemberA();//��ȡ��̬��Ա

     someType b = getMemberB();
     };

�����ڶ��ַ������ڴ󲿷������ͨ�õģ����ǵ�����ľ�̬��Ա����ʱ����д��װ�����Ĺ��������ǳ��޴��ڴ�������£�����ʹ��Singletonģʽ�����������ඨ�����ͨ�࣬Ȼ��ʹ��Singleton�����Ϊȫ��Ψһ�Ķ�����е��á�

     ��ԭh+cpp�µĶ������£�


    class A{
     public:
     type getMember(){
     return member;
     }
     static type member;//��̬��Ա

     }

 ����singleton��ʽ��ʵ�ִ���������£�singletonʵ�������в�������ĵ���


    //ʵ��ʵ����

     class Aprovider{
     public:
     type getMember(){
     return member;
     }
     type member;//��Ϊ��ͨ��Ա

     }
     //�ṩ�������ߵĽӿ���

     class A{
     public:
     type getMember(){
     return Singleton<AProvider>::getInstance()->getMember();
     }
     }