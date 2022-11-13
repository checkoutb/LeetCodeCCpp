
#include "../header/myheader.h"

class LT2462
{
public:

    // D D

    //priority_queue<int, vector<int>, greater<int>> pq1, pq2;





    //Runtime194 ms
    //    Beats
    //    93.42 %
    //    Memory72.7 MB
    //    Beats
    //    79.91 %
    long long lt2462a(vector<int>& costs, int k, int candidates)
    {
        int sz1 = costs.size();

        priority_queue<int, vector<int>, greater<int>> pri1;
        priority_queue<int, vector<int>, greater<int>> pri2;
        pri1.push(INT_MAX);
        pri2.push(INT_MAX);

        int st = 0;
        int en = sz1 - 1;
        long long ans = 0LL;

        for (int i = 0; i < candidates; ++i)
        {
            if (st <= en)
            {
                pri1.push(costs[st++]);
            }
            if (en >= st)
            {
                pri2.push(costs[en--]);
            }
        }

        while (k-- > 0)
        {
            if (pri1.top() <= pri2.top())
            {
                ans += pri1.top();
                pri1.pop();
                if (st <= en)
                    pri1.push(costs[st++]);
            }
            else
            {
                ans += pri2.top();
                pri2.pop();
                if (st <= en)
                    pri2.push(costs[en--]);
            }
        }
        return ans;
    }

};

int main()
{

    LT2462 lt;

    //myvi cst = { 17,12,10,2,7,2,11,20,8 };
    //int k = 3;
    //int cand = 4;

    myvi cst = { 1,2,4,1 };
    int k = 3;
    int cand = 3;

    cout << lt.lt2462a(cst, k, cand);

    return 0;
}
