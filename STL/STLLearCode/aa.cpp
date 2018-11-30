/*
 * aa.cpp
 *
 *  Created on: 2018Äê11ÔÂ26ÈÕ
 *      Author: lian.pengfei
 */



#include <stdio.h>
#include <string>
#include <string.h>
#include <memory>

struct TStaleSessST
{
    char  sInterfaceName[10];
    long iSessReadyForCleanUp;
    long iSessionCleaned;
    long iReauthorCleaned;


    TStaleSessST()
    {
        Clear();
    }

    bool operator== ( TStaleSessST  &pTemp) \
            {                                                                \
        if( IsSame(pTemp) )                                          \
        {                                                            \
            Add(pTemp);                                              \
            return true;                                             \
        }                                                            \
        else                                                         \
        {                                                            \
            return false;                                            \
        }                                                            \
            }



    void Clear( void )

    {
        memset(sInterfaceName, 0, 10 );
        iSessReadyForCleanUp=0 ;
        iSessionCleaned     =0 ;
        iReauthorCleaned    =0 ;

    }
    bool IsSame(const TStaleSessST & pTemp)

    {
        bool bRes= false;
        if( strcmp( sInterfaceName, pTemp.sInterfaceName) == 0 )
        {
            bRes = true;
        }
        return bRes;
    }
    void Add(const TStaleSessST  & pTemp)
    {
        iSessReadyForCleanUp += pTemp.iSessReadyForCleanUp;
                iSessionCleaned += pTemp.iSessionCleaned;
                iReauthorCleaned += pTemp.iReauthorCleaned;
    }
    bool operator< ( TStaleSessST  &pTemp) const
    {
        if(  strcmp( sInterfaceName, pTemp.sInterfaceName) < 0  )
        {
           return true;
        }
        else
        {
            return false;
        }
    }
};

void Add()
{

    TMonitorKeyStats * pTemp = (TMonitorKeyStats *)pStatContext;
             m_listMKStats.push_back( (*pTemp));
}
int main()
{


    void ReportStatisMgr::AddStats( int iRepItem , void * pStatContext )

}



