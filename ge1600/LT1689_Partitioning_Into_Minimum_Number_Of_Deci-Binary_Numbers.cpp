
#include "../header/myheader.h"

class LT1689
{
public:

// D D

// return *max_element(n.begin(), n.end()) - '0';



//Runtime: 48 ms, faster than 100.00% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
//Memory Usage: 13.9 MB, less than 25.00% of C++ online submissions for Partitioning Into Minimum Number Of Deci-Binary Numbers.
    int lt1689a(string n)
    {
        char mx = '0';
        for (char ch : n)
            mx = max(mx, ch);
        return mx - '0';
    }

};

int main()
{

    LT1689 lt;


    return 0;
}
