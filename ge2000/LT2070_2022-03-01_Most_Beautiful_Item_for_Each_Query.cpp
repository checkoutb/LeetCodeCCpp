
#include "../header/myheader.h"

class LT2070
{
public:

// D D

//            result[i] = map.floorEntry(queries[i]).getValue();

//    sort(begin(items), end(items));
//    for (int i = 1; i < items.size(); ++i)
//        items[i][1] = max(items[i][1], items[i - 1][1]);
//    for (int i = 0; i < qs.size(); ++i) {
//        auto it = upper_bound(begin(items), end(items), vector<int>{qs[i], INT_MAX});
//        qs[i] = it == begin(items) ? 0 : (*prev(it))[1];
//    }


//Runtime: 495 ms, faster than 68.71% of C++ online submissions for Most Beautiful Item for Each Query.
//Memory Usage: 96.3 MB, less than 27.67% of C++ online submissions for Most Beautiful Item for Each Query.
// 感觉segment tree 也可以用，虽然不会写。而且有更简单的。。
    vector<int> lt2070a(vector<vector<int>>& items, vector<int>& queries)
    {
        map<int, int> map2;
        for (vector<int>& vi : items)
            map2[vi[0]] = max(map2[vi[0]], vi[1]);
        vector<int> ans(queries.size(), 0);
        map<int, int>::iterator it = map2.begin();
        int t2 = it->second;
        for (it++; it != map2.end(); it++)
        {
            t2 = max(t2, it->second);
            it->second = t2;
        }
        for (int i = 0; i < queries.size(); i++)
        {
            map<int, int>::iterator it = map2.upper_bound(queries[i]);
            if (it != begin(map2))
            {
                it = std::prev(it);
                ans[i] = it->second;
            }
        }
        return ans;
    }

};

int main()
{

    LT2070 lt;

    myvvi vv = {{1,2},{1,4},{1,111}};
    myvi q = {{1}};

    myvi v = lt.lt2070a(vv, q);

    showVectorInt(v);

    return 0;
}
