/*
 * RvalueReference.cpp
 *
 *  Created on: 2018��5��4��
 *      Author: Administrator
 */


/*
 * ���ڰ�����ָ���Ա��ʱ��
 * ע��ǳ�������������
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

	/*�ƶ�����
	 * ���� HasPtrMem && ��ʶ��ֵ����
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
 //b��û�б����٣���b�Ѿ�����ʹ��
   //����ֻ��Ϊ�����Σ�ʵ��b��û����ʧ����������ʹ�� ��˵��b���������ڲ���

   //����ת�� ��ģ��������ʹ��
	return 0;

}

