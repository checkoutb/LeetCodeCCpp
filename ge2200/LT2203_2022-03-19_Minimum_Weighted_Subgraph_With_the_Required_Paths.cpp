
#include "../header/myheader.h"

class LT2203
{
public:


// D

//     pq.push({0, st});
// 使用堆优化的 Dijkstra
// vector<vector<int>> 代替 unordered_map 。




// tle...
// 从 src1 到 各个点的最小距离， 各个点到 dest的最小距离。  从src2 到各个点的 最小。
    long long lt2203a(int n, vector<vector<int>>& edges, int src1, int src2, int dest)
    {
        long long ans = LONG_MAX;
        unordered_map<int, unordered_map<int, int>> map2;       // from, to, weight
        unordered_map<int, unordered_map<int, int>> map3;       // to, from, weight
        for (vector<int>& vi : edges)
        {
            if (map2.find(vi[0]) != map2.end() && map2[vi[0]].find(vi[1]) != map2[vi[0]].end())
            {
                map2[vi[0]][vi[1]] = min(vi[2], map2[vi[0]][vi[1]]);
                map3[vi[1]][vi[0]] = map2[vi[0]][vi[1]];
            }
            else
            {
                map2[vi[0]][vi[1]] = vi[2];
                map3[vi[1]][vi[0]] = vi[2];
            }
        }
        vector<long long> vi1(n, LONG_MAX);
        vector<long long> vi2(n, LONG_MAX);
        vector<long long> vi3(n, LONG_MAX);
        vi1[src1] = 0;
        vi2[src2] = 0;
        vi3[dest] = 0;
        cala1(map2, vi1, src1);
        cala1(map2, vi2, src2);
        cala1(map3, vi3, dest);
        #ifdef __test
        for (long long l : vi1)
        {
            cout<<l<<", ";
        }
        cout<<endl;
        for (long long l : vi2)
        {
            cout<<l<<", ";
        }
        cout<<endl;
        for (long long l : vi3)
        {
            cout<<l<<", ";
        }
        cout<<endl;
        #endif // __test
        for (int i = 0; i < n; i++)
        {
            if (vi1[i] != LONG_MAX && vi2[i] != LONG_MAX && vi3[i] != LONG_MAX)
                ans = min(ans, vi1[i] + vi2[i] + vi3[i]);
        }
        return ans == LONG_MAX ? -1 : ans;
    }

    // Dijkstra
    void cala1(unordered_map<int, unordered_map<int, int>>& map2, vector<long long>& vi, int st)
    {
        vector<bool> vst(vi.size(), false);
//        vst[st] = true;
        bool chg = true;
        while (chg)
        {
            vst[st] = true;
            chg = false;
            int mni = -1;
            long long mn = LONG_MAX;       // == chg...
            for (auto& p : map2[st])
            {
                int en = p.first;
                int we = p.second;
                if (vi[st] + we < vi[en])
                {
//                    chg = true;
                    vi[en] = vi[st] + we;
                }
            }
//            if (chg)
//            {
                for (int i = 0; i < vi.size(); ++i)
                {
                    if (vst[i] == false && mn > vi[i])
                    {
                        chg = true;
                        mn = vi[i];
                        mni = i;
                    }
                }
//            }
            st = mni;
        }
    }

};

int main()
{

    LT2203 lt;

    myvvi vv = {{0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1}};
    myvi v = {0,1,5,6};

//    myvvi vv = {{0,1,1},{2,1,1}};
//    myvi v = {0,1,2,3};

    cout<<lt.lt2203a(v[3], vv, v[0], v[1], v[2]);

    return 0;
}
