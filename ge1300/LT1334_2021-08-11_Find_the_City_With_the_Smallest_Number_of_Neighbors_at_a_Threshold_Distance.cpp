
#include "../header/myheader.h"

class LT1334
{
public:

// D D

// Floyd...


//Floyd: 14ms
//Dijkstra: 32ms
//SPFA: 64ms
//Bellman: 251ms




// who needs memo?  希望世界没有dp。

//Runtime: 32 ms, faster than 93.34% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.
//Memory Usage: 16.4 MB, less than 21.72% of C++ online submissions for Find the City With the Smallest Number of Neighbors at a Threshold Distance.

// 每个bfs/dfs下，
// 而且是 无向图，所以可以memo。 不过memo 怎么用？ 。memo[][] 代表下标1到下标2的距离？  -1代表没有遇到。
// 还有一个 提前退出，毕竟要找 最少的。
// 先不用memo吧， 感觉是， 全部 INT_MAX, 然后edges中设置到 memo中，  然后dfs的时候， 根据剩余距离，看现在这个点能到哪里(memo中值小于 剩余距离)
//   但是memo 没有办法跨点。 或者说 需要 更新一遍。 所有后继的 能到达的点 更新到本节点，min一下。
// 那不如bfs，然后所有能到达点更新到 自己。
// 先不用memo， 就一个提前退出，试试会不会tle
    int lt1334a(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
//        unordered_map<int, vector<pair<int, int>>> map2;        // <start, <end, distance>>
        unordered_map<int, vector<vector<int>>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi);
            swap(vi[1], vi[0]);
            map2[vi[0]].push_back(vi);
        }
        int ans = -1;
        int cnt = INT_MAX;          // count of ans's neighbour
//        vector<bool> vst(n);
        vector<int> vst(n);
//        for (int i = 0; i < n; ++i)
        for (int i = n - 1; i >= 0; --i)
        {
            queue<pair<int, int>> que1;     // city, remain distance
            que1.push({i, distanceThreshold});
            std::fill(begin(vst), end(vst), -1);     // 还剩多少长度, 让0也通过。
            vst[i] = distanceThreshold;
            int cnt2 = 0;
            while (!que1.empty())
            {
                int szq = que1.size();
                while (szq-- > 0)
                {
                    pair<int, int> p = que1.front();
                    int t2 = p.first;
                    int t3 = p.second;
                    que1.pop();
                    for (vector<int>& vi : map2[t2])
                    {
                        if (vst[vi[1]] < (t3 - vi[2])   // 估计有些测试 会不停刷新。。。
//                             && vi[2] <= t3
                             )
                        {
                            if (vst[vi[1]] == -1)    // ..
                                cnt2++;
                            vst[vi[1]] = (t3 - vi[2]);
//                            vst[vi[1]] = true;      // ... 路径刷新，更短了。
                            if (cnt2 >= cnt)
                                goto AAA;
                            que1.push({vi[1], t3 - vi[2]});
                            #ifdef __test
//                            if (i == 3)
//                            {
//                                cout<<"        "<<vi[1]<<", "<<(t3 - vi[2])<<endl;
//                            }
                            #endif // __test
                        }
                    }
                }
            }
            if (cnt > cnt2)     // 全0的时候，需要这个。
            {
                cnt = cnt2;
                ans = i;
            }
            #ifdef __test
//            cout<<ans<<", "<<cnt<<endl;
            #endif // __test
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

//    myvvi vv = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
//    int n{4}, dis{4};

//    myvvi vv = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
//    int n{5}, dis{2};


// 7
    myvvi vv = {{3,6,5840},{0,6,7765},{0,4,4017},{0,3,3930},{0,7,1730},{3,4,9214},{0,5,5861},{2,6,2600},
    {1,4,1908},{4,6,665},{1,5,5140},{5,7,6921},{2,7,5674},{1,2,4154},{2,5,913},{0,2,7125},{6,7,6799},
    {1,7,6166},{4,5,5878},{1,6,4816},{1,3,5591},{5,6,7226},{3,7,3901},{3,5,9989},{2,3,8504},{4,7,2366}};
    int n{8}, dis{919};

    LT1334 lt;

    cout<<lt.lt1334a(n, vv, dis);

    return 0;
}
