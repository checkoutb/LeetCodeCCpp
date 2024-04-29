
#include "../header/myheader.h"

#include <array>

class LT0947
{
public:


    // D D

    // join(stones[i][0], stones[i][1] + 10001);

    // Count the Number of Islands, O(N)


// x + ~x = -1, so ~x = -1 - x



// Runtime
// 19ms
// Beats98.28%of users with C++
// Memory
// 18.42MB
// Beats74.76%of users with C++
    // ?
    // one | , at most one can alive. ok! no .
    // uf ?this point can be removed by which
    int removeStones(vector<vector<int>>& stones)
    {
        int sz1 = stones.size();
        std::array<int, 10001> arr;
        arr.fill(-2);       // -2: not exist,  -1:exist, >=0: uf

        int t2, t3;
        // for (vector<int>& vi : stones)       // ?haha
        // {
        //     if (arr[vi[0]] == -2)
        //         arr[vi[0]] = -1;
        //     if (arr[vi[1]] == -2)
        //         arr[vi[1]] = -1;
        //
        //     t2 = ufa(arr, vi[0]);
        //     t3 = ufa(arr, vi[1]);
        //
        //     if (t2 != t3)
        //         arr[t2] = t3;
        // }

        for (vector<int>& vi : stones)
        {
            arr[vi[1]] = -1;
        }

        std::ranges::sort(stones);

        for (int i = 1; i < sz1; ++i)
        {
            if (stones[i][0] == stones[i - 1][0])
            {
                t2 = ufa(arr, stones[i][1]);
                t3 = ufa(arr, stones[i - 1][1]);
                if (t2 != t3)
                    arr[t2] = t3;
            }
        }
        int ans = sz1 - std::ranges::count_if(arr, [](int i){ return i == -1; });
        return ans;
    }

    int ufa(std::array<int, 10001>& arr, int idx)
    {
        if (arr[idx] >= 0)
        {
            return arr[idx] = ufa(arr, arr[idx]);
        }
        return idx;
    }
};

int main()
{

    LT0947 lt;

    myvvi vv {{0,0},{1,1},{0,2},{2,0},{2,2}};

    cout<<lt.removeStones(vv);

    return 0;
}
