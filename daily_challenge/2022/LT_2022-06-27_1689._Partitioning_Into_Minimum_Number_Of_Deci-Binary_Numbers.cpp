
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 47 ms, faster than 43.36 % of C++ online submissions for Partitioning Into Minimum Number Of Deci - Binary Numbers.
//Memory Usage : 13.6 MB, less than 17.75 % of C++ online submissions for Partitioning Into Minimum Number Of Deci - Binary Numbers.
    // max({n[i]})
    int lta(string n)
    {
        return *max_element(begin(n), end(n)) - '0';
    }

};

int main()
{

    LT lt;

    string s = "1234313";

    cout << lt.lta(s) << endl;

    return 0;
}
