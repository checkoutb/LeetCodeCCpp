
#include "../header/myheader.h"

class LT3243
{
public:





    // II 提交了，TLE。 而且 II 除了n变大，还有一个约束，就是 2个 query 不会 半重叠。 要么 全部包含，要么 完全不重叠。
    // 似乎变简单了？某种意义上简单， 只需要判断下，如果被之前的 query包含了，那么 do nothing。
    //   如果没有被包含，那么直接 减去 query 覆盖的长度 就是 0 - n-1 的路径。

    
// Runtime
// 96ms
// Beats92.10%
// Analyze Complexity
// Memory
// 106.90MB
// Beats80.00%

    

    // 只会硬算。 II肯定不行。
    // 硬算也很麻烦。。
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        std::vector<int> vi(n);
        std::iota(std::begin(vi), std::end(vi), 0);

        int szq = queries.size();
        std::vector<int> vans(szq);
        std::vector<std::vector<int>> vnxt(n);
        int st, en;
        for (int i = 0; i < szq; ++i) {
            st = queries[i][0], en = queries[i][1];

            vnxt[st].push_back(en);
            
            std::queue<std::pair<int, int>> que;
            que.push(std::make_pair(st, vi[st]));

            while (!que.empty()) {
                auto& [idx, len] = que.front();

                if (idx + 1 < n && vi[idx + 1] > len + 1) {
                    vi[idx + 1] = len + 1;
                    que.push(std::make_pair(idx + 1, len + 1));
                }
                for (int nxt : vnxt[idx]) {
                    if (vi[nxt] > len + 1) {
                        vi[nxt] = len + 1;
                        que.push(std::make_pair(nxt, len + 1));
                    }
                }

                que.pop();
            }

            vans[i] = vi[n - 1];
        }
        return vans;
    }


};

int main()
{

    LT3243 lt;


    return 0;
}
