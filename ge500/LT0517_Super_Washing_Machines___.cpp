
#include "../header/myheader.h"

class LT0517
{
public:

// gg...
    int lt0517b(vector<int>& machines)
    {
        int sum2 = std::accumulate(machines.begin(), machines.end(), 0);
        int sz1 = machines.size();
        if (sum2 % sz1 != 0)
            return -1;
        int avg = machines[0];
        sum2 = 0;
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            sum2 += machines[i];
            if (avg == sum2 / (i + 1))
                continue;
            avg = sum2 / (i + 1);
            ans += std::abs(machines[i] - avg);
        }
        return ans;
    }

    // error
    int lt0517a(vector<int>& machines)
    {
        int sum2 = std::accumulate(machines.begin(), machines.end(), 0);
        int sz1 = machines.size();
        if (sum2 % sz1 != 0)
            return -1;
        int t1 = sum2 / sz1;
        int t2 = 0;
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (machines[i] < t1)
            {
                if (t2 > 0)
                {
                    int n2 = t1 - machines[i];
                    int n3 = std::max(n2, t2);
                    t2 = 0;
                }
                else
                {
                    int n2 = t1 - machines[i];
                    int n3 = n2;
                    for (int j = i + 1; j < sz1 && n2 > 0; j++)
                    {
                        if (machines[j] > 0)
                        {
                            if (machines[j] > n2)
                            {
                                machines[j] -= n2;
                                n2 = 0;
                            }
                            else
                            {
                                n2 -= machines[j];
                                machines[j] = 0;
                            }
                        }
                        else
                        {
                            n3++;
                        }
                    }
                    ans = std::max(ans, n3);
                }
            }
        }
    }
};

int main()
{
    vector<int> v = {4,0,0,4};

    LT0517 lt;
    cout<<lt.lt0517b(v)<<endl;

    return 0;
}
