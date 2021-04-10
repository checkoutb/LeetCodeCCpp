
#include "../header/myheader.h"

class LT1817
{
public:

// D D





//Runtime: 216 ms, faster than 95.06% of C++ online submissions for Finding the Users Active Minutes.
//Memory Usage: 85.4 MB, less than 69.51% of C++ online submissions for Finding the Users Active Minutes.
    vector<int> lt1817a(vector<vector<int>>& logs, int k)
    {
        unordered_map<int, unordered_set<int>> map2;
        for (vector<int>& vi : logs)
        {
            map2[vi[0]].insert(vi[1]);
        }
        vector<int> ans(k, 0);
        for (auto& p : map2)
        {
            ans[p.second.size() - 1]++;
        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{1,1},{2,2},{2,3}};
    int k = 4;

    LT1817 lt;

    myvi v = lt.lt1817a(vv, k);
    showVectorInt(v);

    return 0;
}
