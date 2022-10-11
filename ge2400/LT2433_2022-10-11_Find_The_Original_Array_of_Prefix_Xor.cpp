
#include "../header/myheader.h"

class LT2433
{
public:






//Runtime: 253 ms, faster than 51.60 % of C++ online submissions for Find The Original Array of Prefix Xor.
//Memory Usage : 76.1 MB, less than 63.61 % of C++ online submissions for Find The Original Array of Prefix Xor.
    myvi lt2433a(myvi& pref)
    {

        for (int i = pref.size() - 1; i > 0; --i)
        {
            pref[i] ^= pref[i - 1];
        }
        return pref;



        // .......

        //for (int i = 1; i < pref.size(); ++i)
        //{
        //    pref[i] ^= pref[i - 1];
        //}
        //return pref;

        //int sz1 = pref.size();
        //vector<int> vi(sz1);
        //int t2 = 0;
        //for (int i = 0; i < sz1; ++i)
        //{
        //    t2 ^= pref[i];
        //}


    }

};

int main()
{

    LT2433 lt;


    return 0;
}
