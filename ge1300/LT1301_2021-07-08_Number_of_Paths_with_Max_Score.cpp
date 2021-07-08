
#include "../header/myheader.h"

class LT1301
{
public:

// D D



//        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
//        vector<vector<int>>sum(m+1,vector<int>(n+1,0));
//        sum[m-1][n-1]=1;
//        for(int i=m-1;i>=0;--i){
//            for(int j=n-1;j>=0;--j){
//                if(board[i][j]!='X'){
//                    int m=max(dp[i][j+1],max(dp[i+1][j],dp[i+1][j+1]));
//                    dp[i][j]=m+(board[i][j]-'0');
//                    if(dp[i][j+1]==m){
//                        sum[i][j]=(sum[i][j]+sum[i][j+1])%mod;
//                    }
//                    if(dp[i+1][j]==m){
//                        sum[i][j]=(sum[i][j]+sum[i+1][j])%mod;
//                    }
//                    if(dp[i+1][j+1]==m){
//                        sum[i][j]=(sum[i][j]+sum[i+1][j+1])%mod;
//                    }
//                }
// 从  右，下，右下  取最大值， 然后 判断这个最大值来自哪里。











//Runtime: 12 ms, faster than 82.70% of C++ online submissions for Number of Paths with Max Score.
//Memory Usage: 8.8 MB, less than 70.81% of C++ online submissions for Number of Paths with Max Score.
//
//E12
//1x1
//21S
// E23
// 2x2
// 12S
    vector<int> lt1301a(vector<string>& board)
    {
        int sz1 = board.size();
        vector<vector<pair<int, int>>> vvp(sz1, vector<pair<int, int>>(sz1, {-1, -1}));
        vvp[sz1 - 1][sz1 - 1].second = 1;
        vvp[sz1 - 1][sz1 - 1].first = 0;
        vvp[0][0].first = 0;
        vvp[0][0].second = 0;
        const int MOD = (int) 1E9 + 7;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (int j = sz1 - 1; j >= 0; --j)
            {
                if (vvp[i][j].first == -1)
                    continue;
                if (board[i][j] != 'X')
                {
                    int p1 = vvp[i][j].first;
                    int t3 = vvp[i][j].second;
                    int t2;
                    if (i - 1 >= 0)
                    {
                        t2 = p1 + geta1(board[i - 1][j]);
                        if (t2 > vvp[i - 1][j].first)
                        {
                            vvp[i - 1][j].first = t2;
                            vvp[i - 1][j].second = t3;
                        }
                        else if (t2 == vvp[i - 1][j].first)
                        {
                            vvp[i - 1][j].second = (t3 + vvp[i - 1][j].second) % MOD;
                        }
                    }
                    if (j - 1 >= 0)
                    {
                        t2 = p1 + geta1(board[i][j - 1]);
                        // i need for
                        if (t2 > vvp[i][j - 1].first)
                        {
                            vvp[i][j - 1].first = t2;
                            vvp[i][j - 1].second = t3;
                        }
                        else if (t2 == vvp[i][j - 1].first)
                        {
                            vvp[i][j - 1].second = (t3 + vvp[i][j - 1].second) % MOD;
                        }
                    }
                    if (i - 1 >= 0 && j - 1 >= 0)
                    {
                        t2 = p1 + geta1(board[i-1][j-1]);
                        if (t2 > vvp[i-1][j-1].first)
                        {
                            vvp[i-1][j-1].first = t2;
                            vvp[i-1][j-1].second = t3;
                        }
                        else if (t2 == vvp[i-1][j-1].first)
                        {
                            vvp[i-1][j-1].second = (t3 + vvp[i-1][j-1].second) % MOD;
                        }
                    }
                }
            }
        }
        #ifdef __test
        for (vector<pair<int, int>>& vp : vvp)
        {
            for (pair<int, int>& p : vp)
            {
                cout<<"("<<p.first<<", "<<p.second<<"), ";
            }
            cout<<endl;
        }
        #endif // __test
        return {vvp[0][0].first, vvp[0][0].second};
    }
    int geta1(char ch)
    {
        if (ch == 'E')
            return 0;
        return ch - '0';
    }

};

int main()
{
//    vector<string> vs = {"E23","2X2","12S"};
    vector<string> vs = {"E12","1X1","21S"};
//    vector<string> vs = {"E11","XXX","11S"};        // .

    LT1301 lt;

    myvi v = lt.lt1301a(vs);

    cout<<v[0]<<", "<<v[1]<<endl;

    return 0;
}
