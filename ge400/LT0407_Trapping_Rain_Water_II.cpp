
#include "../header/myheader.h"

class LT0407
{


// 对每个非边的点，判断四周是否能形成一个坑。

// error

public:
    int lt0407a(vector<vector<int>>& heightMap)
    {
        int sz1 = heightMap.size();
        int sz2 = heightMap[0].size();
        int max1 = 100000;

        int ans = 0;
        int last = -1;
        while (last != ans)
        {
            last = ans;

            for (int i = 1; i < sz1 - 1; i++)
            {
                for (int j = 1; j < sz2 - 1; j++)
                {
                    int h = funa1(heightMap, i, j);
                    ans += (h - heightMap[i][j] >= 0 ? h - heightMap[i][j] : 0);
                    heightMap[i][j] = h;

                    #ifdef __test
                    cout<<h<<endl;
                    #endif // __test
                }
            }
        }

        return ans;
    }

    int funa1(vector<vector<int>>& hm, int i, int j)
    {
        #ifdef __test
//        cout<<i<<"... "<<j<<"............ "<<hm[i][j]<<endl;
        #endif // __test

        int t1 = hm[i][j];
        vector<vector<bool>> arr(hm.size());            // vector<vector<int>> swp(n,vector<int>(m));
        for (int m = 0; m < hm.size(); m++)
        {
            arr[m].resize(hm[0].size());
        }
        arr[i][j] = true;
        int ans = recursiona1(hm, i, j, t1, arr);
        return ans;
    }

    int recursiona2(vector<vector<int>>& hm, int i, int j, int h, vector<vector<bool>>& arr)
    {
        if (i <= 0 || j <= 0 || i >= hm.size() - 1 || j >= hm[0].size() - 1)
            return 0;

        int ans = INT_MAX;

        if (!arr[i + 1][j])
        {
            arr[i + 1][j] = true;
            if (hm[i + 1][j] < h)
            {
                ans = min(ans, recursiona2(hm, i + 1, j, h, arr));
                ans = min(ans, recursiona2(hm, i, j - 1, h, arr));
                ans = min(ans, recursiona2(hm, i, j + 1, h, arr));

                cout<<",,,,1 "<<ans<<endl;
            }
            else
            {
                ans = min(ans, hm[i + 1][j]);


                cout<<",,,,2 "<<ans<<endl;

            }
        }
        if (!arr[i - 1][j])
        {
            arr[i - 1][j] = true;
            if (hm[i - 1][j] < h)
            {
                ans = min(ans, recursiona2(hm, i - 1, j, h, arr));
                ans = min(ans, recursiona2(hm, i, j - 1, h, arr));
                ans = min(ans, recursiona2(hm, i, j + 1, h, arr));

                cout<<",,,,3 "<<ans<<endl;

            }
            else
            {
                ans = min(ans, hm[i - 1][j]);

                cout<<",,,,4 "<<ans<<endl;

            }
        }
        if (!arr[i][j + 1])
        {
            arr[i][j + 1] = true;
            if (hm[i][j + 1] < h)
            {
                ans = min(ans, recursiona2(hm, i, j + 1, h, arr));
                ans = min(ans, recursiona2(hm, i - 1, j, h, arr));
                ans = min(ans, recursiona2(hm, i + 1, j, h, arr));

                cout<<",,,,5 "<<ans<<endl;

            }
            else
            {
                ans = min(ans, hm[i][j + 1]);

                cout<<",,,,6 "<<ans<<endl;

            }
        }
        if (!arr[i][j - 1])
        {
            arr[i][j - 1] = true;
            if (hm[i][j - 1] < h)
            {
                ans = min(ans, recursiona2(hm, i, j - 1, h, arr));
                ans = min(ans, recursiona2(hm, i - 1, j, h, arr));
                ans = min(ans, recursiona2(hm, i + 1, j, h, arr));

                cout<<",,,,7 "<<ans<<endl;

            }
            else
            {
                ans = min(ans, hm[i][j - 1]);

                cout<<",,,,8 "<<ans<<endl;

            }
        }
        cout<<",,,,.... "<<ans<<endl;
        return ans;
    }

    int recursiona1(vector<vector<int>>& hm, int i, int j, int h, vector<vector<bool>>& arr)
    {
        #ifdef __test
//        cout<<i<<", "<<j<<", "<<h<<endl;
        #endif // __test

        if (i <= 0 || j <= 0 || i >= hm.size() - 1 || j >= hm[0].size() - 1)
            return 0;

        int ans = INT_MAX;
        if (!arr[i + 1][j])
        {
            if (hm[i + 1][j] < h)
            {
                arr[i + 1][j] = true;
                ans = min(ans, recursiona1(hm, i + 2, j, h, arr));
                ans = min(ans, recursiona1(hm, i + 1, j - 1, h, arr));
                ans = min(ans, recursiona1(hm, i + 1, j + 1, h, arr));
            }
            else
            {
                ans = min(ans, hm[i + 1][j]);
            }
        }
        if (!arr[i - 1][j])
        {
            if (hm[i - 1][j] < h)
            {
                arr[i - 1][j] = true;
                ans = min(ans, min(recursiona1(hm, i - 2, j, h, arr), min(recursiona1(hm, i - 1, j - 1, h, arr), recursiona1(hm, i - 1, j + 1, h, arr))));
            }
            else
            {
                ans = min(ans, hm[i - 1][j]);
            }
        }
        if (!arr[i][j - 1])
        {
            if (hm[i][j - 1] < h)
            {
                arr[i][j - 1] = true;
                ans = min(ans, min(recursiona1(hm, i, j - 2, h, arr), min(recursiona1(hm, i - 1, j - 1, h, arr), recursiona1(hm, i + 1, j - 1, h, arr))));
            }
            else
            {
                ans = min(ans, hm[i][j - 1]);
            }
        }
        if (!arr[i][j + 1])
        {
            if (hm[i][j + 1] < h)
            {
                arr[i][j + 1] = true;
                ans = min(ans, min(recursiona1(hm, i, j + 2, h, arr), min(recursiona1(hm, i - 1, j + 1, h, arr), recursiona1(hm, i + 1, j + 1, h, arr))));
            }
            else
            {
                ans = min(ans, hm[i][j + 1]);
            }
        }

        #ifdef __test
        cout<<ans<<endl;
        #endif // __test

        return ans;
    }
};

int main()
{
    vector<vector<int>> map4 = {{1,4,3,1,3,2},      // 4
        {3,2,1,3,2,4},
        {2,3,3,2,3,1}
    };

    LT0407 lt;
    cout<<lt.lt0407a(map4)<<endl;

    cout<<endl<<endl<<INT_MAX<<"..."<<pow(2, 16)<<endl;

    return 0;
}
