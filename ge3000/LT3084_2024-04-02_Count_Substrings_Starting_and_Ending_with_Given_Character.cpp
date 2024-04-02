
#include "../header/myheader.h"

class LT3084
{
public:



// 7ms
// Beats94.05%of users with C++
// Memory
// 11.20MB
// Beats72.45%of users with C++

    long long countSubstrings(string s, char c)
    {
        long long cntc = 0LL;
        for (char ch : s)
            if (ch == c)
                ++cntc;

        return (1 + cntc) * (cntc) / 2;
    }

};

int main()
{

    LT3084 lt;


    return 0;
}
