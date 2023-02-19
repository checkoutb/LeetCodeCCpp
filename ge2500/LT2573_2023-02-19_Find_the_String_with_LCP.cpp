
#include "../header/myheader.h"

class LT2573
{
public:


    // D D

    //Then we check if this A is valid for lcp.
    //    If A[i] == A[j],
    //    then lcp[i][j] = lcp[i + 1][j + 1] + 1








    //Runtime938 ms
    //    Beats
    //    25 %
    //    Memory68.9 MB
    //    Beats
    //    37.50 %
/*
[[4,0,2,0]
,[0,3,0,1]
,[2,0,2,0]
,[0,1,0,1]]

[[4,3,2,1]
,[3,3,2,1]
,[2,2,2,1]
,[1,1,1,1]]

*/

    // [i,) [j,)  max common prefix length
    // [0, j] > 0 means [0] == [j] ... [0] is a
    // [1, j] > 0   [1] is b (if [1] not a)
    string lt2573a(vector<vector<int>>& lcp)
    {
        int sz1 = lcp.size();
        string ans(sz1, ' ');
        char ch = 'a';
        for (int i = 0; i < sz1; ++i)
        {
            if (i + lcp[i][i] != sz1)
                return "";
            if (ans[i] != ' ')
                continue;
            if (ch > 'z')
                return "";
            ans[i] = ch++;

            for (int j = i + 1; j < sz1; ++j)
            {
                if (lcp[i][j] != lcp[j][i])
                    return "";

                if (lcp[i][j])
                {
                    if (ans[j] != ' ')
                        return "";

                    ans[j] = ans[i];
                }
            }
        }

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int cnt = 0;
                for (int k = 0; j + k < sz1; ++k)
                {
                    if (ans[i + k] == ans[j + k])
                    {
                        ++cnt;
                    }
                    else
                        break;
                }
                if (lcp[i][j] != cnt)
                    return "";
            }
        }

        return ans;
    }

};

int main()
{

    LT2573 lt;

    //myvvi vv = { {4,0,2,0},{0,3,0,1}, {2,0,2,0},{0,1,0,1} };
    //myvvi vv = { {4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1} };
    //myvvi vv = { {4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,3} };
    myvvi vv = {            // abcbbaab
        {8,0,0,0,0,1,2,0},
        {0,7,0,1,1,0,0,1},
        {0,0,6,0,0,0,0,0},
        {0,1,0,5,1,0,0,1},
        {0,1,0,1,4,0,0,1},
        {1,0,0,0,0,3,1,0},
        {2,0,0,0,0,1,2,0},
        {0,1,0,1,1,0,0,1} };



    cout << lt.lt2573a(vv) << endl;

    return 0;
}
