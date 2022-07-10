
#include "../header/myheader.h"

class LT0864
{
public:


    // D D






//Runtime: 352 ms, faster than 30.43 % of C++ online submissions for Shortest Path to Get All Keys.
//Memory Usage : 10.3 MB, less than 85.68 % of C++ online submissions for Shortest Path to Get All Keys.
    // 2^6 64
    // ["@..aA",
    //  "..B#.",
    //  "....b"]
    int lt0864a(vector<string>& grid)
    {
        int sz1 = grid.size();
        int sz2 = grid[0].size();

        queue<int> que1;
        int mxxx = 0;

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (grid[i][j] == '@')
                {
                    que1.push(i * 100 + j);
                }
                else if (std::isupper(grid[i][j]))
                {
                    mxxx = max(mxxx, 1 << (grid[i][j] - 'A'));
                }
            }
        }
        mxxx *= 2;

        //vector<vector<int>> vvi(sz1, vector<int>(sz2, -1));
        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz2, vector<int>(mxxx, -1)));

        vvvi[que1.front() / 100][que1.front() % 100][0] = 0;

#ifdef __test
        cout << mxxx << endl;
#endif

        int arr[] = { 1,0,-1,0,1 };
        while (!que1.empty())
        {
            int t2 = que1.front();
            que1.pop();
            int r = t2 / 100;
            int c = t2 % 100;

#ifdef __test
            cout << "qqq " << r << ", " << c << ", " << mxxx << " - -- " << vvvi[r][c][mxxx - 1] << endl;
#endif

            if (vvvi[r][c][mxxx - 1] != -1)
                return vvvi[r][c][mxxx - 1];

            for (int i = 0; i < 4; ++i)
            {
                int nr = r + arr[i];
                int nc = c + arr[i + 1];

#ifdef __test
                cout << "new r c " << nr << " - " << nc << endl;
#endif

                if (nr < 0 || nc < 0 || nr == sz1 || nc == sz2)
                    continue;
                if (grid[nr][nc] == '#')
                    continue;

                int lockbit = 0;
                if (std::isupper(grid[nr][nc]))     // lock
                {
                    //if (vvvi[r][c][1 < (grid[nr][nc] - 'A')] & (1 << (grid[nr][nc] - 'A')) == 0)
                    //    continue;
                    lockbit = (1 << (grid[nr][nc] - 'A'));
                }
                
                int keybit = 0;
                if (std::islower(grid[nr][nc]))        // key
                {
                    keybit = (1 << (grid[nr][nc] - 'a'));
                }

                bool one = false;
                for (int i = 0; i < mxxx; ++i)
                {
                    if (vvvi[r][c][i] == -1)
                        continue;

                    int t3 = i;
                    if (lockbit != 0 && ((t3 & lockbit) == 0))
                    {
                        continue;
                    }
                    if (vvvi[nr][nc][t3] == -1 || (vvvi[nr][nc][t3] > vvvi[r][c][t3] + 1))
                    {
                        one = true;
                        vvvi[nr][nc][t3] = vvvi[r][c][i] + 1;
                    }

                    if (keybit == 0)
                        continue;


                    int t2 = i | keybit;

                    if (lockbit != 0 && ((t2 & lockbit) == 0))
                    {
                        continue;
                    }

                    if (vvvi[nr][nc][t2] == -1)
                    {
                        one = true;
                        vvvi[nr][nc][t2] = vvvi[r][c][i] + 1;
                    }
                    else
                    {
                        if (vvvi[nr][nc][t2] > vvvi[r][c][i] + 1)
                        {
                            one = true;
                            vvvi[nr][nc][t2] = vvvi[r][c][i] + 1;
                        }
                    }
                }
                if (one)
                {
                    que1.push(nr * 100 + nc);
                }
            }

#ifdef __test

            for (int i = 0; i < sz1; ++i)
            {
                for (int j = 0; j < sz2; ++j)
                {
                    cout << i << ", " << j << " - ";
                    for (int k = 0; k < mxxx; ++k)
                    {
                        if (vvvi[i][j][k] != -1)
                            cout << "[" << k << ":" << vvvi[i][j][k] << "], ";
                    }
                    cout << endl;
                }
            }
#endif

        }
        return -1;
    }

};

int main()
{

    LT0864 lt;


    //vector<string> vs = { "@.a..", "###.#", "b.A.B" };
    //vector<string> vs = { "@..aA","..B#.","....b" };

    vector<string> vs = { "@Aa" };

    cout << lt.lt0864a(vs) << endl;

    return 0;
}
