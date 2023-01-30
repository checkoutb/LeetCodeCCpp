
#include "../header/myheader.h"

class LT2497
{
public:

    // D D

    



    //Runtime334 ms
    //    Beats
    //    99.51 %
    //    Memory118.7 MB
    //    Beats
    //    81.54 %
    int lt2497a(vector<int>& vals, vector<vector<int>>& edges, int k)
    {
        int sz1 = vals.size();
        vector<vector<int>> vvi(sz1);

        for (vector<int>& vi : edges)
        {
            if (vals[vi[1]] > 0)
                vvi[vi[0]].push_back(vals[vi[1]]);
            if (vals[vi[0]] > 0)
                vvi[vi[1]].push_back(vals[vi[0]]);
        }
        int ans = INT_MIN;

        for (int i = 0; i < sz1; ++i)
        {
            //sort(rbegin(vvi[i]), rend(vvi[i]));
            if (vvi[i].size() <= k)
            {
                int t2 = vals[i] + std::accumulate(begin(vvi[i]), end(vvi[i]), 0);
                ans = max(t2, ans);
            }
            else
            {
                vector<int>::iterator it = begin(vvi[i]) + (vvi[i].size() - k);
                std::nth_element(begin(vvi[i]), it, end(vvi[i]));
                int t2 = vals[i] + std::accumulate(it, end(vvi[i]), 0);
                ans = max(t2, ans);
            }
        }

        return ans;
    }

};

int main()
{

    LT2497 lt;


    return 0;
}
