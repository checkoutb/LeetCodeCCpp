
#include "../../header/myheader.h"

class LT
{
public:

    // D D

//DP equation:
//    dp[i] = sum(dp[j] * dp[i / j])
//    res = sum(dp[i])
//    with i, j, i / j in the list L


//Runtime: 69 ms, faster than 88.92% of C++ online submissions for Binary Trees With Factors.
//Memory Usage: 8.9 MB, less than 94.46% of C++ online submissions for Binary Trees With Factors.
    int ltb(vector<int>& arr)
    {
        unordered_map<int, int> map2;
        const int MOD = 1e9 + 7;
        sort(begin(arr), end(arr));
        for (int i : arr)
        {
            map2[i] = 1;
        }
        int sz1 = arr.size();
        int mx = arr[sz1 - 1];
        for (int i = 0; i < sz1; ++i)
        {
            int cnti = map2[arr[i]];
            for (int j = 0; j < i; ++j)
            {
                #ifdef __test
                cout<<arr[i]<<" ... "<<arr[j]<<" ? "<<j<<" . "<<i<<endl;
                #endif // __test

                int cntj = map2[arr[j]];
                long long t2 = 1LL * arr[i] * arr[j];
                if (t2 > mx)
                    break;

                if (map2.find(t2) == map2.end())
                    continue;

                map2[t2] = (map2[t2] + 2LL * cnti * cntj) % MOD;
            }

            long long t2 = 1LL * arr[i] * arr[i];
            if (t2 > mx || map2.find(t2) == map2.end())
                continue;

            map2[t2] = (map2[t2] + 1LL * cnti * cnti) % MOD;
        }
        int ans = 0;
        for (auto& p : map2)
        {
            #ifdef __test
            cout<<p.first<<" - "<<p.second<<endl;
            #endif // __test
            ans = (ans + p.second) % MOD;
        }
        return ans;
    }


// <= 10^9 , 所以 root的值 不可能超过 10^9
    int lta(vector<int>& arr)
    {
        map<int, int> map2;
        const int MOD = 1e9 + 7;
        priority_queue<int, vector<int>, greater<int>> priq;

        int ans = 0;
        int mx = -1;
        for (int i : arr)
        {
            priq.push(i);
            mx = max(mx, i);
        }

        while (!priq.empty())
        {
            int t2 = priq.top();
            priq.pop();
            int cnt2 = map2[t2];

            for (pair<const int, int>& p : map2)
            {
                if (p.first == t2)
                    break;

            }



//            unordered_map<int, int> map3;
//
//            for (pair<int, int>& p : map2)
//            {
//                if (p.first == t2)
//                    break;
//                long long t3 = 1LL * p.first * t2;
//                if (t3 > mx)
//                    break;
//
//                map3[(int) t3] = (map3[(int) t3] + 1LL * p.second * cnt2 * 2) % MOD;
//            }
//
//            for (auto& p : map3)
//            {
//                map2[p.first] += p.second;
//                priq.push(p.first);
//            }
        }

        return ans;
    }

};

int main()
{

    LT lt;

    //myvi v = {2,4};
    //myvi v = {2,4,5,10};
    //myvi v = {18,3,6,2};        // 2 3 6 18, {6,2,3}, {6,3,2}, {18,6,3} {18,3,6} {18 {623,632} 3} {18 3 {623 632}}      // 12

    myvi v = {45,42,2,18,23,1170,12,41,40,9,47,24,33,28,10,32,29,17,46,11,759,37,6,26,21,49,31,14,19,8,13,7,27,22,3,36,34,38,39,30,43,15,4,16,35,25,20,44,5,48};

    cout<<lt.ltb(v)<<endl;


    return 0;
}
