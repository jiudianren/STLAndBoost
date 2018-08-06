/*
 * TestFindorIf.cpp
 *
 *  Created on: 2018��5��3��
 *      Author: Administrator
 */



/*
 *
 *
 * find: ����equality��������ѭ������[first,last)�ڵ�����Ԫ�أ�
 * �ҳ���һ��ƥ��"��ͬ(equality)����"�ߡ�����ҵ����ͷ���һ��InputIteratorָ���Ԫ�أ����򷵻ص�����last��


template<class InputIterator,class T>
InputIterator find(InputIterator first,InputIterator last,const T& value)

find_if������ָ����pred�����������Էº�����ʾ����
ѭ������[first,last)�ڵ�����Ԫ�أ��ҳ���һ����pred������true�ߡ�
����ҵ��ͷ���һ��InputIteratorָ���Ԫ�أ�����ͷ��ص�����last��



template<class InputIterator,class Predicate>
InputIterator find_if(InputIterator first,InputIterator last,Predicate pred)

 *
 *
 * */


#include "../STL/TestFindorIf.h"

#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<string>


using namespace std;

class Student
{
public:
    Student():score(0){}
    Student(string iname,float iscore):name(iname),score(iscore){}
    ~Student(){}

    string name;
    float score;
};

class StudentAdapter:public unary_function<Student,bool>
{
private:
    string name;
public:
    explicit StudentAdapter(string iname):name(iname){}

    StudentAdapter():name("null"){}

    //for find_if
    bool operator()(const Student& student)
    {
        return (student.name==name);
    }


    //for sort
    bool operator ()(const  Student *sd1, const Student  *sd2) const
     {
         return sd1->score > sd2->score;
     }
};

int mainFind()
{
    vector<Student> admin;
    vector<Student>::iterator pos;


    Student stu1("lanzhihui",89.1);
    Student stu2("wangdan",89.2);
    Student stu3("wangqian",89.3);



    admin.push_back(stu1);
    admin.push_back(stu2);
    admin.push_back(stu3);

    for(pos=admin.begin();pos!=admin.end();++pos)
    {
        cout<<pos->name<<" "<<pos->score<<endl;
    }
    cout<<endl;




    //ʵ��find_if
    pos=find_if(admin.begin(),admin.end(),StudentAdapter("lanzhihui"));

    if(pos!=admin.end())
    {
        cout<<pos->name<<" "<<pos->score<<endl;
    }

    //����ʵ��find
    vector<int> coll;
    vector<int>::iterator pos1;
    for(int i=0;i<10;i++)
    {
        coll.push_back(i);
    }

    pos1=find(coll.begin(),coll.end(),5);

    if(pos1!=coll.end())
    {
        cout<<*pos1<<" is find"<<endl;
    }

    //sort
    pos=std::sort(admin.begin(),admin.end(),StudentAdapter());


    return 0;
}
