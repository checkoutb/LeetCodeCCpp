
#include "../header/myheader.h"

class LT2767
{
public:

// D D

//To check if cur value is pow of 5,
//we can check if 15625 % cur == 0,
//where 15625 is the biggest pow of 5 with 15 bits.


//Runtime0 ms
//Beats
//100%
//Memory6.4 MB
//Beats
//37.19%
    // 5^0 = 1
    //   1 = 101
    // 2 25 = 11001   16+8+1
    // 125 = 128-3   127-2   11..1101
    int minimumBeautifulSubstrings(string s)
    {
        int sz1 = s.size();
        if (s[0] == '0' || s[sz1 - 1] == '0')
            return -1;

        vector<int> vi(sz1, INT_MAX);        // dp
        int t2 = 0;

        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == '0')
                continue;
            t2 = 1;
            vi[i] = i == 0 ? 1 : (vi[i - 1] == INT_MAX ? INT_MAX : vi[i - 1] + 1);
            for (int j = i - 1; j >= 0; --j)
            {
                t2 = t2 + ((s[j] == '1') ? (1 << (i - j)) : 0);
//                cout<<t2<<endl;
                if (s[j] == '1' && is5(t2))
                {
                    vi[i] = min(vi[i], j == 0 ? 1 : (vi[j - 1] == INT_MAX ? INT_MAX : vi[j - 1] + 1));
                }
            }
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return vi[sz1 - 1] == INT_MAX ? -1 : vi[sz1 - 1];
    }

    bool is5(int n)
    {
        while (n % 5 == 0)
        {
            n /= 5;
        }
        return n == 1;
    }

};

int main()
{

    LT2767 lt;

    string s = "1011";

    cout<<lt.minimumBeautifulSubstrings(s)<<endl;

    return 0;
}
