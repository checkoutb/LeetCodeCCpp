
#include "../header/myheader.h"

class LT2136
{
public:


// D D

//        vector<pair<int,int>>v(n);
//        for(int i=0; i<n; i++)
//        {
//            v[i]={growTime[i],plantTime[i]};
//        }
//        sort(v.begin(),v.end());
//        reverse(v.begin(), v.end());


//        vector<int> id(n);
//        iota(id.begin(), id.end(), 0);


//    vector<pair<int, int>> v;
//    for (auto i = 0; i < plant.size(); ++i)
//        v.push_back({grow[i], plant[i]});
//    sort(begin(v), end(v));
//    int res = 0;
//    for (auto [g, p] : v)
//        res = max(res, g) + p;
//    return res;
// 先开花，再种。


//Runtime: 228 ms, faster than 97.34% of C++ online submissions for Earliest Possible Day of Full Bloom.
//Memory Usage: 170.4 MB, less than 14.95% of C++ online submissions for Earliest Possible Day of Full Bloom.
// 种 + 生长 最大的 先种？  bu, 生长 长的先种。
    int lt2136a(vector<int>& plantTime, vector<int>& growTime)
    {
        int sz1 = plantTime.size();
        map<int, vector<int>> map2;
        for (int i = 0; i < sz1; ++i)
        {
            map2[growTime[i]].push_back(i);
        }
        int ans = 0;
        int pld = 0;
        for (map<int, vector<int>>::reverse_iterator it = rbegin(map2); it != rend(map2); it++)
        {
            for (int i : it->second)
            {
                pld += plantTime[i];
                ans = max(ans, it->first + pld);
            }
        }
        return ans;

//        int sz1 = plantTime.size();
//        map<int, int> map2;
//        for (int i = 0; i < sz1; ++i)
//        {
//            map2[plantTime]
//        }
    }

};

int main()
{

    LT2136 lt;

//    myvi v = {1,4,3};
//    myvi v2 = {2,3,1};

//    myvi v = {1,2,3,2};
//    myvi v2 = {2,1,2,1};

    myvi v = {1};
    myvi v2 = {1};

    cout<<lt.lt2136a(v, v2)<<endl;

    return 0;
}
