
#include "../header/myheader.h"

class LT2699
{
public:



// vvi 没有办法返回edges。 需要 tuple<node, weight, edgeIndex>。。
// 找到 min path 后，修改 path 上的 第一个碰到 -1 的边的值 为 target - dis。 其他的-1的边的值 为 1。
// 其他的 -1的边 都改成 200000000。
// 再执行一次 min path，min dis == target 就返回 边， 否则就是 返回 {}

// 。下次。

    vector<vector<int>> modifiedGraphEdges(
        int n, vector<vector<int>>& edges, int source, int destination, int target) {
        
        int sz1 = edges.size();
        vector<vector<pair<int, int>>> vvi(n);   // node : <node, weight>
        int a,b,w;
        for (int i = 0; i < sz1; ++i)
        {
            a = edges[i][0];
            b = edges[i][1];
            w = edges[i][2];
            vvi[a].push_back(std::make_pair(b, w));
            vvi[b].push_back(std::make_pair(a, w));
        }

        priority_queue<pair<int, vector<int>>> priq;        // <distance, path>
        priq.push(std::make_pair(0, {source}));
        vector<int> path;
        int dis;
        while (!priq.empty())
        {
            pair<int, vector<int>> piv = priq.top();
            priq.pop();
            dis = piv.first;
            path = piv.second;

            if (dis > target)
            {
                return {};
            }
            if (path.back() == destination)
            {
                break;
            }

            for (pair<int, int> p : vvi[path.back()])
            {
                if (path.size() > 1 && path[path.size() - 2] == p.first)
                    continue;

                vector<int> v2 = path;
                v2.push_back(p.first);
                priq.push(make_pair(dis + (p.second == -1 ? 1 : p.second)), v2);
            }
        }





        // long long st = 1;
        // long long en = 2000000000;
        // while (st < en)
        // {
        //     long long md = (st + en) / 2;

        // }
    }


    // int minDistance(vector<vector<pair<int, int>>>& vvi, long long md, int target, int st, int en)
    // {
    //     priority<pair<long long, int>> priq;        // <distance, now node>
    //     priq.push(std::make_pair(0LL, st));

    //     while (!priq.empty())
    //     {
    //         pair<long long, int> plli = priq.top();
    //         priq.pop();

    //         if (plli.first > target)
    //         {
    //             return target + 1;
    //         }
    //     }
    // }

};

int main()
{

    LT2699 lt;


    return 0;
}
