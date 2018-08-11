/*
 * example.cpp
 *
 *  Created on: 2018年1月12日
 *      Author: Administrator
 */




#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/regex.hpp>
#include <iostream>
#include <string>

#include "example.h"

int mainExample1()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );
}


/*
 * example2.cpp
 *
 *  Created on: 2018年1月12日
 *      Author: Administrator
 */

/**
 *g++ example2.cpp -o example  -L/home/phub/boost_1_66_0/BoostIntallLPF/lib -lboost_regex

 运行
  example < path/to/jayne.txt
 */


int mainExample2()
{
    std::string line;
    boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

    while (std::cin)
    {
        std::getline(std::cin, line);
        boost::smatch matches;
        if (boost::regex_match(line, matches, pat))
            std::cout << matches[2] << std::endl;
    }
}
