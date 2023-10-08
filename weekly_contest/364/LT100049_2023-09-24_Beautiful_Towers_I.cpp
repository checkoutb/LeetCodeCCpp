
#include "../../header/myheader.h"

class LT100049
{
public:



// AC II
// AC I
    long long maximumSumOfHeights(vector<int>& maxHeights)
    {
        int sz1 = maxHeights.size();
        vector<long long> pfx(sz1, 0LL);
        vector<long long> sfx(sz1, 0LL);

        long long sum2 = 0;

        map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = maxHeights[i];
            sum2 += t2;
            map2[t2] += 1;
            while (map2.rbegin()->first > t2)
            {
                pair<int, int> p = *map2.rbegin();
                map2.erase(p.first);
                sum2 -= 1LL * (p.first - t2) * p.second;
                map2[t2] += p.second;
            }
            pfx[i] = sum2;
        }

        map2.clear();
        sum2 = 0LL;

        for (int i = sz1 - 1; i >= 0; --i)
        {
            int t2 = maxHeights[i];
            sum2 += t2;
            map2[t2] += 1;
            while (map2.rbegin()->first > t2)
            {
                pair<int, int> p = *map2.rbegin();
                map2.erase(p.first);
                sum2 -= 1LL * (p.first - t2) * p.second;
                map2[t2] += p.second;
            }
            sfx[i] = sum2;
        }

        #ifdef __test
        for (long long ll : pfx)
            cout<<ll<<", ";
        cout<<endl;
        for (long long ll : sfx)
            cout<<ll<<", ";
        cout<<endl;
        #endif // __test

        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
//            long long t2 = maxHeights[i] + (i == 0 ? 0 : pfx[i - 1]) + ((i == sz1 - 1) ? 0 : sfx[i + 1]);
            long long t2 = maxHeights[i] + pfx[i] + sfx[i] - maxHeights[i] * 2;
            ans = max(ans, t2);

            #ifdef __test
            cout<<ans<<endl;
            #endif // __test
        }
        return ans;


//        priority_queue<int> priq;
//
//        for (int i = 0; i < sz1; ++i)
//        {
//            int t2 = maxHeights[i];
//            sum2 += t2;
//            while (!priq.empty() && priq.top() > t2)
//            {
//
//            }
//        }

//        stack<int> stk;
//
//        for (int i = 0; i < sz1; ++i)
//        {
//            int t2 = maxHeights[i];
//            sum2 += t2;
//            while (!stk.empty() && stk.)
//        }
    }



// error
    long long maximumSumOfHeights___(vector<int>& maxHeights)
    {
        int sz1 = maxHeights.size();
        vector<long long> pfx(sz1, 0LL);        // down
        vector<long long> sfx(sz1, 0LL);        // up
        pfx[0] = maxHeights[0];
        int mx = pfx[0];
        for (int i = 1; i < sz1; ++i)
        {
            mx = min(mx, maxHeights[i]);
            pfx[i] = pfx[i - 1] + mx;
        }

        sfx[sz1 - 1] = maxHeights[sz1 - 1];
        mx = sfx[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            mx = min(mx, maxHeights[i]);
            sfx[i] = sfx[i + 1] + mx;
        }

        #ifdef __test
        for (long long ll : pfx)
        {
            cout<<ll<<", ";
        }
        cout<<endl;
        for (long long ll : sfx)
        {
            cout<<ll<<", ";
        }
        cout<<endl;
        #endif // __test

        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            ans = max(ans, maxHeights[i] + (i == 0 ? 0 : (sfx[0] - sfx[i])) + ((i == sz1 - 1) ? 0 : (pfx[sz1 - 1] - pfx[i])));
            cout<<ans<<endl;
        }
        return ans;
    }

};

int main()
{

    LT100049 lt;

//    myvi v = {5,3,4,1,1};
    myvi v = {6,5,3,9,2,7};


    cout<<lt.maximumSumOfHeights(v)<<endl;

    return 0;
}
