#include <vector>
#include <boost/spirit.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_object.hpp>

std::vector<int> g_output;

int on_parse_int(const int val)
{
   g_output.push_back(val);
}

int main()
{
   boost::spirit::rule<> int_csv_rule = int_p[on_parse_int] >> *(',' >> int_p[on_parse_int]);
   boost::spirit::parse("2,3,4", int_csv_rule);
   return 0;
}
