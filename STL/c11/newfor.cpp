/*a
 * newfor.cpp
 *
 *  Created on: 2018Äê5ÔÂ4ÈÕ
 *      Author: Administrator
 */


#include "c11.h"

#include <vector>
#include <algorithm>


#include <unordered_map>

using namespace std;

int mainFor()
{

	int arry[5] ={1,3,2,4,5};
	for ( auto & e: arry)
	{
		e *=2;
	}

	vector<int> aa={1,3,2,4};

	for( auto e: {1,4,5,6})
	{
		//todo
	}

	int arr[] ={1,3,4,6,6,8};
	auto it=std::begin(arr);
	while( it != std::end(arr))
	{


		it++;
	}

	return 0;
}
