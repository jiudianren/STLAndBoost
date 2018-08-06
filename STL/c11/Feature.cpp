/*
 * Feature.cpp
 *
 *  Created on: 2018年5月5日
 *      Author: Administrator
 */


#include "c11.h"
#include <vector>
#include <string>

using namespace std;

//如果fos 抛出异常，则程序将会停止
void fos() noexcept;

int mainFe()
{
	//一致性初始化
	int value[] {1,2,3,4};

	vector<int> iV {1,3,4};
	vector<string > vStr {"s1", "s3","s4"};
//  std::initializer_list<int> ss;

	//raw string
	string sR (R"(\\n)");

	string s2(  "\\\\n");
	return 0;
}
