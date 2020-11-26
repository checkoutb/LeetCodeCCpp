
#include "../header/myheader.h"

class LT1452
{
public:

// D

// std::includes ， 要预先有序， 暴力
// set_intersection. 但我们不需要相同元素，只需要知道是否重叠。

// union-find.


// tle
    vector<int> lt1452a(vector<vector<string>>& favoriteCompanies)
    {
        unordered_map<string, unordered_set<int>> map2;
        for (int i = 0; i < favoriteCompanies.size(); ++i)
        {
            for (string& com : favoriteCompanies[i])
            {
                map2[com].insert(i);
            }
        }
        vector<int> ans;
        for (int i = 0; i < favoriteCompanies.size(); ++i)
        {
            vector<unordered_set<int>> vs;
            for (string& com : favoriteCompanies[i])
                vs.push_back(map2[com]);
            bool flag2 = false;
            for (int idx : vs[0])
            {
                if (idx == i)
                    continue;
                for (unordered_set<int>& st : vs)
                {
                    if (st.find(idx) == st.end())
                    {
                        goto AAA;
                    }
                }
                flag2 = true;
                break;

                AAA:
                continue;
            }
            if (!flag2)
                ans.push_back(i);
        }
        return ans;
    }

};

int main()
{
    vector<vector<string>> vvs = {{"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},{"google"},{"amazon"}};

    LT1452 lt;

    vector<int> v = lt.lt1452a(vvs);

    showVectorInt(v);

    return 0;
}
