
#include "../header/myheader.h"

class LT2028
{
public:


//        int x = sum / n;
//        vector<int> ans(n, x);
//        sum %= n;
//        for (int i = 0; i < sum; i++)
//            ans[i]++;



//Runtime: 255 ms, faster than 40.59% of C++ online submissions for Find Missing Observations.
//Memory Usage: 148.4 MB, less than 5.07% of C++ online submissions for Find Missing Observations.
// 6面色子，1-6
// n+m 次摇色子 n次丢失，m次看到，知道n+m 次的平均值。
// 确切等于，
    vector<int> lt2028a(vector<int>& rolls, int mean, int n)
    {
        int sz1 = rolls.size();         // m
        int sum2 = std::accumulate(begin(rolls), end(rolls), 0);   // sum(m)
        int sum3 = mean * (n + sz1);     // sum(m+n)
        int sum4 = sum3 - sum2;     // sum(n)
        vector<int> ans;
        if (sum4 > 6 * n || sum4 < n)
            return ans;

        dfsa1(sum4, n, ans);
        return ans;
    }

    void dfsa1(int need, int cnt, vector<int>& ans)
    {
        if (cnt == 0)
            return;

        int val = need - cnt + 1;       // others are all 1.
        if (val > 6)
            val = 6;
        ans.push_back(val);
        dfsa1(need - val, cnt - 1, ans);
    }


};

int main()
{

    LT2028 lt;

    myvi v = {3,2,4,3};
    int mean = 4;
    int n = 2;

    showVectorInt(lt.lt2028a(v, mean, n));

    return 0;
}
