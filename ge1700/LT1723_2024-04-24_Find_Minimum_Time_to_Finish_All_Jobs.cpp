
#include "../header/myheader.h"

class LT1723
{
public:


    // D D

    // bs + dfs ...





    // // topic: dp, bitmask
    // // 4096
    // int minimumTimeRequired(vector<int>& jobs, int k)
    // {
    //
    // }




// Runtime
// 1701ms
// Beats12.73%of users with C++
// Memory
// 8.88MB
// Beats73.45%of users with C++

    // after solution, add if (mxwk >= ans) , then AC

    // tle .. tle
    int minimumTimeRequired__ee(vector<int>& jobs, int k)
    {
        std::sort(rbegin(jobs), rend(jobs));
        // int ans = INT_MAX;
        int ans = 0;
        for (int i = 0; i < jobs.size(); i += k)
        {
            ans += jobs[i];
        }

        vector<int> wk(k);
        dfsa1(jobs, wk, 0, 0, ans);
        return ans;
    }

    void dfsa1(vector<int>& jobs, vector<int>& wk, int idx, int mxwk, int& ans)
    {
        if (mxwk >= ans)            // AC, > 也是tle，必须 >=
            return;

        if (idx == jobs.size())
        {
            ans = min(ans, mxwk);
            return;
            // return mxwk;
            // int ans = -1;
            // for (int n : wk)
            //     ans = max(ans, n);
            // return ans;
        }

        int t2 = 0;
        for (int i = 0; i < wk.size(); ++i)
        {
            if (wk[i] + jobs[idx] <= ans)       // 删除 开头的 if (mxwk >= ans) return;   这里改成 < ，不行的，会tle。
            {
                wk[i] += jobs[idx];
                t2 = mxwk;
                mxwk = max(mxwk, wk[i]);
                dfsa1(jobs, wk, idx + 1, mxwk, ans);
                wk[i] -= jobs[idx];
                mxwk = t2;
            }
        }
    }


    // error

    // k <= job <= 12
    // priq ?  ...example 2
    // bs ?
    int minimumTimeRequired_eee(vector<int>& jobs, int k)
    {
        std::sort(rbegin(jobs), rend(jobs));

        int st = jobs[0];
        int en = std::accumulate(begin(jobs), end(jobs), 0);
        int ans = -1;
        while (st <= en)
        {
            int md = (st + en) / 2;
            vector<int> wk(k);
            int idx = 0;
            bool can = true;
            for (int job : jobs)
            {
                for (int i = 0; i < k; ++i)
                {
                    if (wk[i] + job <= md)
                    {
                        wk[i] += job;
                        goto AAA;
                    }
                }
                can = false;
                break;

                AAA:
                continue;

                // if (wk[idx] + job <= md)
                // {
                //     wk[idx] += job;
                // }
                // else
                // {
                //     if (idx + 1 < k)
                //     {
                //         idx += 1;
                //         wk[idx] += job;
                //     }
                //     else
                //     {
                //         wk[idx] += job;
                //     }
                // }
            }

#ifdef __test
            cout<<st<<", "<<md<<", "<<en<<", \n";
            showVectorInt(wk);
#endif

            // if (wk[k - 1] <= md)
            if (can)
            {
                ans = md;
                en = md - 1;
            }
            else
            {
                st = md + 1;
            }
        }
        return ans;

        // priority_queue<int, vector<int>, std::greater<>> priq;
        // for (int i = 0; i < k; ++i)
        //     priq.push(0);
        //
        // int ans = 0;
        // for (int i = 0; i < jobs.size(); ++i)
        // {
        //     int tm = priq.top();
        //     priq.pop();
        //     tm += jobs[i];
        //     priq.push(tm);
        // }
        // while (priq.size() > 1)
        //     priq.pop();
        // ans = priq.top();
        // return ans;
    }

//     int dfsa1(vector<int>& vi, )
//     {
//
//     }
};

int main()
{

    LT1723 lt;

    myvi v {1,2,4,7,8};
    int k = 2;

    cout<<lt.minimumTimeRequired(v, k);

    return 0;
}
