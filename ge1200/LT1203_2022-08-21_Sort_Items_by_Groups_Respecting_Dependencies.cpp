
#include "../header/myheader.h"

class LT1203
{
public:

    // D D


    //bool topSort(vector<unordered_set<int>>& al, int i, vector<int>& res, vector<int>& stat) {
    //    if (stat[i] != 0) return stat[i] == 2;
    //    stat[i] = 1;
    //    for (auto n : al[i])
    //        if (!topSort(al, n, res, stat)) return false;
    //    stat[i] = 2;
    //    res.push_back(i);
    //    return true;
    //}
    //vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
    //    vector<int> res_tmp, res(n), stat(n + 2 * m);
    //    vector<unordered_set<int>> al(n + 2 * m);
    //    for (auto i = 0; i < n; ++i) {
    //        if (group[i] != -1) {
    //            al[n + group[i]].insert(i);
    //            al[i].insert(n + m + group[i]);
    //        }
    //        for (auto j : beforeItems[i]) {
    //            if (group[i] != -1 && group[i] == group[j]) al[j].insert(i);
    //            else {
    //                auto ig = group[i] == -1 ? i : n + group[i];
    //                auto jg = group[j] == -1 ? j : n + m + group[j];
    //                al[jg].insert(ig);
    //            }
    //        }
    //    }
    //    for (int n = al.size() - 1; n >= 0; --n)
    //        if (!topSort(al, n, res_tmp, stat)) return {};
    //    reverse(begin(res_tmp), end(res_tmp));
    //    copy_if(begin(res_tmp), end(res_tmp), res.begin(), [&](int i) {return i < n; });
    //    return res;
    //}



//Runtime: 212 ms, faster than 50.43 % of C++ online submissions for Sort Items by Groups Respecting Dependencies.
//Memory Usage : 49.4 MB, less than 62.07 % of C++ online submissions for Sort Items by Groups Respecting Dependencies.
    // 同group的要在一起。
    // 前面要有哪些。
    // 先把before中出现的放前面。  before 的before 
    vector<int> lt1203a(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        //vector<int> uf(n, -1);

        //unordered_map<int, vector<int>> map2;           // <group, <item>>

        //for (int i = 0; i < group.size(); ++i)
        //{
        //    if (group[i] != -1)
        //        map2[group[i]].push_back()
        //}

        for (int i = 0; i < group.size(); ++i)
        {
            if (group[i] == -1)
                group[i] = m++;
        }

        vector<vector<int>> vvi(m);
        for (int i = 0; i < group.size(); ++i)
        {
            //if (group[i] != -1)
                vvi[group[i]].push_back(i);
        }
        unordered_map<int, unordered_set<int>> map2;       // <group, <prefix group>>
        unordered_map<int, unordered_set<int>> map3;        // suffix
        unordered_map<int, unordered_set<int>> map4;        // <item, prefix in same group>
        unordered_map<int, unordered_set<int>> map5;
        for (int i = 0; i < n; ++i)
        {
            if (beforeItems[i].empty())
                continue;
            
            for (int pfx : beforeItems[i])
            {
                if (group[i] == group[pfx])
                {
                    map4[i].insert(pfx);
                    map5[pfx].insert(i);
                }
                else
                {
                    map2[group[i]].insert(group[pfx]);
                    map3[group[pfx]].insert(group[i]);
                }
            }
        }

        //bool chg = true;
        int chg = -1;
        vector<int> ans(n);
        //unordered_set<int> set2;
        vector<bool> vst(m, false);
        int idx = 0;
        while ((chg != idx) && (idx < n))
        {
            chg = idx;

            for (int i = 0; i < m; ++i)
            {
                //if (set2.find(i) != set2.end())
                //    continue;
                if (vst[i])
                    continue;

                if (map2.find(i) == map2.end() || map2[i].empty())
                {
                    while (!vvi[i].empty())
                    {
                        for (int j = 0; j < vvi[i].size(); ++j)
                        {
                            if (map4.find(vvi[i][j]) == map4.end() || map4[vvi[i][j]].empty())
                            {
                                ans[idx++] = vvi[i][j];

                                if (map5.find(vvi[i][j]) != map5.end())
                                    for (int sfx : map5[vvi[i][j]])
                                        map4[sfx].erase(vvi[i][j]);

                                vvi[i].erase(begin(vvi[i]) + j);
                                goto AAA;
                            }
                        }

#ifdef __test
                        cout << "conflict...." << endl;
#endif

                        return {};

                        AAA:
                        continue;
                    }
                    vst[i] = true;

                    if (map3.find(i) != map3.end())
                        for (int sfx : map3[i])
                            map2[sfx].erase(i);

                }
            }

        }

#ifdef __test
        cout << idx << " ==? " << n << endl;
        showVectorInt(ans);
        showVectorInt(group);
#endif

        return idx == n ? ans : vector<int>();
        //return chg ? ans : {};
    }

};

int main()
{

    LT1203 lt;

    int n = 8;
    int m = 2;
    myvi v = { -1,-1,1,0,0,1,0,-1 };
    myvvi vv = { {},{6},{5},{6},{3,6},{},{4},{} };

    myvi v2 = lt.lt1203a(n, m, v, vv);

    showVectorInt(v2);

    return 0;
}
