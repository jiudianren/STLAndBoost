/*front_insert_iterator*/

/*
 * http://www.cplusplus.com/reference/iterator/front_insert_iterator */


#include <iostream>
#include <iterator>     // std::front_insert_iterator
#include <deque>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include "IterratorTest.h"


using namespace std;

int main () {
  std::deque<int> foo, bar;
  for (int i=1; i<=5; i++)
  { foo.push_back(i); bar.push_back(i*10); }

  std::front_insert_iterator< std::deque<int> > front_it (foo);

  /*����copy ʹ�õ�iterator �ǰ������壬���� ��ǰ����֮ǰ ��ֵ����  */
  std::copy (bar.begin(),bar.end(),front_it);


 if( front_it.iterator_category ==  output_iterator_tag)
 {
	 std::cout<<"lpf"<<std::endl;

 }
  std::cout << "foo:";
  for ( std::deque<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
	  std::cout << ' ' << *it;
  std::cout << '\n';



  /*����copy�� �� myvector.begin() �ĵ�������  ��������  */

  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector (7);

  std::copy ( myints, myints+7, myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;


  return 0;
}


/*
 * ɾ�� vector�е��ظ�Ԫ�أ�
 * */

int removeDuplicates(vector<int>& nums)  {
    map<int,int> tmp_map;


    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it){
        tmp_map[*it]++;
        if(tmp_map[*it] != 1){


            /*
              ������룬ɾ����vector���ظ����ֵ�Ԫ�أ�ֻ�����˵�һ�γ��ֵ�Ԫ�ء�
              ���д��뷢�ֻ����ԭ����ǵ�erase����ִ��һ��֮�����ĵ������ͻ�ʧЧ��
            ����erase�������Է�����һ�����õĵ����������ֻҪ�����������ֵ����Խ��������⣬������ע�͵�����������ȷ���߼���
    erase������������һ�����õĵ���������������for ѭ���и������Ķ�������˻�����������֮��ݼ�һ����ʱ����������������
             */

//            nums.erase(it);

            it = nums.erase(it);
            it--;


        }
    }
    for(auto c : nums)
        cout<<c<<endl;
    return nums.size();
}


void TTit()
{

    int a=10;
    std::list<int *> alist;
    alist.push_back( &a);

    std::list<int*>::iterator it =alist.begin();

    printf( "%d \n", *it);
    int * temp= *it;
    printf( "%d \n",   *temp  );

}

void TT()
{

    int type =111;
    int  a1= 10;
    int  a2= 11;
    int  a3= 13;


    printf("%d \n", a1);
    printf("%d \n", a2);
    printf("%d \n", a3);

    std::map<int ,std::list<int *> > mapTest;

    std::list<int *>  alist;
    alist.push_back( &a1);
    alist.push_back( &a2);
    alist.push_back( &a3);

    mapTest.insert( std::make_pair(type,   alist ))

        std::map<int ,std::list<int *> >::iterator  it =  mapTest.find(type);
    if ( it !=  mapTest.end())
    {

        for ( auto innerit :  it->second )
        {
            (*innerit)  ++;
        }
    }

    printf("%d \n", a1);
    printf("%d \n", a2);
    printf("%d \n", a3);

}





void TestIstream_iterator()
{

	  double value1, value2;
	  std::cout << "Please, insert two values: ";

	  std::istream_iterator<double> eos;              // end-of-stream iterator
	  std::istream_iterator<double> iit (std::cin);   // stdin iterator

	  if (iit!=eos) value1=*iit;

	  ++iit;
	  if (iit!=eos) value2=*iit;

	  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

	}
