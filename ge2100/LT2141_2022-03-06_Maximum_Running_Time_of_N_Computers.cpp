
#include "../header/myheader.h"

class LT2141
{
public:



// g


// 2 [3,3,3] ...
// 先用电量最多的。
    long long lt2141a(int n, vector<int>& batteries)
    {
        std:;sort(begin(batteries), end(batteries));
        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> priq;
        int idx = batteries.size() - 1;
        while (priq.size() < n)
        {
            priq.push(batteries[idx--]);
        }
        while (idx >= 0)
        {
            int mn = priq.top();
            priq.pop();
            priq.push(mn + batteries[idx--]);
        }
        ans = priq.top();
        return ans;
    }

};

int main()
{

    LT2141 lt;




    return 0;
}
