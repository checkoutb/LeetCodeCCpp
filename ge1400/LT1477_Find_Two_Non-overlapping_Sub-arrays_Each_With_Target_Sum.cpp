
#include "../header/myheader.h"

class LT1477
{
public:

// D




// tle.
    int lt1477a(vector<int>& arr, int target)
    {
        int sz1 = arr.size();
        map<int, vector<int>> map2;           // length : {starts}
        for (int i = 0; i < sz1; ++i)
        {
            int sum2 = 0;
            for (int j = i; j < sz1; ++j)
            {
                sum2 += arr[j];
                if (sum2 == target)
                {
                    map2[j - i + 1].push_back(i);
                    break;
                }
                else if (sum2 > target)
                    break;
            }
        }
        int ans = INT_MAX;
        for (map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); ++it)
        {
            int len = it->first;
            if (len * 2 >= ans)
                break;
            vector<int>& vi = it->second;
            int t2 = vi[0] + len;
            int t3 = vi.size() > 1 ? vi[vi.size() - 1] : -1;
            if (t3 >= t2)
            {
                ans = min(ans, 2 * len);
            }
            else
            {
                t2 = vi[0];
                t3 = vi[vi.size() - 1];
                map<int, vector<int>>::iterator it2 = it;
                it2++;
                for (; it2 != map2.end(); ++it2)
                {
                    int len2 = it2->first;
                    if (len + len2 >= ans)
                        break;
                    vector<int>& vi2 = it2->second;
                    int e2 = vi2[0];
                    int e3 = vi2[vi2.size() - 1];
                    if ((e2 + len2 <= t3) || (t2 + len <= e3))
                    {
                        ans = min(ans, len + len2);
                        break;
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{
//    vector<int> v = {3,2,2,4,3};
//    int t{3};
//    vector<int> v = {7,3,4,7};
//    int t{7};
//    vector<int> v = {4,3,2,6,2,3,4};
//    int t{6};

    vector<int> v = {3,1,1,1,5,1,2,1};
    int t{3};

    LT1477 lt;

    cout<<lt.lt1477a(v, t);

    return 0;
}
