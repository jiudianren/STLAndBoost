/*
 * example.cpp
 *
 *  Created on: 2018Äê1ÔÂ12ÈÕ
 *      Author: Administrator
 */




#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}
