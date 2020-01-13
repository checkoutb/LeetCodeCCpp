
#include <bits/stdc++.h>
#include "../header/myheader.h"

using namespace std;            // ...

class LT0517
{
public:


    int lt0517b(vector<int>& machines)
    {
        int sum = std::accumulate(machines.begin(), machines.end(), 0);
        int sz1 = machines.size();
        if (sum % sz1 != 0)
            return -1;
        int avg2 = sum / sz1;

        int arr2[sz1] = {0};
        int arr1[sz1] = {0};
        int sum2 = 0;
        int t1 = 0;

        for (int i = 0; i < sz1; i++)
        {
            t1 += avg2;
            sum2 += machines[i];
            int n2 = 0;
            if (sum2 > t1)
            {
                int t2 = sum2 - t1;
                sum2 -= t2;
                n2 += t2;
                for (int j = i + 1; j < sz1 && t2 > 0; j++)
                {
                    if (machines[i] == 0)
                    {
                        n2++;
                    }
                    else if (machines[i] < avg2)
                    {
                        (if (avg2 - machines[i]) < t2)
                        {
                            machines[i] = avg2;
                            t2 -= (avg2 - machines[i]);
                        }
                        else
                        {
                            machines[i] += t2;
                            t2 = 0;
                            n2 += t2;
                        }
                    }
                }
            }
            else if (sum2 < t1)
            {

            }
        }

        return -2;
    }



// 116 / 120 tle
    int lt0517a(vector<int>& machines)
    {
        int sum = std::accumulate(machines.begin(), machines.end(), 0);
        int sz1 = machines.size();
        if (sum % sz1 != 0)
            return -1;
        int avg2 = sum / sz1;

        int asd = 0;

        int ans = 0;
        while (true)
        {

            #ifdef __test
            for_each(machines.begin(), machines.end(), fun_cout);
            cout<<endl;
            #endif // __test

            if (std::all_of(machines.begin(), machines.end(), [avg2](int i) { return i == avg2; }))
                break;
            int t1 = 0;     // i * avg
            sum = 0;
            int moved = -1;
            ans++;
            for (int i = 0; i < sz1 - 1; i++)
            {
                if (moved != i)
                    moved = -1;
                sum += machines[i];
                t1 += avg2;
                if (sum > t1)
                {
                    if (moved != i && machines[i] > avg2)
                    {
                        machines[i]--;
                        machines[i + 1]++;
                        sum--;
                    }
                }
                else if (sum < t1)
                {

                    machines[i]++;
                    machines[i + 1]--;
                    moved = i + 1;
                    sum++;
                }
            }

        }
        return ans;
    }
};

int main()
{
//    vector<int> v = {1,0,5};
//    vector<int> v = {0,3,0};
//    vector<int> v = {0,6,0};

    vector<int> v[] = {{1,0,5},{0,3,0},{0,6,0},{4,0,0,4}};
    vector<int> ans = {3,2,4,2};

    LT0517 lt;
    int i = 0;
    for (vector<int> v2 : v)
        cout<<lt.lt0517a(v2)<<" : "<<ans[i++]<<endl<<endl;

    return 0;
}
