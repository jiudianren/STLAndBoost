/*
 * Ttuple.cpp
 *
 *  Created on: 2018Äê5ÔÂ5ÈÕ
 *      Author: Administrator
 */

#include <tuple>

#include <string>
#include <iostream>
using namespace std;
int mainTuple()
{


	string myS;
	auto myTuple = make_tuple( ref(myS));
	get<0>(myTuple).append("sss");
	cout<<myS<<endl;

	std::tuple < int ,std::string > t (12,"mys");
	int a;
	string ss;
	make_tuple( ref(a),ref(ss)) =t;


	int a1;
	string s2;
	std::tie( a1,s2) =t;



	return 0;

}

