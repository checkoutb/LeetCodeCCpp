
#include "../header/myheader.h"

class LT1723
{
public:


// g

    // hint : We can select a subset of tasks and assign it to a worker then solve the subproblem on the remaining tasks
    // zhuang ya dp ?

    // tle
    // <= 12
    int minimumTimeRequired(vector<int>& jobs, int k)
    {
        int sz1 = jobs.size();
        sort(rbegin(jobs), rend(jobs));
        int st = jobs[0];
        int en = std::accumulate(begin(jobs), end(jobs), 0);
        int ans = -1;
        while (st <= en)
        {
            vector<int> vi(k, 0);
            int md = (st + en) / 2;

            #ifdef __test
            cout<<st<<" - "<<md<<" - "<<en<<endl;
            #endif
            if (canFinish(jobs, 0, 0, vi, md))
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
    }

    bool canFinish(vector<int>& jobs, int done, int idx, vector<int>& vi, int lmt)
    {
        if (idx == jobs.size())
            return true;
        
        #ifdef __test
        cout<<idx<<", "<<endl;
        #endif

        for (int i = 0; i < vi.size(); ++i)
        {
            if (jobs[idx] + vi[i] <= lmt)
            {
                vi[i] += jobs[idx];
                if (canFinish(jobs, done, idx + 1, vi, lmt))
                    return true;
                vi[i] -= jobs[idx];
            }
        }
        return false;
    }

};

int main()
{

    LT1723 lt;

    // myvi vi = {3,2,3};
    // int k = 3;

    // myvi vi = {1,2,4,7,8};
    // int k = 2;

    myvi vi = {254,256,256,254,251,256,254,253,255,251,251,255};
    int k = 10;

    cout<<lt.minimumTimeRequired(vi, k)<<endl;

    return 0;
}
