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
#include <boost/regex.hpp>
#include <iostream>
#include <string>

int main()
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
