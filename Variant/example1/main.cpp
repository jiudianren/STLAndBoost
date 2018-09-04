/*
 * main.cpp
 *
 *  Created on: 2018Äê8ÔÂ31ÈÕ
 *      Author: Administrator
 */


#include <iostream>
#include <boost/variant.hpp>

class printer_visitor : public boost::static_visitor <void>
{
public:
    void operator ()(int i) const
    {
        std::cout << "int : " << i << std ::endl;
    }

    void operator ()(std:: string& s ) const
    {
        std::cout << "string : " << s << std ::endl;
    }

    void operator ()(double d) const
    {
        std::cout << "double : " << d << std ::endl;
    }
};
int main ()
{
    boost::variant <int, std::string , double> u;
    printer_visitor visitor ;
    u = 4;
    boost::apply_visitor (visitor, u);
    u = "hello world!" ;
    boost::apply_visitor (visitor, u);
    u = 1.2;
    boost::apply_visitor (visitor, u);
}
