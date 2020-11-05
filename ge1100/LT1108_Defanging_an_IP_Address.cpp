
#include "../header/myheader.h"

#include <regex>


class LT1108
{
public:


// D D

//return regex_replace(address, regex("[.]"), "[.]");
// cpp de
// cpp 11 de . 但我这里不是cpp11吗。。。md,搞不懂。
// g++ -v : gcc version 7.4.0 (Ubuntu 7.4.0-1ubuntu1~18.04.1)
// md，头文件呢。。。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defanging an IP Address.
//Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Defanging an IP Address.
    string lt1108a(string address)
    {
        int idot = 0;
        while ((idot = address.find('.', idot)) != std::string::npos)
        {
            address.replace(idot, 1, "[.]");
            idot += 3;
        }
        return address;
    }

};

int main()
{

    string arr[] = {"1.1.1.1", "255.100.50.0"};

    LT1108 lt;

    for (string& s : arr)
    {
        cout<<lt.lt1108a(s)<<endl;

        cout<<std::regex_replace(s, regex("[.]"), "[.]");
    }

    return 0;
}
