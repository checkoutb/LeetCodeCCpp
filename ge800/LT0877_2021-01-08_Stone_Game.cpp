
#include "../header/myheader.h"

class LT0877
{
public:


// D
//        vector<int> dp = p;
//        for (int d = 1; d < p.size(); d++)
//            for (int i = 0; i < p.size() - d; i++)
//                dp[i] = max(p[i] - dp[i + 1], p[i + d] - dp[i]);
//        return dp[0] > 0;

//        for (int i = 0; i < n; i++) dp[i][i] = p[i];
//        for (int d = 1; d < n; d++)
//            for (int i = 0; i < n - d; i++)
//                dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);

// 至少知道边界怎么弄了。。。


//Alex is first to pick pile.
//piles.length is even, and this lead to an interesting fact:
//Alex can always pick odd piles or always pick even piles!



// gg
// 感觉最近几天的有道题挺像的， 就是那道  减去 [1，N)的因子。不过那个是单端的。
// 这个有2端。 当alex作出第一个选择后，无论lee选哪端，最终都是输。
// 但。。dp不来啊
// dfs，当是alex的回合，只需要存在一个， 当lee的回合，必须全部堵死
// 在对方的最优选择上作出 我的最优选择。
    bool lt0877a(vector<int>& piles)
    {
        int sz1 = piles.size();
        vector<vector<pair<int, int>>> vv(sz1, vector<pair<int, int>>(sz1));
        for (int i = 0; i < sz1; ++i)
            vv[i][i].second = piles[i];
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
//                int diff = 0;
                if ((j - i) % 2 == 1)       // alex
                {
                    int alex1 = vv[i][j - 1].first;
                    int lee1 = vv[i][j - 1].second;
                    alex1 += piles[j];
                    int d1 = alex1 - lee1;

                    int alex2 = vv[i + 1][j].first;
                    int lee2 = vv[i + 1][j].second;
                    alex2 += piles[i];
                    int d2 = alex2 - lee2;

                    if (d1 > d2)
                    {
                        vv[i][j].first = alex1;
                        vv[i][j].second = lee1;
                    }
                    else
                    {
                        vv[i][j].first = alex2;
                        vv[i][j].second = lee2;
                    }

                }
                else
                {
                    int a1 = vv[i][j - 1].first;
                    int l1 = vv[i][j - 1].second;
                    l1 += piles[j];
                    int d1 = l1 - a1;

                    int a2 = vv[i + 1][j].first;
                    int l2 = vv[i + 1][j].second;
                    l2 += piles[i];
                    int d2 = l2 - a2;

                    if (d1 > d2)
                    {
                        vv[i][j].first = a1;
                        vv[i][j].second = l1;
                    }
                    else
                    {
                        vv[i][j].first = a2;
                        vv[i][j].second = l2;
                    }
                }
//                vv[i][j] = max();
            }
        }
//        for (int j = i - 1; j >= 0; --j)
//        {
//
//        }
        #ifdef __test
        for (vector<pair<int, int>>& vp : vv)
        {
            for (pair<int, int>& p : vp)
            {
                cout<<"{"<<p.first<<","<<p.second<<"}, ";
            }
            cout<<endl;
        }
        #endif // __test
        return vv[0][sz1 - 1].first > vv[0][sz1 - 1].second;
    }
//    // alex, lee
//    pair<int, int> dfsa1(vector<int>& vi, bool isAlex, int st, int en)
//    {
//        if (st > en)
//            return {0,0};
//
//    }

};

int main()
{
    myvi v = {5,3,4,5};
//    myvi v = {1,2};

    LT0877 lt;

    cout<<lt.lt0877a(v);

    return 0;
}
