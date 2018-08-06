
#include <boost/foreach.hpp>
#include <vector>
#include <iostream>


void test_foreach()
{

    std::vector<int> a1;
    std::vector<int> a2;

    a1.push_back(1);
    a1.push_back(3);
    a1.push_back(5);

    a2.push_back(2);
    a2.push_back(4);
    a2.push_back(6);

    std::vector<std::vector<int> > matrix_int;

    matrix_int.push_back(a1);
    matrix_int.push_back(a2);


    BOOST_FOREACH( std::vector<int> & row, matrix_int )
        BOOST_FOREACH( int & i, row )
            ++i;

    BOOST_FOREACH( std::vector<int> & row, matrix_int )
         BOOST_FOREACH( int & i, row )
         { std::cout<<i<<std::endl;}
}


int main()
{
    test_foreach();

    return 0;

}
