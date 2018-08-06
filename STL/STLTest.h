/*
 * STLTest.h
 *
 *  Created on: 2017��5��24��
 *      Author: Lian
 */


/*
 * virtualFuction.h
 *
 *  Created on: 2017��5��24��
 *      Author: Lian
 */

#ifndef STLTEST_H_
#define STLTEST_H_
#include <iostream>
#include <string>
#include <string.h>
#include <list>
using namespace std;


//��������
class PrintString {
public:
    PrintString (std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) { }
    void operator() (const std::string &s) const { os << s << sep; }
private:
    std::ostream &os;
    char sep;
};

/*Function Predicate*/
bool isLarger (const std::string &s1, const std::string &s2) ;

/*Function Object*/
class LargerString {
public:
    bool operator() (const std::string& a, const std::string& b) {
        return a.size() > b.size();
    }
};




struct  TMonitorKeyStats
{

    char sMonitorKeyName[60+1];

    int iTotalOctets;
    int iInputOctets;

    bool operator< ( TMonitorKeyStats  &t1) const{
        if( strcmp(sMonitorKeyName, t1.sMonitorKeyName ) < 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool add(const TMonitorKeyStats &t1) {
        if(strcmp(sMonitorKeyName, t1.sMonitorKeyName )==0 )
        {
            iTotalOctets+= t1.iTotalOctets;
            iInputOctets+= t1.iInputOctets;
            return true;
        }
        else
        {
            return false;
        }
    }


    bool operator==(const TMonitorKeyStats &t1) {
        if(strcmp(sMonitorKeyName, t1.sMonitorKeyName )==0 )
        {
            iTotalOctets+= t1.iTotalOctets;
            iInputOctets+= t1.iInputOctets;
            return true;
        }
        else
        {
            return false;
        }
    }

    void Clear( void ){
        memset(sMonitorKeyName,0,60+1);
        this->iTotalOctets=0;
        this->iInputOctets=0;
    };

    void  ToString(void ){

        std::cout<< sMonitorKeyName<<":"<<iTotalOctets<<","<<iInputOctets<<endl;
    };

    bool IsSame(TMonitorKeyStats  & pMonKeyStats)
    {
        bool bRes= false;
        //�����ַ���Ŀ��ͬ ����Ϊ��ͬһ�� ͳ����
        //sStartTime sEndTime sPolicyServer ��ͬ���ſ���
        //�ַ����Ƚ�   ����Ƚϣ��ж�ͳ�Ƽ�¼�Ƿ���ͬ
        if( strcmp( sMonitorKeyName, pMonKeyStats.sMonitorKeyName) == 0 )
        {
            bRes = true;
        }
        return bRes;
    }
    void Add(TMonitorKeyStats  & pMonKeyStats)
    {
        iTotalOctets+=pMonKeyStats.iTotalOctets;
        iInputOctets+=pMonKeyStats.iInputOctets;
    }


};

void TestMylist();
void backinsertIter();
void stringIterator();


void TestMax();
void mainPredicat();
void mulitMapTest();
void mainSTLTest();

void doForEach(string temp);
void TestForEach();

#endif /* VIRTUALFUCTION_H_ */
