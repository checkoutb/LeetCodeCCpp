
#include "../header/myheader.h"

class LT0787
{

    int cheapest = INT_MAX;
public:



// D D
// Dijkstra

// bellman ford
//        vector<int> c(n, 1e8);
//        c[src] = 0;
//
//        for(int z=0; z<=k; z++){
//            vector<int> C(c);
//            for(auto e: a)
//                C[e[1]] = min(C[e[1]], c[e[0]] + e[2]);
//            c = C;
//        }
//        return c[sink] == 1e8 ? -1 : c[sink];



//Runtime: 28 ms, faster than 68.66% of C++ online submissions for Cheapest Flights Within K Stops.
//Memory Usage: 11.3 MB, less than 100.00% of C++ online submissions for Cheapest Flights Within K Stops.
    int lt0787b(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        vector<int> arr2(n, INT_MAX);

        for (vector<int> v : flights)
        {
            arr[v[0]][v[1]] = v[2];
        }

        queue<int> que2;
        que2.push(src);
        que2.push(-1);
        arr2[src] = 0;
        vector<int> vt2(n, INT_MAX);
        while (!que2.empty())
        {
            int t2 = que2.front();
            que2.pop();
            if (t2 == -1)
            {
                for (int i = 0; i < n; i++)
                {
                    arr2[i] = vt2[i];               // .. 否则 -1....-1之间的 会相互影响。
                }
                if (--K < 0)
                    break;
                if (!que2.empty())
                {
                    que2.push(-1);
                }
                continue;
            }

            for (int i = 0; i < n; i++)
            {
                if (arr[t2][i] > 0)
                {
                    if (arr2[i] > arr2[t2] + arr[t2][i] && vt2[i] > arr2[t2] + arr[t2][i])
                    {
                        vt2[i] = arr2[t2] + arr[t2][i];
                        que2.push(i);
                    }
                }
            }
        }
        return arr2[dst] == INT_MAX ? -1 : arr2[dst];
    }



// tle
    int lt0787a(int n, vector<vector<int>>& flights, int src, int dst, int K)
    {
        vector<int> pass(n, 0);
        pass[src] = 1;
        for (vector<int> v : flights)
        {
            if (v[0] == src)
            {
                dfsa1(n, flights, v[1], dst, K, v[2], pass);
            }
        }
        return cheapest == INT_MAX ? -1 : cheapest;
    }

    void dfsa1(int n, vector<vector<int>>& vv, int now, int dst, int k, int spend, vector<int>& pass)
    {
        if (k < 0)
        {
            return;
        }
        if (now == dst)
            cheapest = std::min(cheapest, spend);
        pass[now] = 1;
        for (vector<int> v : vv)
        {
//            if (v[0] == now && !pass[v[1]])               // 输出33，是错误的。
            if (v[0] == now)                        // tle。。。25/41
            {
                dfsa1(n, vv, v[1], dst, k - 1, spend + v[2], pass);
            }
        }
    }

};

int main()
{

//    int n = 3, src = 0, dst = 2, k = 1;
//    vector<vector<int>> edges = {{0,1,100}, {1,2,100}, {0,2,500}};


//// 14
//    int n = 10;
//    vector<vector<int>> edges = {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},
//    {6,8,6},{7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},{4,0,9},
//    {5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
//    int src = 6;
//    int dst = 0;
//    int k = 7;


// 6
    int n = 4;
    vector<vector<int>> edges = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    int src = 0;
    int dst = 3;
    int k = 1;



    LT0787 lt;

    cout<<lt.lt0787b(n,edges, src, dst, k)<<endl;

    return 0;
}
