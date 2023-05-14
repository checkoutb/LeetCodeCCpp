
#include "../../header/myheader.h"

class LT6431
{
public:



    // AC

    // ^
    // i = i ^ (i+1)
    // i = n-1 ^ 0
    bool doesValidArrayExist(vector<int>& derived)
    {
        int sz1 = derived.size();
        int t2 = 1;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = derived[i] ^ t2;
        }
        if (t2 == 1)
            return true;

        t2 = 0;
        for (int i = 0; i < sz1; ++i)
            t2 = derived[i] ^ t2;

        if (t2 == 0)
            return true;

        return false;
    }


};

int main()
{

    LT6431 lt;


    return 0;
}
