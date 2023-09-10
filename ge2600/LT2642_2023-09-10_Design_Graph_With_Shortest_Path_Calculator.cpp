
#include "../header/myheader.h"

class LT2642
{
public:



};

// D

// am[i][j] = min(am[i][j], am[i][e[0]] + am[e[1]][j] + e[2]);



// g

class Graph {

    vector<vector<int>> vvi;
    int sz1;

public:
    Graph(int n, vector<vector<int>>& edges) {
        this->vvi = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        this->sz1 = n;
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]][vi[1]] = vi[2];
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (vvi[i][k] == INT_MAX)
                    continue;
                for (int j = 0; j < n; ++j)
                {
                    if (vvi[k][j] == INT_MAX)
                        continue;
                    if (vvi[i][k] + vvi[k][j] < vvi[i][j])
                        vvi[i][j] = vvi[i][k] + vvi[k][j];
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        if (vvi[edge[0]][edge[1]] <= edge[2])
            return;

        int a = edge[0], b = edge[1];
        vvi[a][b] = edge[2];

        for (int i = 0; i < sz1; ++i)
        {
            if (vvi[i][a] == INT_MAX)
                continue;
            for (int j = 0; j < sz1; ++j)
            {
                if (vvi[a][j] == INT_MAX)
                    continue;

                if (vvi[i][a] + vvi[a][j] < vvi[i][j])
                    vvi[i][j] = vvi[i][a] + vvi[a][j];
            }
        }
    }

    int shortestPath(int node1, int node2) {
        if (node1 == node2)
            return 0;
        return vvi[node1][node2] == INT_MAX ? -1 : vvi[node1][node2];
    }
};


int main()
{

    LT2642 lt;


    return 0;
}
