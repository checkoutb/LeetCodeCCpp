
#include "../header/myheader.h"

class LT1786
{
public:




    // gg



// error, 不过估计能过也是tle，MOD在那里放着，说明至少要执行 MOD×2 次 dfsb2，肯定tle。  应该是dp， 到这个点的点相乘
    int lt1786b(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<pair<int, int>>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].emplace_back(make_pair(vi[1], vi[2]));
            map2[vi[1]].emplace_back(make_pair(vi[0], vi[2]));
        }
        vector<int> vi(n + 1, INT_MAX);
        dfsb1(vi, map2, n, 0, -1);
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        dfsb2(vi, map2, 1, vi[1], 0, -1);
        return ans;
    }
    int ans = 0;
    const int MOD = 1E9 + 7;
    void dfsb2(vector<int>& vi, unordered_map<int, vector<pair<int, int>>>& map2, int idx, int mnvi, int len, int parent)
    {
        if (idx == vi.size() - 1)
        {
//            ans = (ans + len) % MOD;
            ans = (ans + 1) % MOD;          /// ...
            return;
        }
        vector<pair<int, int>>& vp = map2[idx];
        for (pair<int, int>& p : vp)
        {
            if (vi[p.first] <= vi[idx] && p.first != parent)
            {
                dfsb2(vi, map2, p.first, vi[p.first], (len + p.second) % MOD, idx);
            }
        }
    }
    void dfsb1(vector<int>& vi, unordered_map<int, vector<pair<int, int>>>& map2, int idx, int len, int parent)
    {
        if (idx < 1)
            return;
        if (len >= vi[idx])         // can remove parent.
            return;
        vi[idx] = len;
//        vi[idx] = min(vi[idx], len);
        vector<pair<int, int>>& vp = map2[idx];
        for (pair<int, int>& p : vp)
        {
            if (p.first != parent)
            {
                dfsb1(vi, map2, p.first, len + p.second, idx);
            }
        }
    }


// error     distanceToLastNode
    int lt1786a(int n, vector<vector<int>>& edges)
    {
        unordered_map<int, vector<pair<int, int>>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(make_pair(vi[1], vi[2]));
            map2[vi[1]].push_back(make_pair(vi[0], vi[2]));
        }
        dfsa1(map2, INT_MAX, n, 0, 1);
        return ans;
    }
//    int ans = 0;
    void dfsa1(unordered_map<int, vector<pair<int, int>>>& map2, int lenLimit, int n, int sumLen, int now)
    {
        if (now == n)
        {
            ans += sumLen;
            return;
        }
        vector<pair<int, int>>& vp = map2[now];
        for (pair<int, int>& p : vp)
        {
            if (p.second < lenLimit)
            {
                dfsa1(map2, p.second, n, sumLen + p.second, p.first);
            }
        }
    }

};

int main()
{
//    int n = 5;
//    myvvi vv = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};

//    int n = 7;
//    myvvi vv = {{1,3,1},{4,1,2},{7,3,4},{2,5,3},{5,6,1},{6,7,2},{7,5,3},{2,6,4}};


    int n = 10;         // 1
    myvvi vv = {{9,10,8},{9,6,5},{1,5,9},{6,8,10},{1,8,1},{8,10,7},{10,7,9},
    {5,7,3},{4,2,9},{2,3,9},{3,10,4},{1,4,7},{7,6,1},{3,9,8},{9,1,6},{4,7,10},{9,4,9}};

    LT1786 lt;

    cout<<lt.lt1786b(n, vv);

    return 0;
}
