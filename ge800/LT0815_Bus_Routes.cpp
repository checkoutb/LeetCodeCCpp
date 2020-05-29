
#include "../header/myheader.h"

class LT0815
{
public:



// discuss, map:stop->bus   routes[bus].clear   queue<pair<int, int>>



// 43/45  tle
// 不过10^6 有点大。 1e6个int要3mb多。。还要作一个转换。 估计tle。。
    int lt0815a(vector<vector<int>>& routes, int S, int T)
    {
        if (S == T)
            return 0;
//        int arr[1000000] = {0};
        int mxc = -1;
        map<int, unordered_set<int>> map2;
        for (vector<int> v : routes)
        {
            for (int i : v)
            {
                map2[i].insert(v.begin(), v.end());
                mxc = std::max(mxc, i);
            }
        }

        vector<int> arr(mxc + 1, 0);        // +1
//        int ans = 0;
        queue<int> que2;
        que2.push(-1);
        que2.push(S);
        while (!arr[T] && que2.size() > 1)
        {
            int t2 = que2.front();
            que2.pop();
            if (t2 == -1)
            {
//                ans++;
                que2.push(-1);
                continue;
            }
            int t3 = arr[t2] + 1;
            for (int i : map2[t2])
            {
                if (i != t2 && arr[i] == 0)
                {
                    arr[i] = t3;
                    que2.push(i);
                }
            }
        }
        return arr[T] == 0 ? -1 : arr[T];
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2,7},{3,6,7}};
    int s = 1;
    int t = 6;

    LT0815 lt;

    cout<<lt.lt0815a(vv, s, t)<<endl;

    return 0;
}
