
#include "../header/myheader.h"

class LT1579
{
public:

    // D D

    // If not necessary to add, increment res.




//Runtime: 1387 ms, faster than 7.76 % of C++ online submissions for Remove Max Number of Edges to Keep Graph Fully Traversable.
//Memory Usage : 206 MB, less than 5.17 % of C++ online submissions for Remove Max Number of Edges to Keep Graph Fully Traversable.
    // 最小生成树。
    // 先用type 3 做 连通， 然后 分别用 type 1 ,type 2 做连通。 剩余的就是删除的。
    int lt1579a(int n, vector<vector<int>>& edges)
    {
        vector<vector<vector<int>>> vvi(4);
        //int mx = 1;
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi);
            //mx = max(mx, max(vi[1], vi[2]));
        }

        vector<int> uf(n + 1, -1);

        int cnt = 0;

        // type 3
        unordered_map<int, vector<int>> map2;

        for (vector<int>& vi : vvi[3])
        {
            //if (vi[0] < vi[1])
                map2[vi[1]].push_back(vi[2]);
            //else
                //map2[vi[2]].push_back(vi[1]);
        }
        for (auto& p : map2)
        {
#ifdef __test
            //cout << p.first << ":";
            //for (int a : p.second)
            //    cout << a << ", ";
            //cout << endl;
#endif
            int st = p.first;
            for (int en : p.second)
            {
                int ts = ufa(uf, st);
                int te = ufa(uf, en);
                if (ts != te)
                {
                    cnt++;
                    uf[ts] = te;
                }
            }
        }

#ifdef __test
        //cout << "type3 : " << cnt << endl;
#endif

        // type 2
        map2.clear();
        vector<int> uf2(begin(uf), end(uf));
        for (vector<int>& vi : vvi[2])
            map2[vi[1]].push_back(vi[2]);
        for (auto& p : map2)
        {
            int st = p.first;
            for (int en : p.second)
            {
                int ts = ufa(uf2, st);
                int te = ufa(uf2, en);
                if (ts != te)
                {
                    cnt++;
                    uf2[ts] = te;
                }
            }
        }
#ifdef __test
        //cout << "type2 : " << cnt << endl;
#endif
        // type 1
        map2.clear();
        for (vector<int>& vi : vvi[1])
            map2[vi[2]].push_back(vi[1]);
        for (auto& p : map2)
        {
#ifdef __test
            //cout << p.first << ":";
            //for (int a : p.second)
            //    cout << a << ", ";
            //cout << endl;
#endif
            int st = p.first;
            for (int en : p.second)
            {
                int ts = ufa(uf, st);
                int te = ufa(uf, en);
#ifdef __test
//                cout << st << " - " << en << ",,,, " << ts << ", " << te << endl;
#endif
                if (ts != te)
                {
                    cnt++;
                    uf[ts] = te;
                }
            }
        }
#ifdef __test
        cout << "type1 : " << cnt << endl;
        cout << &uf[0] << ", " << &uf2[0] << endl;
#endif
        int t2 = std::count(begin(uf), end(uf), -1);
        int t3 = std::count(begin(uf2), end(uf2), -1);

        if (t2 != 2 || t3 != 2)         // [0] && [not 0]
            return -1;

        return edges.size() - cnt;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }
};

int main()
{

    LT1579 lt;

    //myvvi vv = { {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4} };
    //int n = 4;

    //myvvi vv = { {3,1,2},{3,2,3},{1,1,4},{2,1,4} };
    //int n = 4;

    myvvi vv = { {3,2,3},{1,1,2},{2,3,4} };
    int n = 4;

    cout << lt.lt1579a(n, vv) << endl;

    return 0;
}
