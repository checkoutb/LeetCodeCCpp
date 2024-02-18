
#include "../header/myheader.h"

#include <format>

class LT2975
{
public:

    // D D

        // if (m == n)
        //     return (long)(n - 1) * (n - 1) % 1000000007;
        // HF.push_back(1), VF.push_back(1), HF.push_back(m), VF.push_back(n);
        // if (HF.size() > VF.size())
        //     swap(HF,VF);
        // sort(VF.begin(), VF.end());
        // unordered_set<int> hset;
        // long best = 0, diff;
        // for (int i = HF.size() - 1; i; i--)
        //     for (int j = 0; j < i; j++)
        //         hset.insert(abs(HF[i] - HF[j]));
        // for (int i = VF.size() - 1; i; i--)
        //     for (int j = 0; j < i && best < (diff = VF[i] - VF[j]); j++)
        //         if (hset.find(diff) != hset.end())
        //             best = diff;
        // return best ? best * best % 1000000007 : -1;

    // ...........................



// Runtime
// 839ms
// Beats99.38%of users with C++
// Memory
// 55.92MB
// Beats99.41%of users with C++


    // ca, MLE, 内存炸了。 。。。 m,n < 10^9

    // 本来想  while (get<0>(pq.top()) == a)  pq.pop()， 但是不行， 长度相同，不代表 下标会类似。
    // 想到下标，想到了 重复子问题。  [xx, 1, 10] -> [xx, 2, 10] -> [xx, 2, 9]
    //                           [xx, 1, 10] -> [xx, 1, 9] -> [xx, 2, 9]         2,9 就重复了。

    // 2943 rust的， length <= 100。 Jan 05, 2024 14:18 。 similar question中看到的。

    // 看了下 hint，没什么启发。

    // tle ....

    // 我记得我做过，类似的，一模一样，除了形参名。。h_vec, v_vec, 好像是rust的。
    // 这个就是找到， 相同的 水平 和 垂直 的值。
    // size < 600 .. (600)*(600+1)/2 ...
    // 双指针，不行。 priq了
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences)
    {
        std::sort(begin(hFences), end(hFences));
        std::sort(begin(vFences), end(vFences));

        std::priority_queue<tuple<int, int, int>> pqh;
        std::priority_queue<tuple<int, int, int>> pqv;

        pqh.push(std::make_tuple(m - 1, -1, static_cast<int>(hFences.size())));
        pqv.push(std::make_tuple(n - 1, -1, static_cast<int>(vFences.size())));

        vector<vector<bool>> vvbh(hFences.size() + 2, vector<bool>(hFences.size() + 2));        // [m+2][m+2], MLE
        vector<vector<bool>> vvbv(vFences.size() + 2, vector<bool>(vFences.size() + 2));

        const int MOD = 1e9 + 7;

        while (!pqh.empty() && !pqv.empty())
        {

            // 之前用了 &， 导致 pop后， 未定义了。。但是没有报错。
            auto [a,b,c] = pqh.top();
            auto [x,y,z] = pqv.top();
#ifdef __test
            // cout<<a<<", "<<x<<endl;
            // getchar();
            cout<<a<<" - "<<b<<" - "<<c<<endl;
            cout<<std::format("{} {} {}", x, y, z)<<endl;
#endif
            if (a == x)
            {
                return 1LL * a * x % MOD;
            }
            else if (a > x)
            {
                pqh.pop();
                if ((b + 1) == c)
                    continue;

                if (vvbh[b + 1 + 1][c + 1] == false)
                {
                    pqh.push(std::make_tuple((c == hFences.size() ? m : hFences[c]) - hFences[b + 1], b + 1, c));
                    vvbh[b + 1 + 1][c + 1] = true;
                }


                if (vvbh[b + 1][c - 1 + 1] == false)
                {
                    // b == -1 => 1, not 0
                    pqh.push(std::make_tuple(hFences[c - 1] - (b == -1 ? 1 : hFences[b]), b, c - 1));
                    vvbh[b + 1][c - 1 + 1] = true;
                }
            }
            else
            {
                pqv.pop();
                if ((y + 1) == z)
                    continue;
                if (vvbv[y + 1 + 1][z + 1] == false)
                {
                    pqv.push(make_tuple((z == vFences.size() ? n : vFences[z]) - vFences[y + 1], y + 1, z));
                    vvbv[y + 1 + 1][z + 1] = true;
                }
                if (vvbv[y + 1][z - 1 + 1] == false)
                {
                    pqv.push(make_tuple(vFences[z - 1] - (y == -1 ? 1 : vFences[y]), y, z - 1));
                    vvbv[y + 1][z - 1 + 1] = true;
                }
            }
        }
        return -1;
    }

};

int main()
{

    LT2975 lt;

    // int m{4}, n{3};
    // myvi v{2,3}, v2{2};

    int m{6}, n{7};
    myvi v{2}, v2{4};

    cout<<lt.maximizeSquareArea(m,n,v,v2)<<endl;

    return 0;
}
