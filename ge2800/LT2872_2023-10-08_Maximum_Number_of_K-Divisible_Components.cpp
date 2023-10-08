
#include "../header/myheader.h"

class LT2872
{
public:

// D D



//Runtime353 ms
//Beats
//73.70%
//Memory176.1 MB
//Beats
//68.76%
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k)
    {
        vector<vector<int>> vvi(n);
        for (vector<int>& vi : edges)
        {
            vvi[vi[0]].push_back(vi[1]);
            vvi[vi[1]].push_back(vi[0]);
        }
        int ans = 0;
        dfsa1(vvi, values, 0, -1, k, ans);
        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, vector<int>& values, int node, int parent, int k, int& ans)
    {
//        vector<int> vi;
        long long sum2 = values[node];
        for (int nxt : vvi[node])
        {
            if (nxt != parent)
            {
                int t2 = dfsa1(vvi, values, nxt, node, k, ans);
                sum2 += t2;
//                if (t2 != 0)
//                    vi.push_back(t2);
            }
        }

        if (sum2 % k == 0)
        {
            ++ans;
            return 0;
        }
        else
        {
            return sum2 % k;
        }

//        if (vi.empty())
//        {
//            if (values[node] % 3 == 0)
//            {
//                ++ans;
//                return 0;
//            }
//            else
//            {
//                return values[node] % 3;
//            }
//        }

//        int sum2 = reduce(begin(vi), end(vi));
//        sum2 +=

//        sort(begin(vi), end(vi));
//        if (vi[vi.size() - 1] == 0)
//        {
//            ans += vi.size();
//            if (values[node] % 3 == 0)
//            {
//                ++ans;
//            }
//            return values[node] % 3;
//        }
//        else if (vi[vi.size() - 2] == 0)
//        {
//            ans += vi.size() - 1;
//            if ((values[node] + vi[vi.size() - 1]) % 3 == 0)
//                ++ans;
//            return (values[node] + vi[vi.size() - 1]) % 3;
//        }
//        else
//        {
//
//        }
    }
};

int main()
{

    LT2872 lt;

    myvvi vv = {{0,2},{1,2},{1,3},{2,4}};
    myvi v = {1,8,1,4,4};
    int k = 6;
    int n = 5;

    cout<<lt.maxKDivisibleComponents(n, vv, v, k)<<endl;

    return 0;
}
