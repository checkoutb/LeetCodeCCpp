
#include "../header/myheader.h"

class LT1851
{
public:

// D

// 对 queries 也排序
// pri_q

// uf

// set


// gg
// 10^7 数组 配合 b的sort。

    vector<int> lt1851b(vector<vector<int>>& intervals, vector<int>& queries)
    {
        std::sort(begin(intervals), end(intervals), [](const vector<int>& v1, const vector<int>& v2){ return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v2[1]; });
//        std::lower_bound()
        vector<int> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); ++i)
        {
            int t2 = queries[i];
            vector<vector<int>>::iterator it = std::lower_bound(begin(intervals), end(intervals), t2,
                [](const vector<int>& v1, int t3){ return t3 <= v1[0]; });
            int ta = -1;
            if (it != end(intervals))
                ta = it->operator[](1) - it->operator[](0);
            else
            {
                it--;
                if (it->operator[](1) >= t2 && )

                continue;
            }
            if (it != begin(intervals))
            {

                it--;
            }


//            if (it != end(intervals))
//            {
//                int t4 = it->[1] - it->[0];
//
//            }
        }
        return ans;
    }



// tle.
    vector<int> lt1851a(vector<vector<int>>& intervals, vector<int>& queries)
    {
//        std::sort(begin(intervals), end(intervals), [](const vector<int>& v1, const vector<int>& v2){ return v1[]})
        std::sort(begin(intervals), end(intervals), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] - v1[0] < v2[1] - v2[0]; });
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
        {
            int t2 = queries[i];
            for (int j = 0; j < intervals.size(); ++j)
            {
                if (t2 >= intervals[j][0] && t2 <= intervals[j][1])
                {
                    ans.push_back(intervals[j][1] - intervals[j][0] + 1);
                    goto AAA;
                }
            }
            ans.push_back(-1);
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,4},{2,4},{3,6},{4,4}};
//    myvi q = {2,3,4,5};

    myvvi vv = {{2,3},{2,5},{1,8},{20,25}};
    myvi q = {2,19,5,22};

    LT1851 lt;

    myvi v = lt.lt1851b(vv, q);

    showVectorInt(v);

    return 0;
}
