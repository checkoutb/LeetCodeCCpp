
#include "../header/myheader.h"

class LT3044
{
public:

    // D D

    // for (int x = i, y = j; x >= 0 && x < m && y >= 0 && y < n; x += dx[t], y += dy[t]) {




// Runtime
// 7ms
// Beats100.00%of users with C++
// Memory
// 30.28MB
// Beats75.00%of users with C++

    int mostFrequentPrime(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        std::map<int, int> map2;
        int path[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                for (int k = 0; k < 8; ++k)
                {
                    t2 = mat[i][j];
                    int ni = i + path[k][0];
                    int nj = j + path[k][1];
                    while (ni >= 0 && nj >= 0 && ni < sz1 && nj < sz2)
                    {
                        t2 = t2 * 10 + mat[ni][nj];
                        if (map2.contains(t2) || isPrime(t2))
                            ++map2[t2];

                        ni += path[k][0];
                        nj += path[k][1];
                    }
                }
            }
        }
        int ans = -1;
        int mx = 1;
        for (auto& [k, v] : map2)
        {
            if (v >= mx)
            {
                ans = k;
                mx = v;
            }
        }
        return ans;
    }

    bool isPrime(int a)
    {
        for (int i = 2; i * i <= a; ++i)
        {
            if (a % i == 0)
                return false;
        }
        return true;
    }

};

int main()
{

    LT3044 lt;

    // myvvi vv {{1,1},{9,9},{1,1}};
    // myvvi vv {{7}};
    // myvvi vv {{9,7,8},{4,6,5},{2,8,6}};
    myvvi vv {{9,3}};

    cout<<lt.mostFrequentPrime(vv)<<endl;


    return 0;
}
