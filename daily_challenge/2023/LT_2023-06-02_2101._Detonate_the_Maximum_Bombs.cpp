
#include "../../header/myheader.h"

class LT
{
public:



// Runtime179 ms
// Beats
// 49.37%
// Memory14.4 MB
// Beats
// 87.92%
    // after hint++
    int ltc(vector<vector<int>>& bombs)
    {
        int sz1 = bombs.size();
        vector<vector<int>> vvi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            int a = bombs[i][0];
            int b = bombs[i][1];
            long long rr = 1LL * bombs[i][2] * bombs[i][2];
            for (int j = 0; j < sz1; ++j)
            {
                if (i == j)
                    continue;
                if (rr >= 1LL * (a - bombs[j][0]) * (a - bombs[j][0]) + 1LL * (b - bombs[j][1]) * (b - bombs[j][1]))
                {
                    vvi[i].push_back(j);
                }
            }
        }
        int ans = 1;
        vector<bool> vb(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            std::fill(begin(vb), end(vb), false);
            ans = max(ans, dfsc1(vvi, i, vb));
        }
        return ans;
    }

    int dfsc1(vector<vector<int>>& vvi, int idx, vector<bool>& vb)
    {
        if (vb[idx])
            return 0;
        vb[idx] = true;
        int ans = 1;
        for (int nxt : vvi[idx])
        {
            ans += dfsc1(vvi, nxt, vb);
        }
        return ans;
    }


    // 还有 x^2 + y^2 <= r^2 , no sqrt

    // g... hint: 预先计算出图，单向连接，然后对每个点dfs。

    // 
    int ltb(vector<vector<int>>& bombs)
    {
        return -1;
    }

    int dfsa1(vector<vector<int>>& vvi, int idx, vector<bool>& vst)
    {
        vst[idx] = true;
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (vst[i])
                continue;
            // if (std::sqrt(1LL * () * () + 1LL * () * ()) <= vvi[idx][2])
            {

            }
        }
        return -1;
    }

    // error
    // a -> b , c -> b ,   a !-> c, c !-> a
    //
    // uf ?
    int maximumDetonation(vector<vector<int>>& bombs)
    {
        int sz1 = bombs.size();
        vector<int> uf(sz1, -1);
        std::sort(begin(bombs), end(bombs), [](vector<int>& v1, vector<int>& v2){
            return v1[2] > v2[2];
        });
        for (int i = 0; i < sz1; ++i)
        {
            int a = bombs[i][0];
            int b = bombs[i][1];
            int t2 = bombs[i][2];
            int t3,t4;
            t3 = ufa(uf, i);
            for (int j = i + 1; j < sz1; ++j)
            {
                t4 = ufa(uf, j);
                if (t3 == t4)
                    continue;
                if (std::sqrt(1LL * (a - bombs[j][0]) * (a - bombs[j][0]) + 1LL * (b - bombs[j][1]) * (b - bombs[j][1])) <= t2)
                {
                    #ifdef __test
                    cout<<a<<"+"<<b<<" <-> "<<bombs[j][0]<<"+"<<bombs[j][1]<<"    "<<t2<<" > "<<std::sqrt(1LL * (a - bombs[j][0]) * (a - bombs[j][0]) + 1LL * (b - bombs[j][1]) * (b - bombs[j][1]))<<endl;
                    #endif

                    uf[t4] = t3;
                }
            }
        }
        unordered_map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            ++map2[ufa(uf, i)];
        }
        int ans = 0;
        for (auto& p : map2)
        {
            if (p.second > ans)
                ans = p.second;
        }
        return ans;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT lt;

    myvvi vv = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};
//    myvvi vv = {{1,1,100000},{100000,100000,1}};

    // myvvi vv = {{855,82,158},{17,719,430},{90,756,164},
    // {376,17,340},{691,636,152},{565,776,5},{464,154,271},
    // {53,361,162},{278,609,82},{202,927,219},{542,865,377},
    // {330,402,270},{720,199,10},{986,697,443},{471,296,69},
    // {393,81,404},{127,405,177}};


    cout<<lt.ltc(vv)<<endl;

    return 0;
}
