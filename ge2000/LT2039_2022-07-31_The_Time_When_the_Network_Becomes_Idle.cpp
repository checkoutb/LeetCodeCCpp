
#include "../header/myheader.h"

class LT2039
{
public:

    // D D




//Runtime: 1206 ms, faster than 39.40% of C++ online submissions for The Time When the Network Becomes Idle.
//Memory Usage: 218.5 MB, less than 10.76% of C++ online submissions for The Time When the Network Becomes Idle.
    // server 0 是处理机， 立刻处理并返回，不消耗时间。
    // 其他的server 发送数据 给server 0，然后等待数据
    // 2台服务器间，1秒内可以传输 任意多的数据。 但是 必须要 1秒。
    // dijkstra，0 到其他点的 ，， 单源最短路径。   取最近的，然后松弛，然后取最近的。 权是1。 权是1，感觉不如bfs。。。不需要dijkstra。。练练
    int lt2039a(vector<vector<int>>& edges, vector<int>& patience)
    {
        int sz1 = patience.size();
        vector<int> vi(sz1, INT_MAX);

        unordered_map<int, vector<int>> map2;
        for (vector<int>& vi : edges)
        {
            map2[vi[0]].push_back(vi[1]);
            map2[vi[1]].push_back(vi[0]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priq;   // <distance, idx>
        priq.push({0, 0});
        vi[0] = 0;
        while (!priq.empty())
        {
            pair<int, int> p = priq.top();
            priq.pop();
            int dis = p.first;
            int idx = p.second;
//            if (dis > vi[idx])            // ? 感觉不会发生，priq. dui  不会发生。 那就 没有多余的数据， 很快的。
//                continue;
            for (int nxt : map2[idx])
            {
                if (dis + 1 < vi[nxt])
                {
                    vi[nxt] = dis + 1;
                    priq.push({dis + 1, nxt});
                }
            }
        }

        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        int ans = 0;
        for (int i = 1; i < sz1; ++i)
        {
            int t2 = vi[i] * 2;
            t2 += ((t2 - 1) / patience[i]) * patience[i];
            ans = max(ans, t2);
        }

        return ans + 1;
    }

};

int main()
{

    LT2039 lt;

    myvvi vv = {{0,1},{1,2}};
    myvi v = {0,2,1};

//    myvvi vv = {{0,1},{1,2},{0,2}};
//    myvi v = {0,11,1};

    cout<<lt.lt2039a(vv, v)<<endl;

    return 0;
}
