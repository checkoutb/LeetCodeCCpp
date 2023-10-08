
#include "../header/myheader.h"

class LT2857
{
public:

// D D

//        unordered_map<int, unordered_map<int, int>> count;
//        int res = 0;
//        for (auto& c : coordinates) {
//            for (int x = 0; x <= k; x++)
//                if (count[c[0] ^ x].count(c[1] ^ (k - x)))
//                    res += count[c[0] ^ x][c[1] ^ (k - x)];
//            count[c[0]][c[1]]++;
//        }
//        return res;



//Runtime630 ms
//Beats
//68.91%
//Memory137.4 MB
//Beats
//66.2%

    // k <= 100 < 2^7
    // x1 ^ x2 = 0..k    y^y = k - x^x
    // 0..100  for (i .. 0..50000)
    int countPairs(vector<vector<int>>& coordinates, int k)
    {
        int sz1 = coordinates.size();
        sort(begin(coordinates), end(coordinates));
        int ans = 0;
        map<int, map<int, int>> map2;
        set<pair<int, int>> set2;
        for (vector<int>& vi : coordinates)
        {
            ++map2[vi[0]][vi[1]];
            set2.insert(std::make_pair(vi[0], vi[1]));
        }

        for (int xorx = 0; xorx <= k; ++xorx)
        {
            int xory = k - xorx;
            for (auto& p : set2)
            {
                int t2 = xorx ^ p.first;
                if (t2 < p.first)
                    continue;
                if (map2.find(t2) == map2.end())
                    continue;

                int t3 = xory ^ p.second;
                if (t2 == p.first && t3 < p.second)
                    continue;
                if (t2 == p.first && t3 == p.second)
                {
                    int t5 = map2[t2][t3];
                    ans += 1LL * (t5 - 1) * t5 / 2;
                    continue;
                }
                if (map2[t2].find(t3) == map2[t2].end())
                    continue;

                ans += map2[t2][t3] * map2[p.first][p.second];
            }
        }
        return ans;
    }


};

int main()
{

    LT2857 lt;

    myvvi vv = {{1,3},{1,3},{1,3},{1,3},{1,3}};
    int k = 0;

    cout<<lt.countPairs(vv, k)<<endl;

    return 0;
}
