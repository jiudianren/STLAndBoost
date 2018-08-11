/*
 * RTTITest.h
 *
 *  Created on: 2017Äê12ÔÂ26ÈÕ
 *      Author: Administrator
 */

#ifndef SRC_STLTEST_RTTITEST_H_
#define SRC_STLTEST_RTTITEST_H_

#if 0
#include <map>
#include <typeinfo>

#include <string>
class CDataType
{
};


class CDataTypeA : public CDataType
{
};
class CDataTypeB : public CDataType
{
};



class CreatorType {};
class CreatorForDataA : public CreatorType {

};
class CreatorForDataB : public CreatorType {};

typedef std::string KeyType;

static std::map<std::string, CreatorType*> nameMap;


void RegistCreator(KeyType key, CreatorType* creator)
{
    nameMap[key] = creator;
}

CreatorType* GetCreator( CDataType* data)
{
    return nameMap[ typeid(*data).name()];
}


struct A {
    virtual ~A() {}
};

struct B : A {};
struct C : A {};

#endif /* SRC_STLTEST_RTTITEST_H_ */

#endif
