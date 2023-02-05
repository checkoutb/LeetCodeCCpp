
#include "../header/myheader.h"

class LT2536
{
public:


    // D D

    //vector<vector<int>> v(n, vector<int>(n, 0));
    //for (int i = 0; i < queries.size(); i++) {
    //    int x1 = queries[i][0];
    //    int y1 = queries[i][1];
    //    int x2 = queries[i][2];
    //    int y2 = queries[i][3];
    //    v[x1][y1] += 1;
    //    if (y2 + 1 < n) v[x1][y2 + 1] += -1;
    //    if (x2 + 1 < n) v[x2 + 1][y1] += -1;
    //    if (x2 + 1 < n && y2 + 1 < n) v[x2 + 1][y2 + 1] += 1;
    //}
    //
    //for (int i = 0; i < v.size(); i++) {
    //    int sum = 0;
    //    for (int j = 0; j < v[i].size(); j++) {
    //        sum += v[i][j];
    //        if (i) {
    //            v[i][j] = sum + v[i - 1][j];
    //        }
    //        else {
    //            v[i][j] = sum;
    //        }
    //    }
    //}




    //Runtime295 ms
    //    Beats
    //    70.66 %
    //    Memory84.3 MB
    //    Beats
    //    61.42 %
    vector<vector<int>> lt2536a(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> vvi(n, vector<int>(n, 0));
        vector<int> vi(n, 0);
        vector<vector<int>> vv2(n);

        std::sort(begin(queries), end(queries));
        int qi = 0;
        int szq = queries.size();
        int val = 0;
        for (int i = 0; i < n; ++i)
        {
            while (qi < szq && queries[qi][0] <= i)
            {
                ++vi[queries[qi][1]];
                if (queries[qi][3] + 1 < n)
                    --vi[queries[qi][3] + 1];

                vv2[queries[qi][2]].push_back(qi);
                ++qi;
            }

            val = 0;
            for (int j = 0; j < n; ++j)
            {
                val += vi[j];
                vvi[i][j] = val;
            }

            for (int qidx : vv2[i])
            {
                --vi[queries[qidx][1]];
                if (queries[qidx][3] + 1 < n)
                    ++vi[queries[qidx][3] + 1];
            }
        }

        return vvi;
    }

};

int main()
{

    LT2536 lt;

    int n = 3;
    myvvi vv = { {1,1,2,2},{0,0,1,1} };


    myvvi v2 = lt.lt2536a(n, vv);

    for (myvi& v : v2)
    {
        for (int i : v)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}
