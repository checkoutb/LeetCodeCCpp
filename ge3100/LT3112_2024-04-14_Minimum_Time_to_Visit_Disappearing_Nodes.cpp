
#include "../header/myheader.h"

class LT3112
{
public:







// Runtime
// 441ms
// Beats54.55%of users with C++
// Memory
// 195.25MB
// Beats27.27%of users with C++
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear)
    {
        std::vector<std::unordered_map<int, int>> vm(n);
        int n1, n2, w;
        for (int i = 0; i < edges.size(); ++i)
        {
            n1 = edges[i][0], n2 = edges[i][1], w = edges[i][2];
            if (!vm[n1].contains(n2) || vm[n1][n2] > w) {
                vm[n1][n2] = w;
            }
            if (!vm[n2].contains(n1) || vm[n2][n1] > w) {
                vm[n2][n1] = w;
            }
        }
        std::vector<int> ans(n, -1);

#ifdef __test
        for (int i = 0; i < n; ++i)
        {
            for (auto& p : vm[n])
            {
                std::cout<<i<<" to "<<p.first<<" minDis: "<<p.second<<std::endl;
            }
        }
#endif

        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<>> priq;   // <time, node>
        priq.push(std::make_pair(0, 0));
        int tm, node;
        while (!priq.empty())
        {
            std::pair<int, int> p = priq.top();
            priq.pop();
            tm = p.first;
            node = p.second;

#ifdef __test
            std::cout<<node<<" - "<<tm<<std::endl;
#endif

            if (tm >= disappear[node])
                continue;

            if (ans[node] == -1)
            {
                ans[node] = tm;
                for (auto& p : vm[node])
                {
                    if (ans[p.first] == -1)
                    {
                        priq.push(std::make_pair(tm + p.second, p.first));
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{

    LT3112 lt;

    // int n{3};
    // myvvi vv {{0,1,2},{1,2,1},{0,2,4}};
    // myvi vi {1,1,5};

    int n{3};
    myvvi vv {{0,1,2},{1,2,1},{0,2,4}};
    myvi vi {1,3,5};

    vi = lt.minimumTime(n,vv,vi);

    showVectorInt(vi);

    return 0;
}
