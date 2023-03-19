
#include "../header/myheader.h"

class LT1976
{
public:

    // D D

    // Dijkstra





    //Runtime102 ms
    //    Beats
    //    29.93 %
    //    Memory33.5 MB
    //    Beats
    //    46.45 %
    // 
    // tle      用了 最大堆 在那里跑。。
    int lt1976a(int n, vector<vector<int>>& roads)
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, std::greater<>> priq;          // <time, node>
        
        vector<vector<pair<int, int>>> vvi(n);      // <node, <node, time>>
        for (vector<int>& vi : roads)
        {
            vvi[vi[0]].push_back(std::make_pair(vi[1], vi[2]));
            vvi[vi[1]].push_back(std::make_pair(vi[0], vi[2]));
        }

        vector<long long> vll(n, 1LL << 50);
        //vll[0] = 0LL;

        priq.push(std::make_pair(0LL, 0));
        

        while (!priq.empty())
        {
            auto [tm, node] = priq.top();           // auto& 的话， 后续pop掉后，指向的就未知了。
            priq.pop();
            if (tm >= vll[node])
                continue;
            vll[node] = tm;

            if (node == n - 1)
                continue;

            for (pair<int, int>& p : vvi[node])
            {
                long long t2 = tm + p.second;
                priq.push(make_pair(t2, p.first));
            }
        }

        vector<int> vi(n, -1);

        return dfsa1(vvi, vll, n - 1, vi);
    }
    
    const int MOD = 1e9 + 7;

    int dfsa1(vector<vector<pair<int, int>>>& vvp, vector<long long>& vll, int node, vector<int>& vi)
    {
        if (node == 0)
            return 1;

        if (vi[node] != -1)
            return vi[node];

        long long t2 = vll[node];
        int ans = 0;

        for (pair<int, int>& p : vvp[node])
        {
            if (vll[p.first] + p.second == t2)
            {
                ans = (ans + dfsa1(vvp, vll, p.first, vi)) % MOD;
            }
        }

        return vi[node] = ans;
    }

};

int main()
{

    LT1976 lt;


    //int n = 2;
    //myvvi vv = { {1,0,11} };

    int n = 7;
    myvvi vv = { {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2} };

    cout << lt.lt1976a(n, vv) << endl;

    return 0;
}
