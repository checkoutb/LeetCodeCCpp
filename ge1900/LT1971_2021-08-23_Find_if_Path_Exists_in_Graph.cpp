
#include "../header/myheader.h"

class LT1971
{
public:

// D D

// uf





//Runtime: 664 ms, faster than 32.51% of C++ online submissions for Find if Path Exists in Graph.
//Memory Usage: 177.5 MB, less than 47.81% of C++ online submissions for Find if Path Exists in Graph.
// bi-directional... 无向图  。。。双向图
// vertex 顶点
    bool lt1971a(int n, vector<vector<int>>& edges, int start, int end)
    {
        vector<bool> vb(n);
        queue<int> que1;
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < edges.size(); ++i)
        {
            map2[edges[i][0]].push_back(edges[i][1]);
            map2[edges[i][1]].push_back(edges[i][0]);
        }
        vb[start] = true;
        que1.push(start);
        while (!que1.empty())
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                int t2 = que1.front();
                if (t2 == end)
                    return true;
                que1.pop();
                for (int t3 : map2[t2])
                {
                    if (!vb[t3])
                    {
                        vb[t3] = true;
                        que1.push(t3);
                    }
                }
            }
        }
        return false;
    }

};

int main()
{

//6
//[[0,1],[0,2],[3,5],[5,4],[4,3]]
//0
//5         // false            // map2[t2] 写成 edges[t2]。。。。。

    int n = 6;
    myvvi vv = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    int st = 0;
    int en = 5;

    LT1971 lt;

    cout<<lt.lt1971a(n, vv, st, en);

    return 0;
}
