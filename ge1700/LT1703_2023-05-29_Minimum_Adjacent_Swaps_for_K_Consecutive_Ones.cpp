
#include "../header/myheader.h"

class LT1703
{
public:

// D D


// sliding window




// Runtime184 ms
// Beats
// 13.97%
// Memory124 MB
// Beats
// 56.42%
    // move to mid of 111
    int minMoves(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        long long lft = k / 2;
        long long rht = k - lft - 1;
        int idx = -1;
        int cnt = 0;
        long long sum2 = 0LL;

        if (k == 1)
            return 0;

        vector<int> v2;
        for (int i = 0; i < sz1; ++i)
            if (nums[i] == 1)
                v2.push_back(i);
        
        vector<long long> vi(v2.size(), INT_MAX);
        long long t2 = 1LL * (0 + lft - 1) * (lft) / 2;
        long long t3 = 1LL * (0 + rht - 1) * (rht) / 2;
        for (long long i = 1; i < v2.size(); ++i)
        {
            if (i < lft)
            {
                sum2 += i * (v2[i] - v2[i - 1] - 1) + (i - 1);
            }
            else
            {
                sum2 += lft * (v2[i] - v2[i - 1] - 1) + lft - 1;
                vi[i] = sum2 - t2;
                sum2 -= v2[i] - v2[i - lft] - 1;
            }
        }

        int sz2 = v2.size();
        long long ans = INT_MAX;
        sum2 = 0;
        if (rht == 0)
            ans = vi[sz2 - 1];

        #ifdef __test
        //showVectorInt(vi);
        showVectorInt(v2);
        cout<<lft<<", "<<rht<<", "<<t2 << " - " << t3 <<endl;
        #endif

        for (long long i = v2.size() - 2; i >= 0; --i)
        {
            if (rht == 0)
            {
                ans = min(ans, vi[i]);
                continue;
            }
            if (i >= sz2 - rht)
            {
                sum2 += (sz2 - 1 - i) * (v2[i + 1] - v2[i] - 1) + (sz2 - i - 2);
                #ifdef __test
                cout<<" -- 11 "<<sum2<<endl;
                #endif
            }
            else
            {
                sum2 += rht * (v2[i + 1] - v2[i] - 1) + rht - 1;
            #ifdef __test
            cout<<" --  "<<sum2<<endl;
            #endif
                ans = min(ans, sum2 + vi[i] - t3);
                sum2 -= v2[i + rht] - v2[i] - 1;
            }
        }

        return ans;

        // for (int i = 0; i < sz1; ++i)
        // {
        //     if (nums[i] == 1)
        //     {
        //         if (idx == -1)
        //             idx = i;
        //     }
        // }
    }

};

int main()
{

    LT1703 lt;

    // myvi v = {1,0,0,1,0,1};
    // int k = 2;

    // myvi v = {1,0,0,0,0,0,1,1};
    // int k = 3;

    // myvi v = {1,1,0,1};
    // int k = 2;

    myvi v = {1,0,0,1,0,1,1,1,0,1,1};       // 8
    int k = 7;

    cout<<lt.minMoves(v, k);

    return 0;
}
