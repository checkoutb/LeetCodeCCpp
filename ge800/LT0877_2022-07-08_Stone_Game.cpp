
#include "../header/myheader.h"

class LT0877
{
public:

    // D D

    // return true...


    //Alex is first to pick pile.
    //    piles.length is even, and this lead to an interesting fact :
    //Alex can always pick odd piles or always pick even piles!



    //dp[i][j] means the biggest number of stones you can get more than opponent picking piles in piles[i] ~piles[j].
    //    You can first pick piles[i] or piles[j].

    //    If you pick piles[i], your result will be piles[i] - dp[i + 1][j]
    //    If you pick piles[j], your result will be piles[j] - dp[i][j - 1]

    //    So we get :
    //dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1])

    //int n = p.size();
    //vector<vector<int>> dp(n, vector<int>(n, 0));
    //for (int i = 0; i < n; i++) dp[i][i] = p[i];
    //for (int d = 1; d < n; d++)
    //    for (int i = 0; i < n - d; i++)
    //        dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);
    //return dp[0][n - 1] > 0;

    // 。。。。。。


    //vector<int> dp = p;
    //for (int d = 1; d < p.size(); d++)
    //    for (int i = 0; i < p.size() - d; i++)
    //        dp[i] = max(p[i] - dp[i + 1], p[i + d] - dp[i]);
    //return dp[0] > 0;




    //For stones in piles[left]...piles[right], there are 2 choices for the player1 to pick :

    //Pick left : pickLeft = dp(left + 1, right).
    //    The score of the player1 = piles[left] + the second pick score from pickLeft, so firstScore = piles[left] + pickLeft[1]
    //    The score of the player2 = first pick score from pickLeft, so secondScore = pickLeft[0]
    //    Pick right : pickRight = dp(left, right - 1).
    //    The score of the player1 = piles[right] + the second pick score from pickRight, so firstScore = piles[right] + pickRight[1]
    //    The score of the player2 = first pick score from pickRight, so secondScore = pickRight[0].

    //    We need to get the maximum score when the player1 plays first from above 2 choices.



    //pair<int, int> dp(vector<int>& piles, int left, int right) {
    //    if (left > right) return make_pair(0, 0);
    //    if (memo[left][right].first != 0) return memo[left][right];

    //    pair<int, int> leftPick = dp(piles, left + 1, right);
    //    pair<int, int> rightPick = dp(piles, left, right - 1);
    //    if (piles[left] + leftPick.second > piles[right] + rightPick.second) { // If the left choice has higher score than the right choice
    //        return memo[left][right] = make_pair(piles[left] + leftPick.second, leftPick.first); // then pick left
    //    }
    //    return memo[left][right] = make_pair(piles[right] + rightPick.second, rightPick.first); // else pick right
    //}









    // �訌忘楙叩�
//Runtime: 42 ms, faster than 21.07 % of C++ online submissions for Stone Game.
//Memory Usage : 16.5 MB, less than 12.89 % of C++ online submissions for Stone Game.
    bool lt0877a(vector<int>& piles)
    {
        int sz1 = piles.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));

        vector<int> psum(begin(piles), end(piles));
        for (int i = 1; i < sz1; ++i)
        {
            psum[i] += psum[i - 1];
        }

        for (int len = 1; len <= sz1; ++len)
        {
            for (int i = 0; i + len <= sz1; ++i)
            {
                if (len == 1)
                {
                    vvi[i][i] = piles[i];
                    continue;
                }

                int st = i;
                int en = st + len - 1;
                int t2 = psum[en] - (st == 0 ? 0 : psum[st - 1]);

                if (len % 2)    // bob
                {
                    vvi[st][en] = max(vvi[st][en], max(piles[st] + (psum[en] - psum[st]) - vvi[st + 1][en], piles[en] + (psum[en - 1] - (st == 0 ? 0 : psum[st - 1]))));
                }
                else
                {
                    vvi[st][en] = max(vvi[st][en], max(piles[st] + (psum[en] - psum[st]) - vvi[st + 1][en], piles[en] + (psum[en - 1] - (st == 0 ? 0 : psum[st - 1]))));
                }
            }
        }
        return vvi[0][sz1 - 1] > (psum[sz1 - 1] - vvi[0][sz1 - 1]);
    }

};

int main()
{

    LT0877 lt;

    //myvi v = { 5,3,4,5 };
    myvi v = { 3,7,2,3 };

    cout << lt.lt0877a(v) << endl;

    return 0;
}
