
#include "../header/myheader.h"

class LT0908
{
public:

// D
//max(0, mx - mn - 2 * K);


//Runtime: 40 ms, faster than 57.30% of C++ online submissions for Smallest Range I.
//Memory Usage: 15.5 MB, less than 83.22% of C++ online submissions for Smallest Range I.
    int lt0908a(vector<int>& A, int K)
    {
        int mx = *std::max_element(A.begin(), A.end());
        int mn = *std::min_element(A.begin(), A.end());
        return (mx - K < mn + K) ? 0 : (mx - mn - K - K);
    }

};

int main()
{

    LT0908 lt;


    return 0;
}
