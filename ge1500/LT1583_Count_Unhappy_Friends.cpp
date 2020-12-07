
#include "../header/myheader.h"

class LT1583
{
public:

// D D






//Runtime: 148 ms, faster than 40.89% of C++ online submissions for Count Unhappy Friends.
//Memory Usage: 25.2 MB, less than 81.79% of C++ online submissions for Count Unhappy Friends.
// a b 是关系很很很好的， 但是 pair中 分开了。
    int lt1583a(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs)
    {
        unordered_map<int, unordered_set<int>> map2;        // person : friends
        for (vector<int>& p : pairs)
        {
            map2[p[0]].insert(p[1]);
            map2[p[1]].insert(p[0]);
        }
        for (int i = 0, mxi = pairs.size(); i < mxi; ++i)
            pairs.push_back({pairs[i][1], pairs[i][0]});
        int ans = 0;
        for (int i = 0, mxi = pairs.size(); i < mxi; ++i)
        {
            int st = pairs[i][0];
            int en = pairs[i][1];
            for (int j = 0, mxj = preferences[st].size(); j < mxj && preferences[st][j] != en; ++j)
            {
                int better = preferences[st][j];
                if (map2.find(better) == map2.end())
                    continue;
                unordered_set<int>& set2 = map2[better];
                for (int frnd : set2)
                {
                    for (int m = 0; m < preferences[better].size() && preferences[better][m] != frnd; ++m)
                    {
                        if (preferences[better][m] == st)
                        {
                            ans++;
                            goto AAA;
                        }
                    }
                }
            }
            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{
    myvvi vv = {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}};
    myvvi v2 = {{0,1},{2,3}};
    int n = 4;

//    myvvi vv = {{1},{0}};
//    myvvi v2 = {{1,0}};
//    int n = 2;

//    int n = 4;
//    myvvi vv = {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}};
//    myvvi v2 = {{1,3},{0,2}};

    LT1583 lt;

    cout<<lt.lt1583a(n,vv,v2);

    return 0;
}
