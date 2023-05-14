
#include "../header/myheader.h"

class LT2642
{
public:



};


// hint: Dijkstra

// tle
class Graph {

    vector<vector<pair<int, int>>> vvi;
    int n;

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        this->vvi.resize(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            this->vvi[edges[i][0]].emplace_back(std::make_pair(edges[i][1], edges[i][2]));
        }
    }

    void addEdge(vector<int> edge) {
        this->vvi[edge[0]].push_back(std::make_pair(edge[1], edge[2]));
    }

    int shortestPath(int node1, int node2) {
        vector<int> vi(this->n, INT_MAX);
        dfsa1(this->vvi, node1, 0, vi);
        return vi[node2] == INT_MAX ? -1 : vi[node2];
    }

private:

    void dfsa1(vector<vector<pair<int, int>>>& vp, int node, int cost, vector<int>& vi)
    {
        if (vi[node] <= cost)
            return;

        vi[node] = cost;
        for (pair<int, int>& p : vp[node])
        {
            dfsa1(vp, p.first, p.second + cost, vi);
        }
    }

};


int main()
{

    LT2642 lt;


    return 0;
}
