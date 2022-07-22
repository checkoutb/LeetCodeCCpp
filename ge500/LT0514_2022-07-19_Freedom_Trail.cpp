
#include "../header/myheader.h"

class LT0514
{
public:

    // D D

    //int m = r.length(), n = key.length(), dp[][] = new int[n + 1][m];
    //for (int i = n - 1; i >= 0; i--) {
    //    for (int j = 0; j < m; j++) {
    //        dp[i][j] = Integer.MAX_VALUE;
    //        for (int k = 0; k < m; k++) {
    //            if (r.charAt(k) == key.charAt(i)) {
    //                int move = Math.abs(j - k), min = Math.min(move, m - move);
    //                dp[i][j] = Math.min(dp[i][j], min + dp[i + 1][k]);
    //            }
    //        }
    //    }
    //}
    //return dp[0][0] + n;
    //
    // 。。。。 int move = Math.abs(j - k), min = Math.min(move, m - move);



//Runtime: 82 ms, faster than 35.54 % of C++ online submissions for Freedom Trail.
//Memory Usage : 16.6 MB, less than 23.69 % of C++ online submissions for Freedom Trail.
    // < 100
    // 现在的位置，key的位置，最小步数。 太稀疏了，
    // 6-1 5-2 4-3
    // 1  -2 1  -3 2    -0 1 -6 2 -5 3  -4 3     6+2 = sz1+1
    // 5  3 -0  3-4-0 ,  3-0-2, 3-1-3,3-2-4  
    // 5 - 0 ,  sz1+tar - now
    int lt0514a(string ring, string key)
    {
        vector<vector<int>> vvi(26);
        for (int i = 0; i < ring.size(); ++i)
        {
            vvi[ring[i] - 'a'].push_back(i);
        }
        vector<unordered_map<int, int>> vp(key.size());
        int sz1 = ring.size();
        for (int i : vvi[key[0] - 'a'])
        {
            int t2 = (min(i, sz1 - i)) + 1;
            vp[0][i] = t2;
        }

        for (int i = 1; i < key.size(); ++i)
        {
            for (auto& p : vp[i - 1])
            {
                //int pidx = p.first;
                //int t2 = p.second + 1 + min(abs(pidx - ));
                int p1 = p.first;
                int p2 = p.second;
                for (int ni : vvi[key[i] - 'a'])
                {
                    int t2 = p2 + 1 + min(int (sz1 + p1 - ni), min(abs(p1 - ni), int (sz1 + ni - p1)));
#ifdef __test
                    cout << i << ", " << p1 << ", " << ni << ", " << sz1 << " === " << t2 << endl;
#endif
                    if (vp[i].find(ni) == vp[i].end())
                    {
                        vp[i][ni] = t2;
                    }
                    else
                    {
                        vp[i][ni] = min(vp[i][ni], t2);
                    }
                }
            }
        }

#ifdef __test
        for (int i = 0; i < key.size(); ++i)
        {
            cout << key[i] << " -- ";
            for (auto& p : vp[i])
            {
                cout << p.first << ":" << p.second << ",   ";
            }
            cout << endl;
        }
#endif

        int ans = INT_MAX;
        for (auto& p : vp[key.size() - 1])
        {
            ans = min(ans, p.second);
        }
        return ans;
    }

};

int main()
{

    LT0514 lt;

    //string r = "godding", k = "gd";

    //string r = "godding", k = "godding";

    string r = "pqwcx", k = "cpqwx";        // 13

    //string r = "abcde", k = "ade";      // 6


    cout << lt.lt0514a(r, k) << endl;

    return 0;
}
