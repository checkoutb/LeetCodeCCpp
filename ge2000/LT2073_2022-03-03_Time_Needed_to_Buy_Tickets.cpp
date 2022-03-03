
#include "../header/myheader.h"

class LT2073
{
public:

// D D

//return IntStream.range(0, t.length).map(i -> Math.min(t[i], i > k ? t[k] - 1 : t[k])).sum();

//ans += min(A[k] - (i > k), A[i]);



//Runtime: 4 ms, faster than 62.18% of C++ online submissions for Time Needed to Buy Tickets.
//Memory Usage: 7.7 MB, less than 19.90% of C++ online submissions for Time Needed to Buy Tickets.
// + min([k], [i]) + 1 - 1.
    int lt2073a(vector<int>& tickets, int k)
    {
        int ans = 0;
        int t2 = tickets[k];
        for (int i = 0; i < tickets.size(); ++i)
        {
            ans += (i <= k ? min(t2, tickets[i]) : min(t2 - 1, tickets[i]));
        }
        return ans;
    }

};

int main()
{

    LT2073 lt;

//    myvi v = {2,3,2};
//    int t = 2;

    myvi v = {5,3,1,1};
    int t = 0;

    cout<<lt.lt2073a(v, t)<<endl;

    return 0;
}
