#include "c11.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include "c11_test.h"
#include "debug.h"

using namespace std;


void testAuto()
{
	__FUNC_LOGn();
	int a =1;
	auto b = a;

	//not ok  auto ��ռλ�������������Ͷ�����һ��
//	auto z;
//	z= b;
	cout<<"b:"<<b<<"a:"<< a <<endl;
	__FUNC_LOGn();
}

void TestAutoInner1()
{
	vector< string > vect_Temp;
	vect_Temp.push_back("aa");
	vect_Temp.push_back("bb");
	vect_Temp.push_back("cc");
	vect_Temp.push_back("dd");

	//old
	std::vector<string >::iterator it= vect_Temp.begin();
	cout<<"old "<<endl;
	for(; it!=vect_Temp.end(); it++)
	{
	    cout<<*it<<endl;
	}

	//new
	auto autoit=vect_Temp.begin();
	cout<<"new"<<endl;
	for(;autoit != vect_Temp.end(); autoit++)
	{
	    cout<<*autoit <<endl;
	}

	cout<<"for(auto it:vect_Temp ) "<<endl;
	for(auto& it : vect_Temp )
	{
	    cout<<it <<endl;
	}

}

/*��̬����   ���ڱ����ڼ���ж���
 * ��̬���ԣ������������ʱ�򣬲���֪�����*/

/*
 * http://www.cnblogs.com/QG-whz/p/4952980.html
 *
 * ���e��һ��û�д����ŵı�Ƿ����ʽ�������Ա���ʱ��ʽ����ô��decltype��e������e��������ʵ������͡�
 * ���⣬���e��һ�������صĺ�������ᵼ�±������
���� ������e��������T�����e��һ������ֵ����ôdecltype��e��ΪT&&
���򣬼���e��������T�����e��һ����ֵ����ôdecltype��e��ΪT&��
���򣬼���e��������T����decltype��e��ΪT��
 * */
void testDeclType()
{
	__FUNC_LOGn();
	int a =1;
	decltype (a) b =1;
	int d=2;
    decltype( (a)) c= d;  //����c��int &
    c = 100;
	cout<<"b:"<<b <<"c:"<<c <<endl;
}


void mainC11()
{
	cout<<"<<<<<<<<<test c++ 11 start:"<<endl;

	testAuto();
//	TestAutoInner1();


	testDeclType();
	cout<<"<<<<<<<<<test c++ 11 end"<<endl;

}
