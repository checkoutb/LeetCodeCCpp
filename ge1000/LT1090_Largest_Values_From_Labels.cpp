
#include "../header/myheader.h"

class LT1090
{
public:


// D D

//  multimap<int, int> s;
//  unordered_map<int, int> m;
//  for (auto i = 0; i < vs.size(); ++i) s.insert({vs[i], ls[i]});
//  for (auto it = rbegin(s); it != rend(s) && wanted > 0; ++it) {
//    if (++m[it->second] <= limit) {
//      res += it->first;
//      --wanted;
//    }
//  }
//  return res;

// multimap,, zhen mei yongguo.




//Runtime: 56 ms, faster than 93.71% of C++ online submissions for Largest Values From Labels.
//Memory Usage: 20.7 MB, less than 9.71% of C++ online submissions for Largest Values From Labels.
// 最多 num_wanted个数字，并且 数字对应的每个label 最多出现 use_limit 次。
// 组pair， sort by value， 如果label达到上限，就不选。
    int lt1090a(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < values.size(); i++)
        {
            vp.push_back({values[i], labels[i]});
        }
        sort(begin(vp), end(vp), [](pair<int, int>& p1, pair<int, int>& p2) { return p1.first > p2.first; });

        #ifdef __test
        for (pair<int, int>& p : vp)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        #endif // __test

        int ans = 0;
        int cnt = 0;
        unordered_map<int, int> map2;
        for (pair<int, int>& p : vp)
        {
            if (map2[p.second] < use_limit)
            {
                ++cnt;
                ans += p.first;
                map2[p.second]++;
            }
            if (cnt == num_wanted)
                break;
        }
        return ans;
    }

};

int main()
{

    vector<int> v1 = {9,8,8,7,6};
    vector<int> v2 = {0,0,0,1,1};
    int n = 3;
    int l = 2;

    LT1090 lt;

    cout<<lt.lt1090a(v1,v2,n,l)<<endl;

    return 0;
}
