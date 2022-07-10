
#include "../header/myheader.h"

class LT0913
{
public:



    // gg , 无限2个点跳。


    int lt0913a(vector<vector<int>>& graph)
    {
        int sz1 = graph.size();

        vector<vector<int>> dpm(sz1, vector<int>(sz1, -1));
        vector<vector<int>> dpc(sz1, vector<int>(sz1, -1));

        dfsam1(graph, 1, 2, -1, -1, dpm, dpc);

        return dpm[1][2];
    }

    int dfsam1(vector<vector<int>>& vvi, int m, int c, int lm, int lc, vector<vector<int>>& dpm, vector<vector<int>>& dpc)
    {
#ifdef __test
        cout << m << ", " << c << endl;
#endif

        if (m == c)
            return 2;
        if (dpm[m][c] != -1)
            //return dpm[m][c];
            return 0;


        vector<int> win;
        vector<int> draw;
        for (int nxt : vvi[m])
        {
            int t2 = dfsac1(vvi, nxt, c, m, c, dpm, dpc);
            if (t2 == 1)
            {
                win.push_back(nxt);
            }
            else if (t2 == 0)
            {
                draw.push_back(nxt);
            }
        }

        for (int i : win)
        {
            //if (i != m)
            {
                dpm[m][c] = 1;
                goto AAA;
            }
        }
        //dpm[m][c] = win.empty() ? 2 : 0;

        dpm[m][c] = draw.empty() ? 2 : 0;


        AAA:
        return dpm[m][c];
    }

    int dfsac1(vector<vector<int>>& vvi, int m, int c, int lm, int lc, vector<vector<int>>& dpm, vector<vector<int>>& dpc)
    {
        if (m == 0)
        {
            return 1;
        }
        if (dpc[m][c] != -1)
            //return dpc[m][c];
            return 0;


        vector<int> win;
        //vector<int> draw;
        bool draw = false;
        bool mouseWin = false;
        for (int i : vvi[c])
        {
            int t2 = dfsam1(vvi, m, i, m, c, dpm, dpc);
            if (t2 == 2)
            {
                win.push_back(t2);
            }
            else if (t2 == 0)
            {
                draw = true;
            }
            else
                mouseWin = true;
        }

        dpc[m][c] = win.empty() ? (draw ? 0 : 1) : 2;
        return dpc[m][c];
    }

};

int main()
{

    LT0913 lt;

    myvvi vv = { {2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3} };

    cout << lt.lt0913a(vv) << endl;

    return 0;
}
