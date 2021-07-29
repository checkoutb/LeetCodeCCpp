
#include "../header/myheader.h"

class LT1936
{
public:

// D D


//        int s = 0;
//        int count = 0;
//        for (int & rung : rungs ){
//            count += ceil( 1.0*(rung -s)/dist ) -1;
//            s = rung;
//        }


//Compare the previous height pre and the current height a,
//we need (a - pre - 1) / dist extra rungs.
//        for (int a: A) {
//            res += (a - pre - 1) / dist;
//            pre = a;
//        }
// -1 就不需要 (%dist==0?1:0) .. 不过 可以 ==0, bool转int


//    int res = (rungs[0] - 1) / dist;
//    for (int i = 1; i < rungs.length; ++i)
//        res += (rungs[i] - rungs[i - 1] - 1) / dist;




//Runtime: 100 ms, faster than 78.91% of C++ online submissions for Add Minimum Number of Rungs.
//Memory Usage: 54.2 MB, less than 71.52% of C++ online submissions for Add Minimum Number of Rungs.
    int lt1936b(vector<int>& rungs, int dist)
    {
        int sz1 = rungs.size();
        int ans = 0;
        int reach = dist;
        for (int i = 0; i < sz1; ++i)
        {
            if (reach < rungs[i])
            {
                ans += (rungs[i] - reach + dist) / dist - ((rungs[i] - reach + dist) % dist == 0 ? 1 : 0);
                reach = rungs[i] + dist;
            }
            else
            {
                reach = rungs[i] + dist;            // every element will do this. and array is increasing
            }
        }
        return ans;
    }



// tle....   rungs[i] <= 10^9   dist=1
    int lt1936a(vector<int>& rungs, int dist)
    {
        int ans = 0;
        int reach = dist;
        for (int i = 0; i < rungs.size(); ++i)
        {
            if (rungs[i] > reach)
            {
                ans++;
                reach = reach + dist;
                i--;
            }
            else
            {
                reach = max(reach, rungs[i] + dist);        // reach = rungs[i] + dist ?
            }
        }
        return ans;
    }

};

int main()
{
    myvi v = {3};
    int a = 1;

    LT1936 lt;

    cout<<lt.lt1936b(v,a)<<endl;

    return 0;
}
