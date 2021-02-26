
#include "../header/myheader.h"

class LT1040
{
public:

// D D

// sliding windows. 。。。

//        sort(A.begin(), A.end());
//        int i = 0, n = A.size(), low = n;
//        int high = max(A[n - 1] - n + 2 - A[1], A[n - 2] - A[0] - n + 2);
//        for (int j = 0; j < n; ++j) {
//            while (A[j] - A[i] >= n) ++i;
//            if (j - i + 1 == n - 1 && A[j] - A[i] == n - 2)
//                low = min(low, 2);
//            else
//                low = min(low, n - (j - i + 1));
//        }
//        return {low, high};
// .............................................
// zhen tmd meng.




// 或许应该用 upper_bound。。
//Runtime: 20 ms, faster than 88.10% of C++ online submissions for Moving Stones Until Consecutive II.
//Memory Usage: 12.1 MB, less than 82.14% of C++ online submissions for Moving Stones Until Consecutive II.

// endpoint 就2个， 然后选择 各自的 最近，最远。  倒数第二个，要给倒数第一个 留个位置。 但是，是不是 必然可以留一个位置？
// dfs 肯定tle的，  [1,2,3, 10^9]， 这个得。。
// 感觉是 最大空隙，和最小空隙。
// 1个点。。
// 2个点。。都动不了
// 只要>=3个点，最终都能 相邻。 最多次数： 所有空隙 - min(endpoint旁边的空隙)
// 最少次数，寻找2个石头，这2个石头相距sz1-2 (就是 最终相邻后， 这2个石头是 头 尾)。  不不不
// 应该是 对每个石头计算， 它后续sz1-1个位置中的 空隙，的和 ， min(和) 就是 最少次数，  第一个点好像没有办法计算。第一个点除非 正好有一个 在sz1的尾巴
// 不， 第一个点，如果sz1没有石头，除非sz1 之后 还有2个点，不然没有 石头能够 达到 sz1。
    vector<int> lt1040a(vector<int>& stones)
    {
        int sz1 = stones.size();
        if (sz1 <= 2)
            return {0, 0};
        std::sort(begin(stones), end(stones));

        int mx = (stones[sz1 - 1] - stones[0] + 1 - sz1 - min(stones[sz1 - 1] - stones[sz1 - 2] - 1, stones[1] - stones[0] - 1));
        int mn = INT_MAX;
        vector<int>::iterator it = std::lower_bound(begin(stones), end(stones), stones[0] + sz1 - 1);
//        int vit = *it;
        #ifdef __test
        cout<<" it "<<*it<<endl;
        #endif // __test
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = stones[i] + sz1 - 1;
            while (it != end(stones) && t2 > *it)
            {
                it++;
            }
            if (it == end(stones))
            {
                break;
            }
            if (i == 0)
            {
                if (*it == t2 || std::distance(it, end(stones)) >= 2)
                {
//                    if (*it == t2)
//                    {
//cout<<std::distance(begin(stones), it)<<" . . ."<<endl;
                        mn = min(mn, (int) (sz1 - std::distance(begin(stones), it) - (t2 == *it)));
//                    }
//                    else
//                    {
//
//                    }
                }
            }
            else
            {
                #ifdef __test
                cout<<(int) std::distance(begin(stones) + i, it)<<endl;
                cout<<*it<<endl;

                #endif // __test
                mn = min(mn, sz1 - (int) std::distance(begin(stones) + i, it) - (t2 == *it));
            }
            #ifdef __test

            cout<<i<<", "<<mn<<endl;
            #endif // __test
        }
        return {mn, mx};
    }

};

int main()
{
//    myvi v = {7,4,9};     // 1 2
//    myvi v = {6,5,4,3,10};        // 2 3
//    myvi v = {100,101,104,102,103};
//    myvi v = {8,7,6,5,10};      // 1 1
    myvi v = {1,500000000,1000000000};        //2 4999

    LT1040 lt;

    myvi v2 = lt.lt1040a(v);

    cout<<v2[0]<<", "<<v2[1]<<endl;

    return 0;
}
