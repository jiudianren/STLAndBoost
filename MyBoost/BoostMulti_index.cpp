/*
 * BoostMulti_index.cpp
 *
 *  Created on: 2018Äê6ÔÂ21ÈÕ
 *      Author: Administrator
 */


/*
 *https://www.boost.org/doc/libs/1_62_0/libs/multi_index/doc/index.html
 *
 *
 *https://blog.csdn.net/liuqiuyuewo/article/details/75332345
 * */

#include <string>
#include <iostream>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>

using namespace boost;
using namespace boost::multi_index;
using namespace std;
struct Person{
  int id;
  int age;
  int height;
  string name;

  Person(int id_,int age_,int height_,std::string name_):
    id(id_),
    age(age_),
    height(height_),
    name(name_)
    {}
};

std::ostream& operator<<(std::ostream& os,const Person& ps)
{
  os<<ps.id<<" "<<ps.age<<" "<<ps.height<<" "<<ps.name<<" "<<std::endl;
  return os;
}

typedef multi_index_container<
  Person,
  indexed_by<
    ordered_unique<member<Person, int, &Person::id> >,
    ordered_non_unique<member<Person, int, &Person::age> >,
    ordered_non_unique<member<Person, int, &Person::height> >,
    ordered_non_unique<member<Person, string, &Person::name> >
> >PersonContainer;

typedef PersonContainer::nth_index<0>::type IdIndex;
typedef PersonContainer::nth_index<1>::type AgeIndex;
typedef PersonContainer::nth_index<2>::type HeightIndex;
typedef PersonContainer::nth_index<3>::type NameIndex;




struct person_id{};
struct person_age{};
struct person_height{};
struct person_name{};

typedef multi_index_container<
  Person,indexed_by<
    ordered_unique< tag<person_id>,member<Person, int, &Person::id> >,
    ordered_non_unique< tag<person_age>,member<Person, int, &Person::age> >,
    ordered_non_unique< tag<person_height>,member<Person, int, &Person::height> >,
    ordered_non_unique<tag<person_name>,member<Person, string, &Person::name> >
> >PersonContainerTag;

int main(){
  PersonContainer con;
  con.insert(Person(2,31,170,"aliu"));
  con.insert(Person(1,27,164,"dliu"));
  con.insert(Person(0,55,182,"cliu"));
  con.insert(Person(3,51,142,"bliu"));


  IdIndex& ids = con.get<0>();
  copy(ids.begin(),ids.end(), ostream_iterator<Person>(cout));
  cout << endl;

  AgeIndex& ages = con.get<1>();
  copy(ages.begin(), ages.end(), ostream_iterator<Person>(cout));
  cout << endl;

  HeightIndex& heights = con.get<2>();
  copy(heights.begin(), heights.end(), ostream_iterator<Person>(cout));
  cout << endl;

  NameIndex& names = con.get<3>();
  copy(names.begin(), names.end(), ostream_iterator<Person>(cout));
  cout << endl;



  PersonContainerTag con_tag;
  con_tag.insert(Person(2,31,170,"aliu"));
  con_tag.insert(Person(1,27,164,"dliu"));
  con_tag.insert(Person(0,55,182,"cliu"));
  con_tag.insert(Person(3,51,142,"bliu"));

  auto& ids_tag = con_tag.get<person_id>();
  copy(ids_tag.begin(),ids_tag.end(), ostream_iterator<Person>(cout));
  cout << endl;

  auto& ages_tag = con_tag.get<person_age>();
  copy(ages_tag.begin(), ages_tag.end(), ostream_iterator<Person>(cout));
  cout << endl;

  auto& heights_tag = con_tag.get<person_height>();
  copy(heights_tag.begin(), heights_tag.end(), ostream_iterator<Person>(cout));
  cout << endl;

  auto& names_tag = con_tag.get<person_name>();
  copy(names_tag.begin(), names_tag.end(), ostream_iterator<Person>(cout));
  cout << endl;

  return 0;
}
