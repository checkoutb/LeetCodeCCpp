
#include "../header/myheader.h"

class LT2056
{
public:




// .. g 看懂了，这个是 一秒走一步，如果 2个棋子在 同一秒内 在同一个格子 就不能走了。。
// 得在棋盘上标记 时间。 如果 时间相同，就 都不能走。。

// r q b 车 皇后 象
// 王车易位。 水平相连.. 这个好像是 + 相连啊， 而且 车和象 相连， 也能易位？
    int lt2056a(vector<string>& pieces, vector<vector<int>>& positions)
    {
        vector<vector<char>> vvi(8, vector<char>(8, '.'));
        for (int i = 0; i < pieces.size(); i++)
        {
            vvi[positions[i][0] - 1][positions[i][1] - 1] = pieces[i][0];
        }
        int arr[] = {1,0,-1,0,1};       // +
        int arr2[] = {1,1,-1,-1,1};     // ><
        int ans = 0;
        int nxi = -1;
        int nxj = -1;
        int ans2 = 1;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (vvi[i][j] == '.')
                    continue;
                ans = 1;
                char ch = vvi[i][j];
                if (ch == 'r' || ch == 'q')     // +
                {
                    for (int k = 0; k < 4; k++)
                    {
                        nxi = i + arr[k];
                        nxj = i + arr[k + 1];
                        while (isValidaa(nxi, nxj) && vvi[nxi][nxj] == '.')
                        {
                            ans++;
                            nxi += arr[k];
                            nxj += arr[k + 1];
                        }
                    }
                }
                if (ch == 'q' || ch == 'b')     // ><
                {
                    for (int k = 0; k < 4; k++)
                    {
                        nxi = i + arr2[k];
                        nxj = j + arr2[k + 1];
                        while (isValidaa(nxi, nxj) && vvi[nxi][nxj] == '.')
                        {
                            ans++;
                            nxi += arr2[k];
                            nxj += arr2[k + 1];
                        }
                    }
                }
                nxi = i + 1;
                nxj = j + 1;
                if (isValidaa(nxi, j) && vvi[nxi][nxj] != '.')
                    ans++;
                if (isValidaa(i, nxj) && vvi[nxi][nxj] != '.')
                    ans++;

                ans2 *= ans;
            }
        }
        return ans2;
    }

    bool isValidaa(int i, int j)
    {
        return i >= 0 && j >= 0 && i < 8 && j < 8;
    }

};

int main()
{

    LT2056 lt;

//    vector<string> vs = {"rrr"};
//    vector<string> vs = {"qqq"};
//    myvvi vv = {{1,1}};

//    vector<string> vs = {"bbb"};
//    myvvi vv = {{4,3}};

    vector<string> vs = {"rrr", "bbb"};
    myvvi vv = {{1,1},{2,1}};

    cout<<lt.lt2056a(vs, vv);

    return 0;
}
