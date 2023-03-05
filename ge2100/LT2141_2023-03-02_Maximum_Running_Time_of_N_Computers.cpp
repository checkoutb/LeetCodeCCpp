
#include "../header/myheader.h"

class LT2141
{
public:

    // D D


    //long long l = 0, r = accumulate(batteries.begin(), batteries.end(), 0LL) / n;
    //
    //while (l < r) {
    //    long long m = (l + r + 1) / 2, mins = 0;;
    //    for (auto& b : batteries) mins += min((long long)b, m);
    //    if (mins >= n * m) l = m;
    //    else r = m - 1;
    //}
    //
    //return l;
    // 
    // ？？？？？？？？？？？？？？？？？？？？？？？？？？？
    // 。。 这里的思路就是 如果电量 大于 m，则 只能算 m。 


    //bool isPossible(vector<int>& batteries, long long time, int computers) {
    //    long long totTime = time * computers;

    //    for (long long bTime : batteries)
    //        totTime -= min(time, bTime);

    //    return (totTime <= 0);//if entire charge for all computers is drained, then we used all batteries, so it's a possible solution
    //}



    //sort(A.begin(), A.end());
    //long long sum = accumulate(A.begin(), A.end(), 0L);
    //int k = 0, na = A.size();
    //while (A[na - 1 - k] > sum / (n - k))
    //    sum -= A[na - 1 - k++];
    //return sum / (n - k);
    // 
    // ?????????????!!!!!!!!!!!!!!!!!!!!!


    //long long sum = accumulate(begin(bat), end(bat), 0LL);
    //priority_queue<int> pq(begin(bat), end(bat));
    //while (pq.top() > sum / n) {
    //    sum -= pq.top(); pq.pop();
    //    --n;
    //}
    //return sum / n;


    //Runtime270 ms
    //    Beats
    //    21.34 %
    //    Memory55.9 MB
    //    Beats
    //    22.56 %
    // topic : binary search.  原以为是dp。
    long long lt2141a(int n, vector<int>& batteries)
    {
        int sz1 = batteries.size();

        long long sum2 = std::accumulate(begin(batteries), end(batteries), 0LL);
        sort(begin(batteries), end(batteries));

        //vector<long long> v2(begin(batteries), end(batteries));

        //vector<long long> vll(sz1);
        //vll[0] = batteries[i];
        //for (int i = 1; i < sz1; ++i)
        //{
        //    vll[i] = vll[i - 1] + batteries[i];
        //}
        //sum2 = vll[sz1 - 1];

        long long st = 0LL, en = sum2 / n;
        long long ans = -1LL;
        while (st <= en)
        {
            long long md = (st + en) / 2;
            int cnt = 0;
            long long need = -1;
            int t2 = 0;
            for (int i = sz1 - 1; i >= 0 && cnt < n; )
            {
                if (batteries[i] - t2 >= md)
                {
                    ++cnt;
                    --i;
                }
                else
                {
                    need = md - batteries[i] + t2;
                    --i;
                    while (i >= 0 && need > batteries[i])
                    {
                        need -= batteries[i];
                        --i;
                    }
                    if (i >= 0)
                    {
                        t2 = need;
                        ++cnt;

                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (cnt >= n)
            {
                st = md + 1;
                ans = md;
            }
            else
            {
                en = md - 1;
            }


            //vector<long long>::iterator it = lower_bound(begin(v2), end(v2), md);
            //int idx = 0;
            //int need = 0;
            //if (md > 1000000000)
            //{
            //    idx = sz1 - 1;
            //    need = sz1;
            //}
            //else
            //{
            //    idx = std::distance(begin(batteries), lower_bound(begin(batteries), end(batteries), md));
            //    need = sz1 - idx;
            //}


        }
        return ans;
    }

};

int main()
{

    LT2141 lt;

    int n = 2;
    myvi vi = { 3,3,3 };

    cout << lt.lt2141a(n, vi) << endl;

    return 0;
}
