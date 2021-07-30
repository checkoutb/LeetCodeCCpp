
#include "../header/myheader.h"

class LT1943
{
public:

// D D

//    long long mix[100002] = {}, sum = 0, last_i = 0;
//    bool ends[100002] = {};
//    vector<vector<long long>> res;
//    for (auto &s : segments) {
//        mix[s[0]] += s[2];
//        mix[s[1]] -= s[2];
//        ends[s[0]] = ends[s[1]] = true;
//    }
//    for (int i = 1; i < 100002; ++i) {
//        if (ends[i] && sum)
//            res.push_back({last_i, i, sum});
//        last_i = ends[i] ? i : last_i;
//        sum += mix[i];
//    }
//    return res;
// mix从这个点(s[0])开始，颜色加上s[2],  从s[1]开始，颜色减去
// ends[s[0]] 这个点有颜色消失/增加，所以可以作为 一段的结束。


//        map<int, long long> d;
//        for (auto& a : A) {
//            d[a[0]] += a[2];
//            d[a[1]] -= a[2];
//        }
//        vector<vector<long long> > res;
//        int i = 0;
//        for (auto& it : d) {
//            if (d[i] > 0)
//                res.push_back({i, it.first, d[i]});
//            d[it.first] += d[i];
//            i = it.first;
//        }




// 不知道内存怎么算的， 100mb。。。100×1000×1000/8 = 12500000
//Runtime: 472 ms, faster than 53.05% of C++ online submissions for Describe the Painting.
//Memory Usage: 106.6 MB, less than 60.31% of C++ online submissions for Describe the Painting.
// 和上一道差不多， 进入，离开。
    vector<vector<long long>> lt1943a(vector<vector<int>>& segments)
    {
        int sz1 = segments.size();
        vector<vector<long long>> vvl;
//        vector<pair<int, int>> vpi(sz1), vpo(sz1);
        vector<vector<int>> vpi(sz1, vector<int>(2)), vpo(sz1, vector<int>(2));
        for (int i = 0; i < sz1; ++i)
        {
            vpi[i][0] = segments[i][0];
            vpi[i][1] = segments[i][2];
            vpo[i][0] = segments[i][1];
            vpo[i][1] = segments[i][2];
//            vpi[i].first = segments[i][0];
//            vpi[i].second = segments[i][2];
//            vpo[i].first = segments[i][1];
//            vpo[i].second = segments[i][2];
        }
        std::sort(begin(vpi), end(vpi));
        std::sort(begin(vpo), end(vpo));
        int st = vpi[0][0];
        long long col = vpi[0][1];
        int oidx = 0;
        for (int i = 1; i < sz1; ++i)
        {
            // ... 直接 st 到 en-1， 每个格子+color。。。
            // Each color is distinct.
            while (oidx < sz1 && vpo[oidx][0] <= vpi[i][0])
            {
                if (st != vpo[oidx][0] && col != 0)
                    vvl.push_back({st, vpo[oidx][0], col});
                col -= vpo[oidx][1];
                st = vpo[oidx][0];
                oidx++;
            }
            if (st != vpi[i][0])        // <
            {
                if (col != 0)
                    vvl.push_back({st, vpi[i][0], col});
                st = vpi[i][0];
            }
            col += vpi[i][1];
        }
        while (oidx < sz1)
        {
            if (st != vpo[oidx][0] && col != 0)
                vvl.push_back({st, vpo[oidx][0], col});
            col -= vpo[oidx][1];
            st = vpo[oidx][0];
            oidx++;
        }
        return vvl;
    }

};

int main()
{
//    myvvi vv = {{1,4,5},{4,7,7},{1,7,9}};
//    myvvi vv = {{1,7,9},{6,8,15},{8,10,7}};
//    myvvi vv = {{1,4,5},{1,4,7},{4,7,1},{4,7,11}};

// col == 0...
    myvvi vv = {{4,16,12},{9,10,15},{18,19,13},{3,13,20},{12,16,3},{2,10,10},{3,11,4},{13,16,6}};

    LT1943 lt;

    vector<vector<long long>> vv2 = lt.lt1943a(vv);

    for (vector<long long>& v : vv2)
    {
        for (long i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
