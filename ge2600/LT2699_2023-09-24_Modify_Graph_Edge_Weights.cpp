
#include "../header/myheader.h"

class LT2699
{
public:



// shortest distance ??  min(count(edge)) or min(sum(edge.weight)) ...
    vector<vector<int>> modifiedGraphEdges(
        int n, vector<vector<int>>& edges, int source, int destination, int target) {

        queue<tuple<int, int, vector<int>>> que;    // <node, sum not -1, -1 index>
        vector<vector<pair<int, int>>> vvp; // <next, edges.index>
        for (int i = 0; i < edges.size(); ++i)
        {
            vector<int>& vi = edges[i];
            vvp[vi[0]].push_back(std::make_pair(vi[1], i));
            vvp[vi[1]].push_back(std::make_pair(vi[0], i));
        }
        que.push(std::make_tuple(source, 0, vector<int>()));
        vector<bool> vst(n, false);
        vst[source] = true;
        int node, sum2;
        vector<int> vi;
        bool over = false;
        bool ok = false;
        while (!que.empty() && !over)
        {
            vector<bool> vst2(begin(vst), end(vst));

            for (int i = que.size(); i > 0; --i)
            {
                std::tie(node, sum2, vi) = que.front();
                que.pop();

                if (node == destination)
                {
                    over = true;
                    if (!vi.empty())
                    {
                        ok = true;
                        edges[vi[0]][2] = target - sum2 - vi.size() + 1;
                        for (vector<int>& vi : edges)
                        {
                            if (vi[2] == -1)
                                vi[2] = 1;
                        }
                        break;
                    }
                }


                for (pair<int, int>& pii : vvp[node])
                {
                    if (vst[pii.first])
                        continue;
                    vst2[pii.first] = true;

                    if (edges[pii.second][2] == -1)
                    {
                        if (sum2 + vi.size() + 1 >= target)
                            continue;

                        vector<int> v2(vi);
                        v2.push_back(pii.second);
                        que.push(std::make_tuple(pii.first, sum2, v2));
                    }
                    else
                    {
                        if (sum2 + edges[pii.second][2] + vi.size() >= target)
                            continue;

                        que.push(std::make_tuple(pii.first, sum2 + edges[pii.second][2], vi));
                    }
                }
            }

            swap(vst2, vst);
        }

        return ok ? edges : vector<vector<int>>();
    }

};

int main()
{

    LT2699 lt;

    int n = 5;
    vector<vector<int>> vvi = {{4,1,-1},{2,0,-1},{0,3,-1},{4,3,-1}};
    int s = 0, d = 1, t = 5;

    myvvi vv2 = lt.modifiedGraphEdges(n, vvi, s, d, t);

    for (myvi& vi : vv2)
    {
        cout<<vi[0]<<", "<<vi[1]<<", "<<vi[2]<<endl;
    }

    return 0;
}
