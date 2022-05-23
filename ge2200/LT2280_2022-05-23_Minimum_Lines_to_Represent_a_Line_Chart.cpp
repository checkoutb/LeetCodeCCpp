
#include "../header/myheader.h"

class LT2280
{
public:

// D D

//        if(n == 1)
//            return 0;
//        sort(stockPrices.begin(), stockPrices.end());
//        for(int i = 1; i < n - 1; i++) {
//            if(1LL * (stockPrices[i - 1][1] - stockPrices[i][1]) * (stockPrices[i][0] - stockPrices[i + 1][0]) != 1LL * (stockPrices[i][1] - stockPrices[i + 1][1]) * (stockPrices[i - 1][0] - stockPrices[i][0]))
//                ans++;
//        }


//[[1,1],[500000000,499999999],[1000000000,999999998]]
//python float precision
//499999998 / 499999999 == 499999999 / 500000000
//True
//might need things like Fraction(499999998, 499999999 ) == Fraction(499999999, 500000000)
// haha,python翻车了。


//    int cnt = 0, dx = INT_MIN, dy = INT_MIN;
//    sort(begin(p), end(p));
//    for (int i = 1; i < p.size(); ++i) {
//        int dx1 = p[i][0] - p[i - 1][0], dy1 = p[i][1] - p[i - 1][1], d = gcd(dx1, dy1);
//        cnt += dx != dx1 / d || dy != dy1 / d;
//        dx = dx1 / d;
//        dy = dy1 / d;
//    }
//    return cnt;



//Runtime: 680 ms, faster than 33.33% of C++ online submissions for Minimum Lines to Represent a Line Chart.
//Memory Usage: 114.4 MB, less than 33.33% of C++ online submissions for Minimum Lines to Represent a Line Chart.
// 斜率，并且 4/2 == 2/1
// a/b=c/d <=> ad=cb&&bd!=0
// 一个点，ans==0？      yes.
    int lt2280a(vector<vector<int>>& stockPrices)
    {
        std::sort(begin(stockPrices), end(stockPrices));
        vector<pair<long, long>> vp;
        for (int i = 1; i < stockPrices.size(); ++i)
        {
            vp.emplace_back(1L * (stockPrices[i][0] - stockPrices[i - 1][0]), 1L * (stockPrices[i][1] - stockPrices[i - 1][1]));
        }
        int ans = vp.size();
        for (int i = 1; i < vp.size(); ++i)
        {
            if (vp[i].first * vp[i-1].second == vp[i].second * vp[i-1].first)
            {
                ans--;
            }
        }
        return ans;
    }

//    bool eq(pair<int, int>& p1, pair<int, int>& p2)
//    {
//
//    }

//    int gcd(int a, int b) {
//        if (b == 0)
//            return a;
//        return gcd(b, a % b);
//    }

};

int main()
{

    LT2280 lt;


    return 0;
}
