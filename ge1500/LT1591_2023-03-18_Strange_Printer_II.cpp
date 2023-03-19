
#include "../header/myheader.h"

class LT1591
{
public:

    // D D




    //Runtime295 ms
    //    Beats
    //    8.57 %
    //    Memory22.6 MB
    //    Beats
    //    41.43 %
    bool lt1591a(vector<vector<int>>& targetGrid)
    {
        int sz1 = targetGrid.size();
        int sz2 = targetGrid[0].size();

        int mni[61] = { 0 };
        int mxi[61] = { 0 };
        int mnj[61] = { 0 };
        int mxj[61] = { 0 };

        for (int i = 1; i < 61; ++i)
        {
            mni[i] = mnj[i] = 100;
        }

        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                t2 = targetGrid[i][j];

                mni[t2] = min(mni[t2], i);
                mxi[t2] = max(mxi[t2], i);
                mnj[t2] = min(mnj[t2], j);
                mxj[t2] = max(mxj[t2], j);
            }
        }

        //vector<vector<int>> vvi(61);

        map<int, set<int>> map2;

        for (int k = 1; k < 61; ++k)
        {
            if (mni[k] == 100)
                continue;

            for (int i = mni[k]; i <= mxi[k]; ++i)
            {
                for (int j = mnj[k]; j <= mxj[k]; ++j)
                {
                    if (targetGrid[i][j] != k)
                        map2[k].insert(targetGrid[i][j]);
                }
            }
            map2[k].size();
        }

        bool chosen[61] = { false };
        bool chg = true;
        while (!map2.empty() && chg)
        {
            chg = false;

            for (map<int, set<int>>::iterator it = map2.begin(); it != map2.end(); )
            {
                for (set<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); )
                {
                    if (chosen[*it2])
                    {
                        it2 = it->second.erase(it2);
                    }
                    else
                    {
                        it2++;
                    }
                }
                if (it->second.empty())
                {
                    chg = true;
                    chosen[it->first] = true;
                    it = map2.erase(it);
                }
                else
                {
                    it++;
                }
            }

        }

        return map2.empty();
    }

};

int main()
{

    LT1591 lt;

    //myvvi vv = { {1,2,1},{2,1,2},{1,2,1} };
    //myvvi vv = { {1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4} };
    myvvi vv = { {1,1,1},{3,1,3} };


    cout << lt.lt1591a(vv) << endl;

    return 0;
}
