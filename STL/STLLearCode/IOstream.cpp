
#include <iostream>
#include <fstream>

using namespace std;


int main()
{
    std::ostringstream os;

    os
    << "PID="               << "sss1"
    << "|PNAME="            << "CDR_InDB"

    << "\n";

    string s1 = os.str();
    cout<<s1;

     os
     << "PID="               << "sss1"
     << "|PNAME="            << "CDR_InDB"
     << "\n";

    string s2= os.str();
     cout<<s2.substr(s1.size() );

}
