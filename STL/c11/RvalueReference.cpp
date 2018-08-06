/*
 * RvalueReference.cpp
 *
 *  Created on: 2018年5月4日
 *      Author: Administrator
 */


/*
 * 类在包含有指针成员的时候
 * 注意浅拷贝，还是深拷贝
 *
 * */

#include <string>
#include <iostream>

#include "c11.h"

using namespace std;
class HasPtrMem
{

public:

	HasPtrMem():a(new int(10))
	{
		cout<< "construct"<< ++i_cstr <<std::endl;
	}

	HasPtrMem (const HasPtrMem & refT):a ( new int ( *refT.a))
	{
		cout<< "copy"<< ++i_cpstr <<std::endl;
	}

	~HasPtrMem()
	{
		cout<< "delete "<< ++i_dstr <<std::endl;
	}

	/*移动语义
	 * 其中 HasPtrMem && 标识右值引用
	 *
	 * */

	HasPtrMem (HasPtrMem && h ): a(h.a)
	{
		h.a= NULL;
		cout<< "mv "<< ++i_mvstr <<std::endl;
	}
	int * a;
	static int i_cstr;
	static int i_cpstr;
	static int i_dstr;
	static int i_mvstr;


};
int HasPtrMem::i_cstr=0;
int HasPtrMem::i_cpstr=0;
int HasPtrMem::i_dstr=0;
int HasPtrMem::i_mvstr=0;

HasPtrMem get() { return HasPtrMem() ;}


int mainTe()
{
    HasPtrMem a= get();
    HasPtrMem b;
    HasPtrMem c =std::move(b);
 //b并没有被销毁，但b已经不能使用
   //这里只是为了掩饰，实际b并没有消失，但并不能使用 ，说明b的生命周期不对

   //完美转发 在模板中有所使用
	return 0;

}

