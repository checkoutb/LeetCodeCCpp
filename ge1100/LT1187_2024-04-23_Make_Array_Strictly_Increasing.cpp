
#include "../header/myheader.h"

class LT1187
{
public:




    // g


    // + map2, tle...
    // tle
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2)
    {
        sort(begin(arr2), end(arr2));
        vector<map<long long, int>> map2(arr1.size());
        int ans = dfsa1(arr1, arr2, 0, 0, 0, -1, map2);
        return ans == INT_MAX ? -1 : ans;
    }

    int dfsa1(vector<int>& v1, vector<int>& v2, int idx1, int idx2, int chg, int prev, vector<map<long long, int>>& map2)
    {
        if (idx1 == v1.size())
            return chg;

        long long k2 = chg;
        k2 <<= 31;
        k2 += prev;
        if (map2[idx1].contains(k2))
            return map2[idx1][k2];

        // if (!map2[idx1].empty() && map2[idx1].begin()->first < k2 && map2[idx1].begin()->second != INT_MAX)      // error
        //     return INT_MAX;

        while (idx2 < v2.size() && v2[idx2] <= prev)
            ++idx2;

        if (v1[idx1] > prev)
        {
            int t2 = dfsa1(v1, v2, idx1 + 1, idx2, chg, v1[idx1], map2);
            if (idx2 != v2.size() && v2[idx2] < v1[idx1])
                t2 = min(t2, dfsa1(v1, v2, idx1 + 1, idx2, chg + 1, v2[idx2], map2));

            map2[idx1][k2] = t2;
            return t2;
        }
        else
        {
            if (idx2 == v2.size())
            {
                map2[idx1][k2] = INT_MAX;
                return INT_MAX;
            }

            int t2 = dfsa1(v1, v2, idx1 + 1, idx2, chg + 1, v2[idx2], map2);
            map2[idx1][k2] = t2;
            return t2;
        }
    }
};

int main()
{

    LT1187 lt;


    return 0;
}
