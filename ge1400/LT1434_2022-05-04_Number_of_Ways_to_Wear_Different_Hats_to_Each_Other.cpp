
#include "../header/myheader.h"

class LT1434
{
public:




// hint: dp(peopleMask, idHat) number of ways to wear different hats given a bitmask (people visited) and used hats from 1 to idHat-1.



// tle...
// n <= 10
// long 1<<40 ... bitmask
// 但是感觉 膨胀起来真的快。毕竟 40^10 ~= 10^16   try..
    int lt1434a(vector<vector<int>>& hats)
    {
        const int MOD = 1e9 + 7;
        unordered_map<long, int> map2;
        map2[0] = 1;
        for (vector<int>& vi : hats)
        {
            unordered_map<long, int> map3;

            for (int hat : vi)
            {
                for (auto& p : map2)
                {
                    int t2 = p.first | (1L << hat);
                    if (t2 != p.first)
                    {
                        map3[t2] = (map3[t2] + p.second) % MOD;
                    }
                }
            }
            std::swap(map2, map3);
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans = (ans + p.second) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT1434 lt;

//    myvvi vv{{3,4},{4,5},{5}};
//    myvvi vv{{3,5,1},{3,5}};
    myvvi vv{{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};

    cout<<lt.lt1434a(vv)<<endl;


    return 0;
}
