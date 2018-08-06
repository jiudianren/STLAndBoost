

/*
 *
 * http://www.cplusplus.com/reference/functional/
 *
 *
 *在函数对象这个层面 c++11 和c++98有很多对象 不一样，其中98中有很多被废弃
 * */

#include <iostream>     // std::cout
#include <functional>   // std::plus
#include <algorithm>    // std::transform

int main () {
  int first[]={1,2,3,4,5};
  int second[]={10,20,30,40,50};
  int results[5];
  std::transform (first, first+5, second, results, std::plus<int>());
  for (int i=0; i<5; i++)
	std::cout << results[i] << ' ';
  std::cout << '\n';



  std::pair<int*,int*> ptiter;
    int foo[]={10,20,30,40,50};
    int bar[]={10,20,40,80,160};
    ptiter = std::mismatch (foo, foo+5, bar, std::equal_to<int>());
    std::cout << "First mismatching pair is: " << *ptiter.first;
    std::cout << " and " << *ptiter.second << '\n';


    char nts1[] = "Test";
     char nts2[] = "Test";
     std::string str1 (nts1);
     std::string str2 (nts2);

     std::hash<char*> ptr_hash;
     std::hash<std::string> str_hash;

     std::cout << "same hashes:\n" << std::boolalpha;
     std::cout << "nts1 and nts2: " << (ptr_hash(nts1)==ptr_hash(nts2)) << '\n';
     std::cout << "str1 and str2: " << (str_hash(str1)==str_hash(str2)) << '\n';

  return 0;
}




struct int_holder {
  int value;
  int triple() {return value*3;}
};

int main_Memfn () {
  int_holder five {5};

  // call member directly:
  std::cout << five.triple() << '\n';

  // same as above using a mem_fn:
  auto triple = std::mem_fn (&int_holder::triple);
  std::cout << triple(five) << '\n';
