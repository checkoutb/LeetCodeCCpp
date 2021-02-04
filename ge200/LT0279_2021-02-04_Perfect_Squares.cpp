
#include "../header/myheader.h"

class LT0279
{
public:

// D

//    static vector<int> dp {0};
//    while (dp.size() <= n) {
//        int m = dp.size(), squares = INT_MAX;
//        for (int i=1; i*i<=m; ++i)
//            squares = min(squares, dp[m-i*i] + 1);
//        dp.push_back(squares);
//    }
//    return dp[n];


//    static vector<int> dp {0};
//    int m = dp.size();
//    dp.resize(max(m, n+1), INT_MAX);
//    for (int i=1, i2; (i2 = i*i)<=n; ++i)
//        for (int j=max(m, i2); j<=n; ++j)
//            if (dp[j] > dp[j-i2] + 1)
//                dp[j] = dp[j-i2] + 1;
//    return dp[n];


//    while (n % 4 == 0)
//        n /= 4;
//    if (n % 8 == 7)
//        return 4;
//    int a = -1, b = sqrt(n);
//    n -= b * b;
//    b += b + 1;
//    while (a <= b) {
//        if (n < 0)
//            n += b -= 2;
//        else if (n > 0)
//            n -= a += 2;
//        else
//            return a < 0 ? 1 : 2;
//    }
//    return 3;



// 502/588   7168   tle.
    int lt0279c(int n)
    {
        vector<int> vi;
        for (int i = 1, mxi = std::sqrt(n); i <= mxi; ++i)
            vi.push_back(i * i);
        std::reverse(begin(vi), end(vi));
        ansc = n;
        dfsc1(n, 0, 0, vi);
        return ansc;
    }
    int ansc = INT_MAX;
    void dfsc1(int n, int cnt, int vist, vector<int>& vi)
    {
        if (cnt >= ansc)
            return;
        if (n == 0)
        {
            ansc = cnt;
            return;
        }
        for (int i = vist; i < vi.size(); ++i)
        {
            if (vi[i] <= n)
            {
                if (vi[i] == 1 && cnt == 0)
                    return;
                int re = n - vi[i];
                int ct = 1;
                while (re >= 0)
                {
                    dfsc1(re, cnt + ct, vist + 1, vi);
                    re -= vi[i];
                    ct++;
                }
                dfsc1(n, cnt, vist + 1, vi);
                break;
            }
        }

    }


// 19 = 2*9 + 1...
    int lt0279b(int n)
    {
        vector<int> vi;
        for (int i = 1, mxi = std::sqrt(n); i <= mxi; ++i)
            vi.push_back(i * i);
        std::reverse(begin(vi), end(vi));
        int ans = 0;
        while (n > 0)
        {
            int fst = -1;
            for (int i = 0; i < vi.size(); ++i)
            {
                if (n % vi[i] == 0 && i != vi.size() - 1)
                {
                    ans += n / vi[i];
                    goto AAA;
                }
                if (fst == -1 && n >= vi[i])
                {
                    fst = vi[i];
                }
            }
            ans++;
            n -= fst;
        }
        AAA:
        return ans;
    }


// 感觉好像是： 如果能被 某个平方整除(除了1)，那么就肯定是， 如果不行，那么就取最大。
    int lt0279a(int n)
    {
        vector<int> vi;
        for (int i = 1, mxi = std::sqrt(n); i <= mxi; ++i)
        {
            vi.push_back(i * i);
        }
        std::reverse(begin(vi), end(vi));
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        dfsa1(n, 0, vi);
        return ans;
    }
    int ans = INT_MAX;
//    int arr[] = {1,4,9,16,25,36,49,64,81,100,121}
    void dfsa1(int remain, int cnt, vector<int>& vi)
    {
        if (cnt >= ans)
            return;
        if (remain == 0)
        {
            ans = min(ans, cnt);
            return;
        }
        for (int i = 0; i < vi.size(); ++i)
        {
            if (vi[i] <= remain)
            {
                dfsa1(remain - vi[i], cnt + 1, vi);
                dfsa1(remain, cnt, vi);
                break;
            }
//            if (vi[i] <= remain)
//            {
//                int re = remain - vi[i];
//                int c2 = 1;
//                while (re >= 0)
//                {
//                    dfsa1(re, cnt + c2, vi);
//                    c2++;
//                    re -= vi[i];
//                }
//                dfsa1(remain, cnt, vi);
//            }
        }
    }

};

int main()
{
    myvi v = {12,13,19};
//    myvi v = {1};

    LT0279 lt;

    for (int i : v)
        cout<<lt.lt0279c(i)<<endl;

    return 0;
}
