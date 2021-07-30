
#include "../../header/myheader.h"

class LT
{
public:


// D D

// ... 从4个方向 dp。。
// 2个 forfor。 一个00 开始， 一个 sz1,sz2开始。







// AC       160ms, beats 16%....
    vector<vector<int>> ltc(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        queue<vector<int>> que1;            // i,j,step
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (mat[i][j] == 0)
                {
                    vvi[i][j] = 0;
                    que1.push({i,j,0});
                }
            }
        }
        while (!que1.empty())
        {
            int szq = que1.size();
            while (szq-- > 0)
            {
                vector<int> vi = que1.front();
                que1.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int a = vi[0] + arr2[k][0];
                    int b = vi[1] + arr2[k][1];
                    int c = vi[2] + 1;
                    if (a < 0 || b < 0 || a >= sz1 || b >= sz2)
                        continue;
//                    if (mat[a][b] == 0)
//                        continue;
                    if (vvi[a][b] <= c)
                        continue;
                    vvi[a][b] = c;
                    que1.push({a,b,c});
                }
            }
        }
        return vvi;
    }
    int arr2[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};



    // dfs 能够一次一个岛嘛？ 需要一个visit数组?
// error
    vector<vector<int>> ltb(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (mat[i][j] == 0)
                {
                    vvi[i][j] = 0;
                    continue;
                }
                if (vvi[i][j] == INT_MAX)
                {

                }
//                queue<pair<int, int>> que1;
//                que1.push({i, j});
//                // ... dfs...
            }
        }
        return vvi;
    }

    // 一个岛，一次。
    int dfsa1(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& vvi)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            return 1000000;
        if (vvi[i][j] != INT_MAX)
            return vvi[i][j];
        return -1;
    }




// tle.
// 每个1 都 bfs 搜索0, 还是每个0 都bfs扩展出去。  应该差不多吧。
    vector<vector<int>> lta(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, INT_MAX));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (mat[i][j] == 0)
                {
                    queue<pair<int, int>> vp;           // 非0, 且 vvi > step
                    vp.push({i, j});
                    int step = 0;
//                    vvi[i][j] = 0;
                    while (!vp.empty())
                    {
                        int szq = vp.size();
                        while (szq-- > 0)
                        {
                            pair<int, int> pii = vp.front();
                            vp.pop();
                            vvi[pii.first][pii.second] = step;

                            #ifdef __test
                            cout<<pii.first<<", "<<pii.second<<endl;
                            #endif // __test

                            for (int k = 0; k < 4; ++k)
                            {
                                int a = pii.first + arr[k][0];
                                int b = pii.second + arr[k][1];             // 会重复很多次的， 所以 0的扩展 应该更慢。
                                if (a < 0 || b < 0 || a >= sz1 || b >= sz2 || mat[a][b] == 0 || vvi[a][b] <= (step + 1))
                                {
                                    continue;
                                }
                                vp.push({a, b});
                            }
                        }
                        step++;
                    }
                }
            }
        }
        return vvi;
    }
    int arr[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

};

int main()
{
//    myvvi vv = {{0,0,0},{0,1,0},{0,0,0}};
//    myvvi vv = {{0,0,0},{0,1,0},{1,1,1}};

    myvvi vv = {{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};

    LT lt;

    myvvi vv2 = lt.ltc(vv);

    for (myvi& v : vv2)
    {
        for (int i : v)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
