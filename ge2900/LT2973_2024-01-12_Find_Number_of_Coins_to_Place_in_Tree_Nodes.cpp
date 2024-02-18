
#include "../header/myheader.h"

#include <array>

class LT2973
{
public:





// Runtime
// 860ms
// Beats75.82%of users with C++
// Memory
// 259.70MB
// Beats85.15%of users with C++


    // subtree.size < 3, 1 coin
    // substrr.size >=3,  max product of 3 node ...   -1 1000 -2 ,,   60 6000 60,,,  max 3, min 2
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost)
    {
        int sz1 = cost.size();
        vector<long long> vll(sz1, 0LL);
        vector<vector<int>> vvi(sz1);

        for (auto& vi : edges)
        {
            int a = vi[0], b = vi[1];
            vvi[a].push_back(b);
            vvi[b].push_back(a);
        }

        dfsa1(vvi, 0, -1, cost, vll);

        return vll;
    }

    // struct MyResult {
    //     std::array<int, 3> mx;
    //     std::array<int, 2> mn;
    // };
    //
    // auto create_my_result() -> MyResult
    // {
    //     MyResult ans;
    //     ans.mx[0] = ans.mx[1] = ans.mx[2] = -1;
    //     ans.mn[0] = ans.mn[1] = 1;
    //     return ans;
    // }
    //
    // void merge_mx(MyResult& ans, MyResult& beMerged)
    // {
    //     vector<int> vi;
    //     vi.push_back(std::begin(ans.mx), end(ans.mx));
    //     vi.push_back(std::begin(beMerged.mx), end(beMerged.mx));
    //
    // }
    //
    // void merge_mn(MyResult& ans, MyResult& beMerged)
    // {
    //     if (beMerged.mn[0] < ans.mn[0])
    //     {
    //         ans.mn[1] = ans.mn[0];
    //         ans.mn[0] = beMerged.mn[0];
    //         if (beMerged.mn[1] < ans.mn[1])
    //             ans.mn[1] = beMerged.mn[1];
    //     } else if (beMerged.mn[0] < ans.mn[1])
    //     {
    //         ans.mn[1] = beMerged.mn[0];
    //     }
    // }

    struct MyResult
    {
        std::vector<int> mx3;
        std::vector<int> mn3;
    };

    auto createMyResult(int cost) -> MyResult
    {
        MyResult ans;
        ans.mx3.push_back(cost);
        ans.mn3.push_back(cost);
        return ans;
    }

    auto mergeMyResult(MyResult& ans, MyResult& been) -> void
    {
        ans.mx3.insert(std::end(ans.mx3), begin(been.mx3), end(been.mx3));
        ans.mn3.insert(std::end(ans.mn3), begin(been.mn3), end(been.mn3));
        std::sort(begin(ans.mx3), end(ans.mx3), [](const int a, const int b) {
            return a > b;
        });
        std::sort(begin(ans.mn3), end(ans.mn3));

        if (ans.mx3.size() > 3)
            ans.mx3.resize(3);
        if (ans.mn3.size() > 3)
            ans.mn3.resize(3);
    }

    auto decideCoins(MyResult& ans) -> long long
    {
        if (ans.mx3.size() < 3)
            return 1;

        long long t2 = std::max(1LL * ans.mx3[0] * ans.mx3[1] * ans.mx3[2], 1LL * ans.mn3[0] * ans.mn3[1] * ans.mx3[0]);
        return max(t2, 0LL);
    }

    auto dfsa1(vector<vector<int>>& vvi, int node, int parent, vector<int>& cost, vector<long long>& vll) -> MyResult
    {
        MyResult ans = createMyResult(cost[node]);

        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;
            MyResult t2 = dfsa1(vvi, nxt, node, cost, vll);
            mergeMyResult(ans, t2);
        }

//         if (ans.mx3.size() < 3)
//         {
//             vll[node] = 1;
//         } else {
//
//         }

        vll[node] = decideCoins(ans);

        return ans;
    }

};

int main()
{

    LT2973 lt;

    myvvi vv {{1,0},{2,0},{3,0},{4,0},{5,0}};
    myvi cst = {1,2,3,4,5,6};

    auto ans = lt.placedCoins(vv, cst);

    for (long long ll : ans)
        cout<<ll<<", ";

    cout<<endl;

    return 0;
}
