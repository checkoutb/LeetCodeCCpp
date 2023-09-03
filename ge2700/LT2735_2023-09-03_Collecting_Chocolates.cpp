
#include "../header/myheader.h"

class LT2735
{
public:


// D D
// We binary-search for the number of shifts that produce the lowest cost.



//Runtime207 ms
//Beats
//79.48%
//Memory60.7 MB
//Beats
//69.14%
    // move 0, move 1 .... move sz1-1   1000
    long long minCost(vector<int>& nums, int x)
    {
        int sz1 = nums.size();
        long long ans = LONG_MAX;
        long long t2 = 0;
        vector<int> vi(begin(nums), end(nums));
        ans = std::accumulate(begin(vi), end(vi), 0LL);

        for (int i = 1; i < sz1; ++i)
        {
            t2 = 1LL * i * x;
            for (int j = 0; j < sz1; ++j)
            {
                vi[j] = min(vi[j], nums[(j - i + sz1) % sz1]);
                t2 += vi[j];
            }
            ans = min(ans, t2);

            #ifdef __test
            cout<<ans<<" - "<<t2<<endl;
            showVectorInt(vi);
            #endif // __test
        }
        return ans;
    }

};

int main()
{

    LT2735 lt;

    myvi v = {15,150,56,69,214,203};        // 298
    int x = 42;

    cout<<lt.minCost(v, x)<<endl;

    return 0;
}
