
#include "../header/myheader.h"

class LT1349
{
public:




// Runtime
// 3ms
// Beats71.32%of users with C++
// Memory
// 9.30MB
// Beats82.95%of users with C++
    int maxStudents(vector<vector<char>>& seats)
    {
        int sz1 = seats.size();
        int sz2 = seats[0].size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(1 << sz2, -1));
        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (seats[i][j] == '.')
                {
                    vi[i] |= (1 << j);
                }
            }
        }
        int ans = dfsa1(vvi, 0, sz1, sz2, vi, 0);

#ifdef __test
        showVectorInt(vi);
        cout<<" ==========\n";
        for (myvi& vi : vvi)
        {
            showVectorInt(vi);
        }
#endif


        return ans;
    }

    int dfsa1(vector<vector<int>>& vvi, int level, int sz1, int sz2, vector<int>& vi, int bits)
    {
        if (vvi[level][bits] != -1)
            return vvi[level][bits];
        if (level == sz1)
        {
            int n = 0;
            // while (bits > 0)         // .
            // {
            //     n += (bits & 1);
            //     bits >>= 1;
            // }
            vvi[level][bits] = n;
            return n;
        }

        int ans = 0;
        int t2, t3;
        for (int i = 0; i < (1 << sz2); ++i)
        {
            if ((i & vi[level]) != i)
                continue;

            for (int j = 0; j < sz2; ++j)
            {
                if ((i & (1 << j)) != 0 && (i & (1 << (j + 1))) != 0)
                {
                    goto AAA;
                }
                if ((i & (1 << j)) == 0)
                    continue;
                if (j > 0)
                {
                    if ((bits & (1 << (j - 1))) != 0)
                        goto AAA;
                }
                if (j < sz2 - 1)
                {
                    if ((bits & 1 << (j + 1)) != 0)
                        goto AAA;
                }
            }

            t2 = dfsa1(vvi, level + 1, sz1, sz2, vi, i);
            t3 = i;
            while (t3 > 0)
            {
                t2 += (t3 & 1);
                t3 >>= 1;
            }
            ans = max(ans, t2);

            AAA:
            continue;
        }
// cout<<ans<<"?\n";
        vvi[level][bits] = ans;
        return ans;
    }
};

int main()
{

    LT1349 lt;

    vector<vector<char>> vvc{{'.','#'},{'#','#'},{'#','.'},{'#','#'},{'.','#'}};

    cout<<lt.maxStudents(vvc);

    return 0;
}
