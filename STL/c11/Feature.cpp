/*
 * Feature.cpp
 *
 *  Created on: 2018��5��5��
 *      Author: Administrator
 */


#include "c11.h"
#include <vector>
#include <string>

using namespace std;

//���fos �׳��쳣������򽫻�ֹͣ
void fos() noexcept;

int mainFe()
{
	//һ���Գ�ʼ��
	int value[] {1,2,3,4};

	vector<int> iV {1,3,4};
	vector<string > vStr {"s1", "s3","s4"};
//  std::initializer_list<int> ss;

	//raw string
	string sR (R"(\\n)");

	string s2(  "\\\\n");
	return 0;
}
