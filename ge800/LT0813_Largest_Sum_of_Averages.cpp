
#include "../header/myheader.h"

class LT0813
{
public:


// gg
// D
// memo。 memo[i+1][1] = curSum/(i+1).    curSum是从0到现在的和。 意思就是 前i+1个数 是 1个组，的最大 avg。
// dfs的时候 memo[n][k] = max(memo[n][k], search(i, k - 1, A) + cur / (n - i));       i是从后向前遍历的。


// error
    double lt0813c(vector<int>& A, int K)
    {
        vector<int> v2(A.begin(), A.end());
        std::sort(v2.begin(), v2.end());
        set<int> set2;
        for (int i = 1; i <= K; i++)
        {
            set2.insert(v2[v2.size() - i]);
        }
        vector<int> vindex;
        for (int i = 0; i < A.size(); i++)
        {
            if (set2.find(A[i]) != set2.end())      // ...得最大的优先呐。。
                vindex.push_back(i);
        }
        return -1;
    }

    double avgc1(vector<int>& a, int i, int j)
    {
        int sum = std::accumulate(a.begin() + i, a.begin() + j + 1, 0);
        return 1.0 * sum / (j - i + 1);
    }

// 41/51 tle
    double lt0813b(vector<int>& A, int K)
    {
        double ans = 0.0;

        vector<vector<double>> vv(A.size(), vector<double>(A.size()));
        for (int i = 0; i < A.size(); i++)
        {
            int sum = 0;
            int cnt = 0;
            for (int j = i; j < A.size(); j++)
            {
                sum += A[j];
                cnt++;
                vv[i][j] = 1.0 * sum / cnt;
            }
        }
        ans = dfsb1(A, vv, K, 0, 0.0);

        return ans;
    }

    double MXC = -10.0;

    double dfsb1(vector<int>& a, vector<vector<double>>& vv, int K, int i, double now)
    {
        if (i >= a.size())
            return MXC;
        if (K == 1)
        {
            now += vv[i][a.size() - 1];
            return now;
        }
        double ans = -1.0;
        for (int j = i; j <= a.size() - K; j++)
        {
            ans = std::max(ans, dfsb1(a, vv, K - 1, j + 1, now + vv[i][j]));
        }
        return ans;
    }

// 最大的K-1个数 各自为一组，然后剩下的。。 不， 6，9，1，2，3 分2组。
    double lt0813a(vector<int>& A, int K)
    {
        vector<int> v2(A.begin(), A.end());
        std::sort(v2.begin(), v2.end());
        return -1.0;
    }

};

int main()
{

    vector<int> a = {9,1,2,3,9};
    int k = 3;

    LT0813 lt;

    cout<<lt.lt0813b(a, k)<<endl;

    return 0;
}
