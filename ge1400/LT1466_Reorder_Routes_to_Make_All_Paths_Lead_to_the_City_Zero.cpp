
#include "../header/myheader.h"

class LT1466
{
public:

// D D

//vector<vector<int>> adj(n), back(n);
// 替代 map



//Runtime: 648 ms, faster than 37.29% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
//Memory Usage: 101.2 MB, less than 30.13% of C++ online submissions for Reorder Routes to Make All Paths Lead to the City Zero.
    int lt1466a(int n, vector<vector<int>>& connections)
    {
        unordered_map<int, vector<int>> map2;       // start - destination
        unordered_map<int, vector<int>> map3;       // destination : start
        for (vector<int>& vi : connections)
        {
            map2[vi[0]].push_back(vi[1]);
            map3[vi[1]].push_back(vi[0]);
        }
        int ans = 0;
        queue<int> que1;
        vector<bool> visit(n, false);
        que1.push(0);
        while (!que1.empty())
        {
            int fnt = que1.front();
            que1.pop();
            if (visit[fnt])
                continue;
            visit[fnt] = true;
            if (map3.find(fnt) != map3.end())
                for (int dest : map3[fnt])
                    que1.push(dest);
            if (map2.find(fnt) != map2.end())
            {
                for (int st : map2[fnt])
                {
                    if (!visit[st])
                    {
                        ans++;
                        que1.push(st);
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{
//    int n = 6;
//    vector<vector<int>> vv = {{0,1},{1,3},{2,3},{4,0},{4,5}};

//    int n{5};
//    vector<vector<int>> vv = {{1,0},{1,2},{3,2},{3,4}};

    int n{3};
    vector<vector<int>> vv = {{1,0},{2,0}};

    LT1466 lt;

    cout<<lt.lt1466a(n, vv);

    return 0;
}
