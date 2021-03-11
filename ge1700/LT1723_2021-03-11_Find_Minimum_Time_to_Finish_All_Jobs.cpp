
#include "../header/myheader.h"

class LT1723
{
public:




// tle
    int lt1723a(vector<int>& jobs, int k)
    {
        int sz1 = jobs.size();
//        ans = 2 * *max_element(begin(jobs), end(jobs));
        vector<int> times(k, 0);
        times[0] = jobs[0];
        dfsa1(jobs, 1, times);
        return ans;
    }

    int ans = INT_MAX;

    void dfsa1(vector<int>& jobs, int i, vector<int>& times)
    {
        if (i == jobs.size())
        {
            int mx = *max_element(begin(times), end(times));
            #ifdef __test
            cout<<ans<<", "<<mx<<endl;
            #endif // __test
            ans = min(ans, mx);
            return;
        }
        int v = jobs[i];
        for (int j = 0; j < times.size(); ++j)
        {
            if (times[j] + v > ans)
                continue;
            times[j] += v;
            dfsa1(jobs, i + 1, times);
            times[j] -= v;
        }
    }

};

int main()
{
//    myvi v = {3,2,3};
//    int k = 3;

//    myvi v = {1,2,4,7,8};
//    int k = 2;

//[4345079,7190302,6957449,5605110]
//1

//[9899456,8291115,9477657,9288480,5146275,7697968,8573153,3582365,3758448,9881935,2420271,4542202]
//9


    LT1723 lt;

    cout<<lt.lt1723a(v, k);

    return 0;
}
