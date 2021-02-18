
#include "../header/myheader.h"

class LT1510
{
public:


// D D

//        vector<bool> dp(n + 1, false);
//        for (int i = 0; i <= n; i++) {
//            if (dp[i]) {
//                continue;
//            }
//            for (int k = 1; i + k * k <= n; k++) {
//                dp[i + k * k] = true;
//            }
//        }
//        return dp[n];


//    static int win(int n, vector<int>& dp) {
//        if(dp[n] != -1) return dp[n];
//
//        for(int i = static_cast<int>(sqrt(n)); i > 0; --i)
//            if(!win(n-i*i, dp))
//                return dp[n] = 1;
//
//        return dp[n] = 0;
//    }
//public:
//    bool winnerSquareGame(int n) {
//        vector<int> dp(n+1, -1);
//
//        dp[0] = 0;
//
//        return win(n, dp);
//    }



//if there is any k that dp[i - k * k] == false,
//it means we can make the other lose the game,
//so we can win the game an dp[i] = true.

//        vector<bool> dp(n + 1, false);
//        for (int i = 1; i <= n; ++i) {
//            for (int k = 1; k * k <= i; ++k) {
//                if (!dp[i - k * k]) {
//                    dp[i] = true;
//                    break;
//                }
//            }
//        }
//        return dp[n];


//class Solution:
//    def winnerSquareGame(self, n):
//
//        @lru_cache(None)
//        def dfs(state):
//            if state == 0: return False
//            for i in range(1, int(math.sqrt(state))+1):
//                if not dfs(state - i*i): return True
//            return False
//
//        return dfs(n)
// python,   3?


//    Map<Integer, Boolean> map = new HashMap<>();
//    public boolean winnerSquareGame(int n) {
//        if (n == 0) return false;
//        if (map.containsKey(n)) return map.get(n);
//        boolean res = false;
//        for (int i = 1; i * i <= n; i++) {
//            if (!winnerSquareGame(n - i * i)) {
//                res = true;
//                break;
//            }
//        }
//        map.put(n, res);
//        return res;
//    }


//Runtime: 92 ms, faster than 56.56% of C++ online submissions for Stone Game IV.
//Memory Usage: 6.4 MB, less than 70.65% of C++ online submissions for Stone Game IV.
// 71 / 72   74497   tle
    bool lt1510a(int n)
    {
        vector<bool> vb(n + 1, false);      // number of stone (alice / bob) : can win
        vb[1] = true;
        vector<int> squ;
        for (int i = 1; i * i <= n; ++i)
        {
            squ.push_back(i * i);
        }
        #ifdef __test
//        showVectorInt(squ);
        #endif // __test
        bool flg = false;
        for (int i = 2; i <= n; ++i)
        {
//            vector<int>::iterator it = std::lower_bound(begin(squ), end(squ), i);       // is square?
//            if (*it == i)
//            {
//                vb[i] = win;
//                continue;
//            }

            bool win = false;
            for (int j = 0; j < squ.size(); ++j)
            {
                if (i - squ[j] < 0)
                    break;

                int bob = i - squ[j];       // bob's stone
                if (bob == 0)
                {
                    win = true;
                    break;
                }

                // add, because tle.
                if (vb[bob] == false)
                {
                    win = true;
                    break;
                }
                // add end

                // delete, because tle.
//                bool allalicewin = true;
//                for (int k = 0; k < squ.size(); ++k)
//                {
//                    if (bob - squ[k] < 0)
//                        break;
//                    if (vb[bob - squ[k]] == false)
//                    {
//                        allalicewin = false;
//                        break;
//                    }
//                }
//
//                if (allalicewin)
//                {
//                    win = true;
//                    break;
//                }
                // delete end


//                if (vb[i - squ[j]] == flg)
//                {
//                    #ifdef __test
////                    cout<<"    "<<(i - squ[j])<<endl;
//                    #endif // __test
//                    win = true;
//                    break;
//                }
            }
            vb[i] = win;
//            flg = !flg;
        }
        #ifdef __test
//        for (bool b : vb)
//            cout<<b<<", ";
//        cout<<endl;
        #endif // __test
        return vb[n];
    }

};

int main()
{
    myvi v = {1,2,4,7,17,74497};

    LT1510 lt;

    for (int i : v)
        cout<<lt.lt1510a(i)<<endl<<endl<<endl;

    return 0;
}
