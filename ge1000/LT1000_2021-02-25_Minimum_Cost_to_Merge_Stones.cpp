
#include "../header/myheader.h"

class LT1000
{
public:


// dp,   只有k个的时候 只有一种方法， k+1 时， 1+k 或者 k+1, 2种，  k+2时， 1+1+K, k+1+1, 1+k+1,  k+K(k==2时)
// 这不是dp，  暴力。  没有办法memo吧， 毕竟 当前最小，并不意味着，， 可以memo，不过还是得计算的。
// dfs + memo ？




// error ... 6 4 4 6 ... 40, not 42...
    int lt1000b(vector<int>& stones, int K)
    {
        int sz1 = stones.size();
        if (sz1 <= 1)
            return 0;
        if (sz1 < K * 2 - 1 && sz1 != K)
            return -1;
        dfsb1(stones, K, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsb1(vector<int>& vi, int k, int cost)
    {
        if (vi.size() == 1)
        {
            ans = min(cost, ans);
            return;
        }
        if (cost >= ans)
            return;

        int sz1 = vi.size();
        vector<int> v2(sz1 - k + 1);
        int sum2 = std::accumulate(begin(vi), begin(vi) + k, 0);
        v2[0] = sum2;
        int mnv2 = sum2;
        for (int i = 1; i < v2.size(); ++i)
        {
            // 一个数 会被 加几次， 如果这个数 在 0/sz-1， 那么可以 只加一次。  难道二分？ 然后 merge次数？不行的， 分开后，可能无法合并石头
            sum2 += (vi[i + k - 1] - vi[i - 1]);
            v2[i] = sum2;
            mnv2 = min(sum2, mnv2);
        }
        for (int i = 0; i < v2.size(); ++i)
        {
            if (mnv2 == v2[i])
            {
                vector<int> v3(begin(vi), end(vi));
                v3[i] = mnv2;
                for (int j = 1; j < k; ++j)
                {
                    v3.erase(begin(v3) + i + 1);
                }
                dfsb1(v3, k, cost + mnv2);
            }
        }
    }


// 贪心？
// 2个 min 呢？ 。。。 give up....
    int lt1000a(vector<int>& stones, int K)
    {
        int sz1 = stones.size();
        if (sz1 < K * 2 - 1 && sz1 != K)
            return -1;
        vector<int> vi = {1,2};
        vector<int> vi2 = stones;
        while (vi.size() > 1)
        {
//            int sum2 = 0;
//            for (int i = 0; i < K; i++)
//            {
//                sum2
//            }
            int sum2 = std::accumulate(begin(vi2), begin(vi2) + K, 0);
            vi.resize(vi2.size() - K + 1);
            vi[0] = sum2;
            for (int i = K; i < vi2.size(); ++i)
            {
                sum2 += (vi2[i] - vi2[i - K]);
                vi[i - K + 1] = sum2;
            }

            std::swap(vi, vi2);
        }
    }

};

int main()
{
//    myvi v = {3,2,4,1};
//    int k = 2;

//    myvi v = {3,2,4,1};
//    int k = 3;

//    myvi v = {3,5,1,2,6};
//    int k = 3;

    myvi v = {6,4,4,6};     // 40   4+6  4+6  10+10 ...
    int k = 2;

    LT1000 lt;

    cout<<lt.lt1000b(v, k)<<endl;

    return 0;
}
