/*
 * TesetRemove.cpp
 *
 *  Created on: 2018Äê5ÔÂ6ÈÕ
 *      Author: Administrator
 */


#include <list>
#include <iostream>
#include <algorithm>
using namespace std;
int mainRv()
{

	list<int> roll;

	for (int i =0; i <7 ;i ++)

	{
		roll.push_back(i);
		roll.push_front(i);
	}

	cout<<"pre: "<<std::endl;
	for (auto i : roll)
	{
		cout<<" "<<i;
	}

	remove( roll.begin(),roll.end(), 3);

	cout<<"after: "<<std::endl;
	for (auto i : roll)
	{
		cout<<" "<<i;
	}


	list<int> rodd;

	for (int i =0; i <7 ;i ++)

	{
		rodd.push_back(i);
		rodd.push_front(i);
	}
	auto actualend = remove( rodd.begin(),rodd.end(), 3);

	rodd.erase(actualend, rodd.end());

	cout<<"after: "<<std::endl;
	for (auto i : rodd)
	{
		cout<<" "<<i;
	}



	return 0;
}

