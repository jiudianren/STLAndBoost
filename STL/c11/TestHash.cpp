/*
 * TestHash.cpp
 *
 *  Created on: 2018年9月6日
 *      Author: Administrator
 */



#include "TeshHash.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// Key2 需要提供hash函数
struct Key2
{
    int age;
    string name;
};

class HashKey2
{
public:
    size_t operator ()(const Key2 & key) const
    {
        return std::hash<int>()(key.age) + std::hash<string >()(key.name);
    }

};


struct EqualKey
{
    bool operator () (const Key2 &lhs, const Key2 &rhs) const
    {
        return lhs.age  == rhs.age
            && lhs.name == rhs.name;
    }
};

struct Date
{
    long date;
};

#if 1
int mainUorderMapHash()
{

    std::unordered_map<Key2, Date, HashKey2,EqualKey> sessions;

    Key2 k1;
    k1.age = 10;
    k1.name += "name1";

    Date d1;
    d1.date =100;

    sessions.insert(std::make_pair(k1,d1));
    Key2 k2;
    k2.age = 11;
    k2.name += "name1";

    Date d2;
    d1.date =200;

    sessions.insert(std::make_pair(k2,d2));


    for(auto  it : sessions)
    {
        if(it.second.date >100)
        {
//            sessions.erase( it );
//            it = sessions.begin();
        }
    }

        return 0;
}
#endif

#if 0
void  mainMapHash()
{

    std::map<Key2, Date> sessions;

    Key2 k1;
    k1.age = 10;
    k1.name += "name1";

    Date d1;
    d1.date =100;

    sessions.insert(std::make_pair(k1,d1));
    Key2 k2;
    k2.age = 11;
    k2.name += "name1";

    Date d2;
    d1.date =200;

    sessions.insert(std::make_pair(k2,d2));


    for(auto  it : sessions)
    {
        if(it.second.date >100)
        {
//            sessions.erase( it );
//            it = sessions.begin();
        }
    }

}
#endif
