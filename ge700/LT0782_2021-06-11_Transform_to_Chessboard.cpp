
#include "../header/myheader.h"

class LT0782
{
public:

// D

// 不需要swap， 需要计算。。。



// gg

// 估计需要根据 行中 1的个数 来swap
    int lt0782b(vector<vector<int>>& board)
    {
        int ans = -1;
        int sz1 = board.size();
        if (sz1 % 2 == 0)
        {
            return lt0782a(board);
        }

        vector<int> vr(sz1);
        vector<int> vc(sz1);
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                if (board[i][j] == 1)
                {
                    vr[i]++;
                    vc[j]++;
                    sum2++;
                }
            }
        }
        vector<vector<int>> vvi2(begin(board), end(board));

        if (sum2 > (sz1 * sz1 / 2))
        {
            int tar = -1;
            int cnt = 0;
            // 1
            if (board[0][0] != 1)
            {
                cnt++;
                for (int i = 1; i < sz1; i += 2)
                {
                    if (board[i][0] == 1 && vr[i] > (sz1 / 2))
                    {
                        tar = i;
                        break;
                    }
                }
                if (tar == -1)
                {
                    cnt++;
                    for (int i = 1; i < sz1; i += 2)
                    {
                        if (vr[i] > (sz1 / 2))
                        {
                            tar = i;
                            break;
                        }
                    }
                }
                if (tar == -1)
                {
                    return -1;
                }
                for (int j = 0; j < sz1; ++j)
                {
                    int t2 = board[0][j];
                    board[0][j] = board[tar][j];
                    board[tar][j] = t2;
                }
                if (board[0][0] != 1)
                {
                    for (int j = 0; j < sz1; ++j)
                    {

                    }
                }
                dfsa1(board, 1);
            }
        }
        else
        {
            // 0

        }
    }


// error [[0,1,1],[1,0,0],[1,0,0]]
// 一共就2种可能。 任意swap，不需要相邻。
// 优先横着还是竖着，似乎都一样？ 。。 不，至少第一次移动 需要考虑 横/竖
    int lt0782a(vector<vector<int>>& board)
    {
        int ans = -1;

        vector<vector<int>> vvi2(begin(board), end(board));
        vector<vector<int>> vvi3(begin(board), end(board));
        vector<vector<int>> vvi4(begin(board), end(board));

        // 0
        int t3 = -1;
        int cnt = 0;
        if (board[0][0] != 0)
        {
            cnt = 1;
            int tar = -1;
            for (int i = 1; i < vvi2.size(); i += 2)
            {
                if (board[i][0] == 0)
                {
                    tar = i;
                    goto CCC;
                }
            }
            goto NXT5;
//            return -1;
            CCC:
            for (int j = 0; j < vvi2.size(); ++j)
            {
                int t2 = board[0][j];
                board[0][j] = board[tar][j];
                board[tar][j] = t2;
            }
        }
        #ifdef __test
        for (myvi& vi : board)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test
        t3 = dfsa1(board, 1);
        if (t3 != -1)
        {
            ans = t3 + cnt;
        }
        if (t3 == -1)
        {
            NXT5:
            cnt = 0;
            if (vvi3[0][0] != 0)
            {
                cnt = 1;
                int tar = -1;
                for (int j = 1; j < vvi2.size(); j += 2)
                {
                    if (vvi3[0][j] == 0)
                    {
                        tar = j;
                        goto CCC2;
                    }
                }
                goto NXT3;
//                return -1;
                CCC2:
                for (int j = 0; j < vvi3.size(); ++j)
                {
                    int t2 = vvi3[j][0];
                    vvi3[j][0] = vvi3[j][tar];
                    vvi3[j][tar] = t2;
                }
            }
            #ifdef __test
            for (myvi& vi : vvi3)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            #endif // __test
            t3 = dfsa1(vvi3, 1);
            if (t3 != -1)
            {
                if (ans == -1)
                    ans = t3 + cnt;
                else
                    ans = min(ans, t3 + cnt);
            }
        }

        #ifdef __test
        cout<<". mid .. "<<ans<<endl;
        #endif // __test

        // 1
        NXT3:
        t3 = -1;
        cnt = 0;
        if (vvi2[0][0] != 1)
        {
            cnt = 1;
            int tar = -1;
            for (int i = 1; i < vvi2.size(); i += 2)
            {
                if (vvi2[i][0] == 1)
                {
                    tar = i;
                    goto DDD;
                }
            }
            #ifdef __test
            cout<<" ???? "<<endl;
            #endif // __test
//            return -1;
            goto NXT;

            DDD:
            for (int j = 0; j < vvi2.size(); ++j)
            {
                int t2 = vvi2[0][j];
                vvi2[0][j] = vvi2[tar][j];
                vvi2[tar][j] = t2;
            }
        }
            #ifdef __test
            for (myvi& vi : vvi2)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            #endif // __test
        t3 = dfsa1(vvi2, 1);
        if (t3 != -1)
        {
            if (ans == -1)
                ans = t3 + cnt;
            else
                ans = min(ans, t3 + cnt);
        }
        else
        {
            NXT:
            cnt = 0;
            if (vvi4[0][0] != 1)
            {
                cnt = 1;
                int tar = -1;
                for (int i = 1; i < vvi4.size(); i += 2)
                {
                    if (vvi4[0][i] == 1)
                    {
                        tar = i;
                        goto DDD2;
                    }
                }
//                return -1;
                goto NXT2;
                DDD2:
                for (int j = 0; j < vvi4.size(); ++j)
                {
                    int t2 = vvi4[j][0];
                    vvi4[j][0] = vvi4[j][tar];
                    vvi4[j][tar] = t2;
                }
            }
            #ifdef __test
            for (myvi& vi : vvi4)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            #endif // __test
            t3 = dfsa1(vvi4, 1);
            if (t3 != -1)
            {
                if (ans == -1)
                    ans = t3 + cnt;
                else
                    ans = min(ans, t3 + cnt);
            }
        }
        NXT2:

        return ans;
    }

    // hang
    int dfsa1(vector<vector<int>>& vvi, int i)
    {
        #ifdef __test
        cout<<i<<endl;
        #endif // __test
        if (i == vvi.size())
        {
            #ifdef __test
            cout<<"go to dfsa22222"<<endl;
            #endif // __test
            return dfsa2(vvi, 1);
        }
        int cnt = 0;
        int tar = -1;
        if (
//            i > 0 &&
            (vvi[i][0] == vvi[i - 1][0]))
        {
            #ifdef __test

            #endif // __test
            cnt = 1;
            for (int a = i + 1; a < vvi.size(); a += 2)
            {
                if (vvi[a][0] != vvi[i][0])
                {
                    tar = a;
                    goto AAA;
                }
            }
            #ifdef __test
            cout<<"======="<<endl;
            for (myvi& vi : vvi)
            {
                for (int i : vi)
                    cout<<i<<", ";
                cout<<endl;
            }
            #endif // __test
            return -1;
        }
        AAA:
        if (tar != -1)
        {
            for (int j = 0; j < vvi[0].size(); ++j)
            {
                int t2 = vvi[i][j];
                vvi[i][j] = vvi[tar][j];
                vvi[tar][j] = t2;
            }
        }
        int t3 = dfsa1(vvi, i + 1);
        if (t3 == -1)
            return -1;
        return t3 + cnt;

//        if (tar != -1)
//        {
//            for (int j = 0; j < vvi[0].size(); ++j)
//            {
//                int t2 = vvi[i][j];
//                vvi[i][j] = vvi[a][j];
//                vvi[a][j] = t2;
//            }
//        }
    }

    // lie
    int dfsa2(vector<vector<int>>& vvi, int j)
    {
        if (j == vvi[0].size())
        {
            if (ischessa1(vvi))
            {
                #ifdef __test
                cout<<"final check TTT"<<endl;
                #endif // __test
                return 0;
            }
            else
            {
                #ifdef __test
                cout<<"final check FFF"<<endl;
                #endif // __test
                return -1;
            }
        }

        int cnt = 0;
        int tar = -1;
        if (vvi[0][j] == vvi[0][j - 1])
        {
            cnt = 1;
            for (int a = j + 1; a < vvi.size(); a += 2)
            {
                if (vvi[0][a] != vvi[0][j])
                {
                    tar = a;
                    goto BBB;
                }
            }
            return -1;
        }

        BBB:

        if (tar != -1)
        {
            for (int i = 0; i < vvi.size(); ++i)
            {
                int t2 = vvi[i][j];
                vvi[i][j] = vvi[i][tar];
                vvi[i][tar] = t2;
            }
        }
        int t3 = dfsa2(vvi, j + 1);
        if (t3 == -1)
            return -1;
        return t3 + cnt;

    }

    bool ischessa1(vector<vector<int>>& vvi)
    {
        for (int i = 0; i < vvi.size(); ++i)
        {
            if (i != 0)
            {
                if (vvi[i][0] == vvi[i - 1][0])
                    return false;
            }
            for (int j = 1; j < vvi.size(); ++j)    // N*N
            {
                if (vvi[i][j] == vvi[i][j - 1])
                    return false;
            }
        }
        return true;
    }
};

int main()
{
//    myvvi vv = {{0,1,1,0},{0,1,1,0},{1,0,0,1},{1,0,0,1}};

//    myvvi vv = {{0,1},{1,0}};

//    myvvi vv = {{1,0},{1,0}};

//    myvvi vv = {{1,0,0},{0,1,1},{1,0,0}};

//    myvvi vv = {{0,1,1},{0,1,1},{1,0,0}};

    myvvi vv = {{0,1,1},{1,0,0},{1,0,0}};       // 2


    LT0782 lt;

    cout<<lt.lt0782a(vv)<<endl;

    return 0;
}
