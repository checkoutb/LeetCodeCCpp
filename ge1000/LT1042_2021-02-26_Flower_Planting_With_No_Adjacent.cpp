
#include "../header/myheader.h"

class LT1042
{
public:

// D D

//  vector<int> res(N);
//  vector<vector<int>> g(N);
//  for (auto p : paths) {
//    g[p[0] - 1].push_back(p[1] - 1);
//    g[p[1] - 1].push_back(p[0] - 1);
//  }
//  for (auto i = 0; i < N; ++i) {
//    bool used[5] = {};
//    for (auto j : g[i]) used[res[j]] = true;
//    for (auto fl = 1; fl <= 4; ++fl) {
//      if (!used[fl]) res[i] = fl;
//    }
//  }



//Runtime: 120 ms, faster than 88.96% of C++ online submissions for Flower Planting With No Adjacent.
//Memory Usage: 43.8 MB, less than 67.19% of C++ online submissions for Flower Planting With No Adjacent.
    // 这种是不是 dfs一遍 必然可以得到结果， 会不会有 由于 旁边的旁边的 花 导致自己有问题的？ dfs应该可以必然得到结果。
    vector<int> lt1042a(int n, vector<vector<int>>& paths)
    {
        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : paths)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }
        vector<int> ans(n, 0);
        int flw = 0;
        for (int i = 0; i < n; i++)
        {
            int t2 = i + 1;
            flw = 0;
            if (map2.find(t2) != map2.end())
            {
                vector<int>& vi = map2[t2];
                for (int g : vi)
                {
                    if (g < t2)
                    {
                        flw |= (1 << ans[g - 1]);           // 1-n,  [0,n) 的错位。。。
                    }
                }
            }
            #ifdef __test
            cout<<t2<<", "<<flw<<endl;
            #endif // __test
            for (int j = 1; j <= 4; j++)
            {
                if ((flw & (1 << j)) == 0)         // & 的优先级 真低。。。
                {
                    ans[i] = j;
                    break;
                }
            }
            #ifdef __test
//            showVectorInt(ans);
            #endif // __test
        }
        return ans;
    }

};

int main()
{

//    int n = 3;
//    myvvi vv = {{1,2},{2,3},{3,1}};

//    int n = 4;
//    myvvi vv = {{1,2},{3,4}};

    int n = 4;
    myvvi vv = {{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};

    LT1042 lt;

    myvi v = lt.lt1042a(n, vv);

    showVectorInt(v);

    return 0;
}
