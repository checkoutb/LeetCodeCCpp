
#include "../../header/myheader.h"

class LT6432
{
public:





// AC
// 。。。
// 1298 / 19455	Ouha 	17	0:46:50	0:06:48 	0:13:01 	0:22:17 	0:46:50


struct DSU {
    std::vector<int> f, siz, sz;
    DSU(int n) : f(n), siz(n, 0), sz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        siz[x] += siz[y];
        sz[x] += sz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[leader(x)]; }
};

    //
    int countCompleteComponents(int n, vector<vector<int>>& edges)
    {

        DSU uf(n);
        for (vector<int>& vi : edges)
        {
            ++uf.siz[vi[0]];
        }
        for (vector<int>& vi : edges)
        {
            //++uf.siz[vi[0]];
            uf.merge(vi[0], vi[1]);
        }
        int ans = 0;
        int a, b;
        for (int i = 0; i < n; ++i)
        {
            if (uf.leader(i) == i)
            {
                a = uf.siz[i];      // edge
                b = uf.sz[i];       // node
                if (a == (b - 1) * b / 2)
                    ++ans;
            }
        }
        return ans;

//        vector<int> vi(n);      // node
//        vector<int> v2(n);      // edge
//
//        for (int i = 0; i < n; ++i)
//        {
//            int t2 = uf.leader(i);
//            vi[t2] = uf.sz(t2);
//            v2[t2] = uf.sz1(t2);
//        }

//        for (int i = 0; i < n; ++i)
//        {
//            int t2 = uf.leader(i);
//            ++vi[t2];
//            if (v2[t2] == 0)
//                v2[t2] = uf.size(t2);
//        }
//
//        #ifdef __test
//        showVectorInt(uf.f);
//        showVectorInt(uf.siz);
//        #endif // __test
//
//        int ans = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            if (vi[i] != 0 && vi[i] == v2[i])
//            {
//                ++ans;
//            }
//        }
//
//        return ans;

//        vector<int> vi(n, -1);
//        int a, b;
//        for (vector<int>& e : edges)
//        {
//            a = ufa(vi, e[0]);
//            b = ufa(vi, e[1]);
//            if (a != b)
//            {
//
//            }
//        }
    }

    int ufa(vector<int>& vi, int idx)
    {
        return vi[idx] == -1 ? idx : (vi[idx] = ufa(vi, vi[idx]));
    }

};

int main()
{

    LT6432 lt;

    int n = 6;
    //myvvi vv = {{1,0},{2,0},{1,2},{3,4},{3,5}};
    myvvi vv = {{1,0},{2,0},{1,2},{3,4}};

    cout<<lt.countCompleteComponents(n, vv)<<endl;

    return 0;
}
