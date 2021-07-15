
#include "../header/myheader.h"

class LT1335
{
public:

// D D


// top-down, bottom-up,  2维，1维(2个，swap)，stack。


//        for (int d = 0; d < D; ++d) {
//            stack.clear();
//            for (int i = d; i < n; i++) {
//                dp2[i] = i ? dp[i - 1] + A[i] : A[i];
//                while (stack.size() && A[stack.back()] <= A[i]) {
//                    int j = stack.back(); stack.pop_back();
//                    dp2[i] = min(dp2[i], dp2[j] - A[j] + A[i]);
//                }
//                if (stack.size()) {
//                    dp2[i] = min(dp2[i], dp2[stack.back()]);
//                }
//                stack.push_back(i);
//            }
//            swap(dp, dp2);
//        }




//Runtime: 32 ms, faster than 72.80% of C++ online submissions for Minimum Difficulty of a Job Schedule.
//Memory Usage: 7.8 MB, less than 25.39% of C++ online submissions for Minimum Difficulty of a Job Schedule.
// hint : dp[i][j] where DP states are i the index of the last cut and j the number of remaining cuts.
// 我怎么觉得好像真的只是hint。。还得改下。。 不好像就是这样，不过不能递归dp，需要递推dp
    int lt1335b(vector<int>& jobDifficulty, int d)
    {
        int sz1 = jobDifficulty.size();
        if (sz1 < d)
            return -1;

        // 任务从0开始，天数从1开始。
        vector<vector<int>> vvi(sz1 + 1, vector<int>(d + 1, INT_MAX));       // 已经几个任务完成，在第几天时。
//        int ans = 0;
        vvi[0][1] = jobDifficulty[0];
        for (int i = 1; i < sz1; ++i)
        {
            vvi[i][1] = max(vvi[i - 1][1], jobDifficulty[i]);
        }
        for (int i = 2; i <= d; ++i)
        {
            for (int j = i - 1; j < sz1; ++j)
            {
                int t2 = vvi[j - 1][i - 1];
//                #ifdef __test
//                if (t2 == 143)
//                {
//                    cout<<j<<", "<<i<<"    .... "<<endl;
//                }
//                #endif // __test
                int t3 = 0;
                for (int k = j; k < sz1; ++k)           // 反向更快。 反向得加 stack 或 priq。先顺序构造一个单调栈，然后逆序，元素==top，pop
                {
//                    #ifdef __test
//                    if (t2 == 143)
//                        cout<<k<<",| "<<endl;
//
//                    #endif // __test
                    // 感觉这样写还是tle啊。。试下。
                    t3 = max(t3, jobDifficulty[k]);
                    vvi[k][i] = min(t2 + t3, vvi[k][i]);            //  k  not j......吐了。。
//                    #ifdef __test
//                    if (j == 2 && i == 2)
//                        cout<<vvi[j][i]<<", "<<t2<<endl;
//                    if (j == 1 && i == 2)
//                        cout<<vvi[j][j]<<" ... "<<endl;
//                    #endif // __test
                }
            }
//            #ifdef __test
//            if (i == 2)
//            for (myvi& vi : vvi)
//            {
//                for (int i : vi)
//                    cout<<i<<", ";
//                cout<<endl;
//            }
//            #endif // __test
        }
//        #ifdef __test
//        for (myvi& vi : vvi)
//        {
//            for (int i : vi)
//                cout<<i<<", ";
//            cout<<endl;
//        }
//        #endif // __test
        return vvi[sz1 - 1][d];
//        int ans = INT_MAX;
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (vvi[i][d] == INT_MAX)
//                continue;
//            ans = min(ans, vvi[i][d]);
//        }
//        return INT_MAX == ans ? 0 : ans;
//        for (int i = 1; i <= d; ++i)        // day
//        {
//            for (int j = i - 1; j < sz1; ++j)      // job
//            {
//                // ... 怎么感觉很费操作呢。。
//            }
//        }

//        return ans;
    }



// tle.... memo只是剪枝，还是得计算，计算完后，才知道 已经有更小的了。 不过memo是从第一个任务到现在，所以 对于dp没有太大作用。
//          看hint的 dp描述， 好像就是memo的格式。
// 要求难度最低，难度是每天的难度和
// 每天的难度是当天的最大难度
// 每天必须执行一个任务
// 顺序执行。
// 最多300个任务， 10天。
// 感觉dfs下，就是一个划分，10天(应该)不会有问题的。
// dp的话，[已完成任务数][天数]。。好像。。
    int lt1335a(vector<int>& jobDifficulty, int d)
    {
        if (jobDifficulty.size() < d)
            return -1;

//        cout<<(sizeof memo)<<endl;
        memset(&memo, 123, sizeof memo);            // every byte... not every int(type)
//        cout<<memo[0][1]<<endl;
//        unsigned int aaa = INT_MAX;
//        cout<<aaa<<endl;
//        for (int i = 0; i < 10; ++i)
//        {
//            for (int j = 0; j < 10; ++j)
//            {
//                cout<<memo[i][j]<<", ";
//            }
//            cout<<endl;
//        }
        dfsa1(jobDifficulty, d, 1, 0, 0);
        return ans;
    }
    int ans = INT_MAX;
    int memo[302][11];
    void dfsa1(vector<int>& diff, int d, int now, int sum2, int idx)
    {
        #ifdef __test
//        cout<<now<<", "<<sum2<<", "<<idx<<endl;
        #endif // __test
        if (sum2 >= ans)
            return;
        if (memo[idx][now] < sum2)
        {
            #ifdef __test
//            cout<<idx<<", "<<now<<", "<<memo[idx][now]<<", "<<sum2<<endl;
            #endif // __test
            return;
        }

        memo[idx][now] = sum2;

        if (now == d)
        {
            if (idx < diff.size())
            {
                int t2 = 0;
                for (int i = idx; i < diff.size(); ++i)
                {
                    t2 = max(t2, diff[i]);
//                    std::max_element()
                }
                #ifdef __test
//                cout<<ans<<", "<<(sum2 + t2)<<endl;
                #endif // __test
                ans = min(ans, sum2 + t2);
            }
            return;
        }
        int t2 = 0;
        int i = idx;
        for (; i < diff.size() - (d - now); ++i)         // - (d - now) + 1/0
        {
//            if (t2 < diff[i])
//            {
//                t2 = diff[i];
//                dfsa1(diff, d, now + 1, sum2 + t2, i + 1);
//            }


            // tle...tuotuodi  , 加个memo，把那些 sum2太大的过滤掉。
            // 下面能得到1839, 上面是 2000多。  是因为上面会把难度小的 直接合并到今天， 没有拆分，
//            // 最好是 t2发生变化，才走下一步，但是 5,4,3,2,1的难度，会导致走不了。。 看来必须 -(d-now)
            t2 = max(t2, diff[i]);
            dfsa1(diff, d, now + 1, sum2 + t2, i + 1);
        }
//        dfsa1(diff, d, now + 1, sum2 + t2, i);           // 。。。。
    }

};

int main()
{
//    myvi v = {6,5,4,3,2,1};
//    int d = 2;

//    myvi v = {9,9,9};
//    int d = 4;

//    myvi v = {1,1,1};
//    int d = 3;

//    myvi v = {7,1,7,1,7,1};
//    int d = 3;

//    myvi v = {11,111,22,222,33,333,44,444};
//    int d = 6;

    cout<<std::numeric_limits<int>::max()<<endl;

    // 1839
    myvi v = {143,446,351,170,117
    ,963,785,76,139,772,452,743,23,767,564,872,922,532,957,945,203,615,843,909,458,320,290,235,174,814,414,669,422,769,781,721,523,94,100,464,484,562,941
    };
    int d = 5;


    LT1335 lt;

    cout<<lt.lt1335b(v, d);

    return 0;
}
