
#include "../header/myheader.h"

class LT1536
{
public:



// gg,  主要是， 如果有2个 相同长度， 那么 其中一个 就需要下沉， 如果 下沉的位值已经有值了。那么需要继续下沉，
// 等于是 反， 正常是 下沉的那个先，才能min，不。
// tai chang le..gg
    int lt1536b(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        vector<int> v(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = sz1 - 1; j >= 0; --j)
            {
                if (grid[i][j] == 1)
                {
                    v[i] = j + 1;
                    break;
                }
            }
        }
        int ans = 0;
        vector<bool> vb(sz1, false);
        for (int i = 0; i < sz1; ++i)
        {
            int mx = -1;
            int mxi = -1;
            for (int j = 0; j < sz1; ++j)
            {
                if ((v[j] > j + 1) && mx < v[j])
                {
                    mx = v[j];
                    mxi = j;
                }
            }
            if (v[mxi] != mxi + 1)
            {
                ans += v[mxi] - mxi;
                for (int j = mxi; j < v[mxi]; ++j)
                {
                    v[mxi] = v[mxi + 1];
                }
                v[mxi] = mx;
            }
            else
            {
                for (int j = mxi + 1; j < sz1; ++j)
                {
                    if (v[j] <= mxi)
                    {
                        break;
                    }
                }
            }
        }

        return ans;
    }


// error,  not minimum
// select sort. bubble sort.
// 当不含0时，[0] == 0，  0既是值，也是长度。    1也是。
    int lt1536a(vector<vector<int>>& grid)
    {
        int sz1 = grid.size();
        for (int i = 0; i < sz1; i++)
        {
            for (int j = sz1 - 1; j > 0; --j)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][0] = j + 1;
                    break;
                }
            }
        }
        int ans = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            int mx = grid[0][0];
            int mxi = 0;
            for (int j = 1; j <= i; ++j)
            {
                if (grid[j][0] >= mx)           // .
                {
                    mx = grid[j][0];
                    mxi = j;
                }
            }
            if (mx > i + 1)
                return -1;
            ans += i - mxi;
            for (int j = mxi; j < i; ++j)
            {
                grid[j][0] = grid[j + 1][0];
            }
            grid[i][0] = mx;
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{0,0,1},{1,1,0},{1,0,0}};
//    myvvi vv = {{0,1,1,0},{0,1,1,0},{0,1,1,0},{0,1,1,0}};
//    myvvi vv = {{1,0,0},{1,1,0},{1,1,1}};
    myvvi vv = {{1,0,0,0,0,0},
                {0,1,0,1,0,0},
                {1,0,0,0,0,0},
                {1,1,1,0,0,0},
                {1,1,0,1,0,0},
                {1,0,0,0,0,0}};       // 2


    LT1536 lt;

    cout<<lt.lt1536a(vv);

    return 0;
}
