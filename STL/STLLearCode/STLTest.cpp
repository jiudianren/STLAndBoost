/*
 * STLTest.cpp
 *
 *  Created on: 2017��5��24��
 *      Author: Lian
 *   for ����STL�� ʹ��ʾ��
 *
 *   ���� �㷨  ������
 */


#include "../STL/STLTest.h"

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <iterator>
#include <map>
#include <utility>
#include <string.h>

using namespace std;

typedef  multimap<string,int>::iterator  mMapIter;

void doForEach(string temp)
{

	cout<<temp<<endl;
}

void TestForEach()
{

	std::list<string> listTemp;
	listTemp.push_back("i am the one");
	listTemp.push_back("i am the two");
	listTemp.push_back("i am the three");

	for_each(listTemp.begin(),listTemp.end(),doForEach);
}
/*Function Predicate*/
bool isLarger (const std::string &s1, const std::string &s2) {
	return s1.size() > s2.size();
}

bool  isLarger2 ( TMonitorKeyStats &s1,  TMonitorKeyStats &s2) {
    return  s1 < s2;
}

void TestMax()
{
	double a[]= {1.0, 2.0, 3.0, 4.0, 5.0, 1.0, 2.0, 3.0, 4.0, 5.0};
	std::vector<double> arr(a,a+10);

	std::vector<double>::iterator max = std::max_element(std::begin(arr), std::end(arr));
	//  vector<double>::iterator max=max_element(arr.begin(),arr.end());// ����Ҳ����������ʾ������max
	std::cout << "Max element is " << *max<< " at position " << std::distance(std::begin(arr), max) << std::endl;
	//���ֵһ���Ǵ�*  ���*max����ʾ������

	auto min = std::min_element(std::begin(arr), std::end(arr));
	std::cout << "min element is " << *min<< " at position " << std::distance(std::begin(arr), min) << std::endl;


}
//ν��
void  mainPredicat (void) {



	std::vector<std::string> sv = {"Beauty", "Girl", "Lady", "Women", "Pretty"};

	std::stable_sort(sv.begin(), sv.end(), isLarger);

	std::cout << "Function Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	std::stable_sort(sv.begin(), sv.end(),
			[](const std::string& s1, const std::string& s2){ return s1.size()>s2.size(); });

	std::cout << "Lambda Expression Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;


	bool (*pf) (const std::string &s1, const std::string &s2);
	pf = &isLarger;
	std::stable_sort(sv.begin(), sv.end(), *pf);
	std::cout << "Function Pointer Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;

	std::stable_sort(sv.begin(), sv.end(), LargerString());
	std::cout << "Function Object Predicate : ";
	std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	std::cout << std::endl;


	//    std::stable_sort(sv.begin(), sv.end(), std::larger<std::string>());
	//    std::cout << "Library-Defined Function Object Predicate : ";
	//    std::for_each(sv.begin(), sv.end(), PrintString(std::cout));
	//    std::cout << std::endl;


}


void backinsertIter()
{

	string ai="somethint to copy";
	string aim;
	replace_copy(ai.begin(), ai.end(), back_inserter(aim), 'o', 'p');
	cout<<"old: "<<ai <<"  new : "<<aim<<endl;

}


void mulitMapTest()
{


    multimap<string,int> mMap;
    mMap.insert(make_pair("strtrest",125));
    mMap.insert(make_pair("strtrest",126));
    mMap.insert(make_pair("strtrest",12));
    mMap.insert(make_pair("1",1));
    mMap.insert(make_pair("2",2));
    mMap.insert(make_pair("3",3));
    mMap.insert(make_pair("3",32));
    mMap.insert(make_pair("3",33));
    mMap.insert(make_pair("3",33));
    mMap.insert(make_pair("3",33));
    mMap.insert(make_pair("3",35));
    mMap.insert(make_pair("strtrest",122));
    mMap.insert(make_pair("strtrest",123));
    mMap.insert(make_pair("strtrest",124));

    //���� ����

    cout<<"Traversal all"<<endl;
    multimap<string,int>::iterator iter = mMap.begin();
    while( iter != mMap.end())
    {
        cout << iter->first <<" : "<< iter->second <<endl;
        iter ++;
    }

    //����ĳһ��ֵ

    cout<<"Traversal key"<<endl;
    multimap<string,int>::iterator iBegin = mMap.lower_bound("3"),
     iEnd = mMap.upper_bound("3");

    while( iBegin != iEnd)
    {
        cout << iBegin->first <<" : "<< iBegin->second <<endl;
        iBegin ++;
    }

    //����ĳһ��ֵ

    cout<<"Traversal key"<<endl;

     pair<mMapIter ,mMapIter> itPos = mMap.equal_range("3");


     for(; itPos.first!= itPos.second; itPos.first++)
     {
         cout << itPos.first->first <<" : "<< itPos.first->second <<endl;
     }

    //ɾ��ĳһ��ֵ
    cout<<"erase  key"<<endl;
    mMap.erase("strtrest");
    iter = mMap.begin();
    while( iter != mMap.end())
    {
        cout << iter->first <<" : "<< iter->second <<endl;
        iter ++;
    }

    //ɾ��ĳһ��ֵ �е�ĳһ�� ��Ҫͨ������������
    cout<<"erase  special key"<<endl;

    iBegin = mMap.lower_bound("3");
     iEnd = mMap.upper_bound("3");

    while( iBegin != iEnd)
    {
        if(iBegin->second == 32 )
        {
            mMap.erase(iBegin);
            break;
        }
        iBegin ++;
    }

    iter = mMap.begin();
    while( iter != mMap.end())
    {
        cout << iter->first <<" : "<< iter->second <<endl;
        iter ++;
    }

}
void stringIterator()
{
	string aa="it i s a good ";
	//sit is a string::iterator
	for(auto sit= aa.begin(); sit != aa.end(); sit++)
	{
	   *sit=toupper(*sit);
	}
	cout<<__func__<<" aa: " <<aa<<endl;
}

void TestMylist()
{
    TMonitorKeyStats st;
    list<TMonitorKeyStats> mylist;
    typedef list<TMonitorKeyStats>::iterator  listIt;

    for(int i=0; i<=3;i++)
    {
        st.Clear();

        st.sMonitorKeyName[0]='m';
        st.sMonitorKeyName[1]='k';
        st.sMonitorKeyName[2]='3';
        st.iInputOctets= 1;
        mylist.push_back(st);
    }


    for(int i=0; i<=3;i++)
    {
        st.Clear();
        st.sMonitorKeyName[0]='m';
        st.sMonitorKeyName[1]='k';
        st.sMonitorKeyName[2]='1';

        st.iInputOctets= 1;
        mylist.push_back(st);
    }

    for(int i=0; i<=3;i++)
    {
        st.Clear();

        st.sMonitorKeyName[0]='m';
        st.sMonitorKeyName[1]='k';
        st.sMonitorKeyName[2]='2';
        st.iInputOctets= 1;
        mylist.push_back(st);
    }

    listIt itemp;
    cout<<"befor sort"<<endl;
    itemp =mylist.begin();
    for(; itemp!= mylist.end(); itemp++)
    {
        itemp->ToString();
    }
    cout<<"aftel sort"<<endl;
    // sort �㷨 ��������list�������ο�c++ primer �������е��㷨
//    std::sort( mylist.begin(), mylist.end() , std::less<TMonitorKeyStats>());
//    mylist.sort(isLarger2);
    mylist.sort();
    itemp =mylist.begin();
    for(; itemp!= mylist.end(); itemp++)
    {
        itemp->ToString();
    }



    st.Clear();

    st.sMonitorKeyName[0]='m';
    st.sMonitorKeyName[1]='k';
    st.sMonitorKeyName[2]='2';
    st.iInputOctets= 2;
    mylist.push_back(st);

    st.Clear();
    st.sMonitorKeyName[0]='m';
    st.sMonitorKeyName[1]='k';
    st.sMonitorKeyName[2]='1';
    st.iInputOctets= 1;
    mylist.push_back(st);

    st.Clear();
    st.sMonitorKeyName[0]='m';
    st.sMonitorKeyName[1]='k';
    st.sMonitorKeyName[2]='3';
    st.iInputOctets= 3;
    mylist.push_back(st);



//    listIt itOut= mylist.begin();
//    bool bFlag =false;
//
////    while(itOut != mylist.end())
////    {
////    	listIt itInner = itOut;
////    	itOut->ToString();
////    	itInner++;
////    	while( itInner != mylist.end())
////    	{
////    		if( ! itOut->IsSame( *itInner))
////    		{
////    			itInner++;
////    			continue;
////    		}
////    		//�������������Ԫ����ͬ������Ҫ��ɾ����ͬ��֮ǰ���ȱ�����ɾ��λ�õ���һ��λ��
////			itOut->Add(*itInner);
////			itInner = mylist.erase(itInner);
////    	}
////    	itOut++;
////    }

    cout<<"aftel second sort"<<endl;
    mylist.sort();
    itemp =mylist.begin();
    for(; itemp!= mylist.end(); itemp++)
    {
        itemp->ToString();
    }


    //list�� unique��������ɾ��  unique֮���Ԫ�� �������е��㷨
    cout<<"unique "<<endl;
    // �㷨��unique�����ã�ֻ����list���Լ�unique
//    itemp =  unique( mylist.begin(),mylist.end());
    mylist.unique();
    listIt itemp2 = mylist.begin();

    for( ;itemp2 !=itemp; itemp2++ )
    {
        itemp2->ToString();
    }

    cout<<"unique  after "<<endl;
    for( ;itemp !=mylist.end(); itemp++ )
    {
        itemp->ToString();
    }
    cout<<"end sort"<<endl;
}



void mainSTLTest()
{
	cout<<"STLTEST================start"<<endl;
	//	mainPredicat();
	//	TestForEach();

	TestMax();
	ArryTest();
	stringIterator();
	backinsertIter();

	mulitMapTest();
	cout<<"STLTEST================end"<<endl;
}
