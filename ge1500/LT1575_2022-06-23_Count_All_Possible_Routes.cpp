
#include "../header/myheader.h"

class LT1575
{
public:

    // D D



    //class Solution {
    //public:
    //    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    //        static const int MOD = 1e9 + 7;

    //        int s = locations[start];
    //        int f = locations[finish];
    //        sort(begin(locations), end(locations));
    //        start = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), s));
    //        finish = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), f));

    //        vector<vector<int>> left(locations.size(), vector<int>(fuel + 1));  // left[i][f], last move is toward left to location i by f fuel
    //        vector<vector<int>> right(locations.size(), vector<int>(fuel + 1));  // right[i][f], last move is toward right to location i by f fuel
    //        for (int f = 1; f <= fuel; ++f) {
    //            for (int j = 0; j < locations.size() - 1; ++j) {
    //                int d = locations[j + 1] - locations[j];
    //                if (f > d) {
    //                    // left[j][f] = right[j+1][f-d(j, j+1)] + 2*right[j+2][f-d(j, j+2)] + ... + 2^(k-1)*right[j+k][f-d(j, j+k)]
    //                    // => left[j+1][f] = (ight[j+2][f-d(j+1, j+2)] + 2*right[j+3][f-d(j+1, j+3)] + ... + 2^(k-2)*right[j+1+k-1][f-d(j+1, j+1+k-1)]
    //                    // => left[j+1][f-d(j, j+1)] = right[j+2][f-d(j, j+2)] + 2*right[j+3][f-d(j, j+3)] + ... + 2^(k-2)*right[j+k][f-d(j, j+k)]
    //                    // => left[j][f] = right[j+1][f-d(j, j+1)] + 2*left[j+1][f-d(j, j+1)]
    //                    left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % MOD) % MOD;
    //                }
    //                else if (f == d) {
    //                    left[j][f] = int(j + 1 == start);
    //                }
    //            }
    //            for (int j = 1; j < locations.size(); ++j) {
    //                int d = locations[j] - locations[j - 1];
    //                if (f > d) {
    //                    // right[j][f] = left[j-1][f-d(j, j-1)] + 2*left[j-2][f-d(j, j-2)] + ... + 2^(k-1)*left[j-k][f-d(j, j-k)]
    //                    // => right[j-1][f] = left[j-2][f-d(j-1, j-2)] + 2*left[j-3][f-d(j-1, j-3)] + ... + 2^(k-2)*left[j-1-k+1][f-d(j-1, j-1-k+1)]
    //                    // => right[j-1][f-d(j, j-1)] = left[j-2][f-d(j, j-2)] + 2*left[j-3][f-d(j, j-3)] + ... + 2^(k-2)*left[j-k][f-d(j, j-k)]
    //                    // => right[j][f] = left[j-1][f-d(j, j-1)] + 2*right[j-1][f-d(j, j-1)]
    //                    right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % MOD) % MOD;
    //                }
    //                else if (f == d) {
    //                    right[j][f] = int(j - 1 == start);
    //                }
    //            }
    //        }
    //        int result = int(start == finish);
    //        for (int f = 1; f <= fuel; ++f) {
    //            result = ((result + left[finish][f]) % MOD + right[finish][f]) % MOD;
    //        }
    //        return result;
    //    }
    //};


//Runtime: 243 ms, faster than 54.48 % of C++ online submissions for Count All Possible Routes.
//Memory Usage : 12.1 MB, less than 42.76 % of C++ online submissions for Count All Possible Routes.
    // 10^9 + 7 ...
    // dfs + memo ?
    int lt1575a(vector<int>& locations, int start, int finish, int fuel)
    {
        int sz1 = locations.size();
        vector<vector<int>> vvi(sz1, vector<int>(fuel + 1, -1));

        int ans = dfsa1(locations, vvi, start, finish, fuel);
        return ans;
    }

    int dfsa1(vector<int>& locations, vector<vector<int>>& vvi, int city, int finish, int fuel)
    {
        if (fuel < 0)
            return 0;

        int ans = 0;
        if (city == finish)
            ans = 1;

        if (vvi[city][fuel] != -1)
            return vvi[city][fuel];
        const int MOD = 1e9 + 7;
        for (int i = 0; i < locations.size(); ++i)
        {
            if (i != city)
            {
                int t2 = dfsa1(locations, vvi, i, finish, fuel - abs(locations[i] - locations[city]));
                ans = (ans + t2) % MOD;
            }
        }
        vvi[city][fuel] = ans;
        return ans;
    }

};

int main()
{

    LT1575 lt;

    //myvi v = { 2,3,6,8,4 };
    //int st = 1, fsh = 3, ful = 5;

    //myvi v = { 4,3,1 };
    //int st = 1, fsh = 0, ful = 6;

    myvi v = { 5,2,1 };
    int st = 0, fsh = 2, ful = 3;

    cout << lt.lt1575a(v, st, fsh, ful) << endl;

    return 0;
}
