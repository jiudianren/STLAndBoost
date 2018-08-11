/*
 * StringTest.cpp
 *
 *  Created on: 2018Äê5ÔÂ25ÈÕ
 *      Author: Administrator
 */


#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define SIMPLE_SCPY(dest,src) memccpy(dest,src,'\0',sizeof(dest)-1); dest[sizeof(dest)-1]='\0';
using namespace std;
void EncodeUseNo()
{
    static string sMess;

    char sLastMessage [256]={"aabb150,ccdd150,ee150,ss150"};

    sMess.clear();
    sMess.append(sLastMessage);
    string m_sUserNo("150");
    string m_sEncodeUesrNO("051");

    int iLength = m_sUserNo.size();

    cout<<sMess<<endl;
    std::size_t found =  sMess.find(m_sUserNo);
    while(found  != std::string::npos )
    {
        sMess.replace( found,  iLength, m_sEncodeUesrNO);
        cout<<sMess<<endl;
        found =  sMess.find(m_sUserNo);
    }

    SIMPLE_SCPY(sLastMessage, sMess.c_str());
    cout<< sLastMessage << std::endl;
}

int main()
{
    EncodeUseNo();

}
