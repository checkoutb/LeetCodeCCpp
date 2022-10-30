
#include "../header/myheader.h"

class LT2446
{
public:




//Runtime: 8 ms, faster than 22.41 % of C++ online submissions for Determine if Two Events Have Conflict.
//Memory Usage : 11.6 MB, less than 8.03 % of C++ online submissions for Determine if Two Events Have Conflict.
    bool lt2446a(vector<string>& event1, vector<string>& event2)
    {
        string& s1 = event1[0];
        string& e1 = event1[1];
        string& s2 = event2[0];
        string& e2 = event2[1];

        return s1 <= e2 && s2 <= e1;
    }

};

int main()
{

    LT2446 lt;


    return 0;
}
