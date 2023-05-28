
#include "../../header/myheader.h"

class LT6456
{
public:



    // AC

    // tle
    //
    int maxIncreasingCells(vector<vector<int>>& mat)
    {
        int sz1 = mat.size();
        int sz2 = mat[0].size();
        int ans = 0;
        vector<vector<int>> vvi(sz1, vector<int>(sz2, -1));

        vector<vector<pair<int, int>>> vvr(sz1);
        vector<vector<pair<int, int>>> vvc(sz2);

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvr[i].push_back(std::make_pair(mat[i][j], j));
                vvc[j].push_back(std::make_pair(mat[i][j], i));
            }
        }
        for (int i = 0; i < sz1; ++i)
        {
            sort(begin(vvr[i]), end(vvr[i]));
        }
        for (int j = 0; j < sz2; ++j)
        {
            sort(begin(vvc[j]), end(vvc[j]));
        }

        #ifdef __test
        for (vector<pair<int, int>>& vp : vvr)
        {
            for (pair<int, int>& p : vp)
            {
                cout<<p.first<<"+"<<p.second<<", ";
            }
            cout<<endl;
        }
        cout<<endl;

        for (vector<pair<int, int>>& vp : vvc)
        {
            for (pair<int, int>& p : vp)
            {
                cout<<p.first<<"+"<<p.second<<", ";
            }
            cout<<endl;
        }
        cout<<endl;
        #endif // __test

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                //ans = max(ans, dfsa1(mat, vvi, i, j));
                ans = max(ans, dfsa2(mat, vvi, i, j, vvr, vvc));
            }
        }
        return ans;
    }

    int dfsa2(vector<vector<int>>& mat, vector<vector<int>>& vvi, int i, int j,
                vector<vector<pair<int, int>>>& vvr, vector<vector<pair<int, int>>>& vvc)
    {
        if (vvi[i][j] != -1)
            return vvi[i][j];

            #ifdef __test
            cout<<i<<", "<<j<<endl;
//            getchar();
            #endif // __test


        int t3 = mat[i][j];
        int t2 = 0;

//        cout<<t3<<endl;

        auto it = std::upper_bound(begin(vvr[i]), end(vvr[i]), std::make_pair(t3, int(mat[0].size())));             //  int(mat[0].size())
        //if (it != vvr[i].end())

        int t4 = INT_MIN;
        for (; it != vvr[i].end(); it++)                    // ........
        {
            if (t4 == INT_MIN)
            {
                t4 = it->first;
            }
            else
            {
                if (it->first > t4)
                    break;
            }
            t2 = max(t2, dfsa2(mat, vvi, i, it->second, vvr, vvc));
        }

        t4 = INT_MIN;
        it = std::upper_bound(begin(vvc[j]), end(vvc[j]), std::make_pair(t3, int(mat.size())));
        //if (it != vvc[j].end())
        for (; it != vvc[j].end(); it++)
        {
            if (t4 == INT_MIN)
                t4 = it->first;
            else if (it->first != t4)
                break;

            t2 = max(t2, dfsa2(mat, vvi, it->second, j, vvr, vvc));
        }

        return vvi[i][j] = t2 + 1;
    }

    int dfsa1(vector<vector<int>>& mat, vector<vector<int>>& vvi, int i, int j)
    {
        if (vvi[i][j] != -1)
            return vvi[i][j];

        int t2 = 0;
        int t3 = mat[i][j];
        for (int idx = 0; idx < mat.size(); ++idx)
        {
            if (mat[idx][j] > t3)
                t2 = max(t2, dfsa1(mat, vvi, idx, j));
        }
        for (int idx = 0; idx < mat[0].size(); ++idx)
        {
            if (mat[i][idx] > t3)
                t2 = max(t2, dfsa1(mat, vvi, i, idx));
        }

        return vvi[i][j] = t2 + 1;
    }

};

int main()
{

    LT6456 lt;

    //myvvi vv = {{3,1},{3,4}};
    //myvvi vv = {{3,1,6},{-9,5,7}};
    myvvi vv = {{7,6,3},{-7,-5,6},{-7,0,-4},{6,6,0},{-8,6,0}};

    cout<<lt.maxIncreasingCells(vv)<<endl;

    return 0;
}
