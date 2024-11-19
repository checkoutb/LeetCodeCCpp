
#include "../header/myheader.h"

class LT3203
{
public:




// Runtime
// 743ms
// Beats57.44%
// Analyze Complexity
// Memory
// 334.13MB
// Beats30.89%
    

// [[0,1],[2,0],[3,2],[3,6],[8,7],[4,8],[5,4],[3,5],[3,9]]
// [[0,1],[0,2],[0,3]]
// 7
// ... after connect, max length is still edges1's max path,  not connected path.

    // find each tree's longest path's mid point, connect them.
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // int t2 = 0; // max node
        // int t3 = 0;

        // for (int i = 0; i < edges1.size(); ++i) {
        //     t2 = std::max(t2, std::max(edges1[i][0], edges1[i][1]));
        // }

        // for (int i = 0; i < edges2.size(); ++i) {
        //     t3 = std::max(t3, std::max(edges2[i][0], edges2[i][1]));
        // }

        // std::vector<std::vector<int>> vvi1(t2 + 1);
        // std::vector<std::vector<int>> vvi2(t3 + 1);

        // for (std::vector<int>& vi : edges1) {
        //     vvi1[vi[0]].push_back(vi[1]);
        //     vvi1[vi[1]].push_back(vi[0]);
        // }

        // for (std::vector<int>& vi : edges2) {
        //     vvi2[vi[0]].push_back(vi[1]);
        //     vvi2[vi[1]].push_back(vi[0]);
        // }

        int mxlen1 = calMaxLength(edges1);
        int mxlen2 = calMaxLength(edges2);

        int t2 = (mxlen1 + 1) / 2 + (mxlen2 + 1) / 2 + 1;
        return std::max(t2, std::max(mxlen1, mxlen2));
    }

    // length is count of edge
    // 这个是baidu后的，我不知道怎么计算 最长路径 (想到的最好的方法是：对每个度为1的顶点 bfs)，baidu后： 对于任意一个node，该node的 最远节点 必然是 最长路径的 一个端点， 然后 对这个端点 再计算 最远node 就可以获得 最长路径的 另一个端点。
    int calMaxLength(std::vector<std::vector<int>>& edges) {
        int t2 = 0;
        for (std::vector<int>& vi : edges) {
            t2 = std::max(t2, std::max(vi[0], vi[1]));
        }

        std::vector<std::vector<int>> vvi(t2 + 1);

        for (std::vector<int>& vi : edges) {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }

        std::pair<int, int> p = findFarestNodeAndLength(0, vvi);
        p = findFarestNodeAndLength(p.first, vvi);
        return p.second;
    }

    // bfs
    // Length is count of edge, == nodes' count - 1
    // if count of farest node more then 1, random choose.
    std::pair<int, int> findFarestNodeAndLength(int node2, std::vector<std::vector<int>>& vvi) {
        std::vector<pair<int, int>> vi; // <node, parent>
        vi.push_back(std::make_pair(node2, -1));
        int length = -1;
        int node = -1;
        while (!vi.empty()) {
            int sz1 = vi.size();
            node = vi[sz1 - 1].first;
            std::vector<std::pair<int, int>> v2;
            for (int i = 0; i < sz1; ++i) {
                int t2 = vi[i].first;
                int par = vi[i].second;

                for (int nxt : vvi[t2]) {
                    if (nxt == par)
                        continue;

                    v2.push_back(std::make_pair(nxt, t2));
                }
            }

            // if (!v2.empty()) // length begin with -1, not 0
                ++length;
            
            std::swap(vi, v2);
        }

        return std::make_pair(node, length);
    }

};

int main()
{

    LT3203 lt;


    return 0;
}
