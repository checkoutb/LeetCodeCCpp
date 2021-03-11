
#include "../header/myheader.h"

class LT1732
{
public:

// D D

//    def largestAltitude(self, A):
//        return max(0, max(accumulate(A)))




//Runtime: 4 ms, faster than 58.92% of C++ online submissions for Find the Highest Altitude.
//Memory Usage: 8 MB, less than 19.31% of C++ online submissions for Find the Highest Altitude.
    int lt1732a(vector<int>& gain)
    {
        int ans = 0;
        int t2 = 0;
        for (int i = 0; i < gain.size(); ++i)
        {
            ans = max(ans, (t2 = (t2 + gain[i])));
        }
        return ans;
    }

};

int main()
{

    LT1732 lt;


    return 0;
}
