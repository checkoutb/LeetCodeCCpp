
#include "../../header/myheader.h"

class LT
{
public:


// D D

// bool topSort(vector<unordered_set<int>>& al, int i, vector<int>& res, vector<int>& stat) {
//     if (stat[i] != 0) return stat[i] == 2;
//     stat[i] = 1;
//     for (auto n : al[i])
//         if (!topSort(al, n, res, stat)) return false;
//     stat[i] = 2;
//     res.push_back(i);
//     return true;
// }
// vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
//     vector<int> res_tmp, res(n), stat(n + 2 * m);
//     vector<unordered_set<int>> al(n + 2 * m);
//     for (auto i = 0; i < n; ++i) {
//         if (group[i] != -1) {
//             al[n + group[i]].insert(i);
//             al[i].insert(n + m + group[i]);
//         }
//         for (auto j : beforeItems[i]) {
//             if (group[i] != -1 && group[i] == group[j]) al[j].insert(i);
//             else {
//                 auto ig = group[i] == -1 ? i : n + group[i];
//                 auto jg = group[j] == -1 ? j : n + m + group[j];
//                 al[jg].insert(ig);
//             }
//         }
//     }
//     for (int n = al.size() - 1; n >= 0; --n)
//         if (!topSort(al, n, res_tmp, stat)) return {};
//     reverse(begin(res_tmp), end(res_tmp));
//     copy_if(begin(res_tmp), end(res_tmp), res.begin(), [&](int i) {return i < n; });
//     return res;
// }



// Runtime94 ms
// Beats
// 80.81%
// Memory51 MB
// Beats
// 59.30%

    // 一个组的在一起
    // items 在前面
    // 先把没有 beforeitem 的 排最前面。 然后
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems)
    {
        vector<vector<int>> vvi(m + n);     // group: items
        for (int i = 0; i < n; ++i)
        {
            if (group[i] != -1)
                vvi[group[i]].push_back(i);
            else
                vvi[i + m].push_back(i);
        }

        vector<set<int>> vv2(m + n);     // group: prefix groups
        set<int> set2;
        for (int i = 0; i < beforeItems.size(); ++i)
        {
            if (beforeItems[i].empty())
                continue;

            int gp1 = group[i] == -1 ? i + m : group[i];
            for (int j : beforeItems[i])
            {
                int gp2 = group[j] == -1 ? j + m : group[j];
                if (gp1 != gp2)
                    vv2[gp1].insert(gp2);
                else
                    set2.insert(gp1);
            }
        }

        for (int gp : set2)
        {
            if (!dfsa2(vvi[gp], beforeItems)) {
                return {};
            }
        }

        // for (int i = 0; i < m + n; ++i)
        // {
        //     if (vvi[i].empty())
        //         continue;
        //     for (int j = 0; j < vvi[i].size(); ++j)
        //     {
        //         if (group[vvi[i][j]] == -1)
        //             vv2[i].insert(vvi[i][j] + m);
        //         else
        //             vv2[i].insert(group[vvi[i][j]]);
        //     }
        //     vv2[i].erase(i);
        // }

        #ifdef __test
        for (int i = 0; i < m+n; ++i)
        {
            cout<<"gp-itm: "<<i<<" : ";
            for (int t2 : vvi[i])
                cout<<t2<<", ";
            cout<<endl;
        }
        cout<<"\n\n    ================= \n\n";
        for (int i = 0; i < m+n; ++i)
        {
            cout<<"gp-pfx: "<<i<<" : ";
            for (int t2 : vv2[i])
            {
                cout<<t2<<", ";
            }
            cout<<endl;
        }
        #endif

        vector<int> ans;
        set<int> gpset;
        set<int> gpsfx;
        for (int i = 0; i < m + n; ++i)
        {
            if (vvi[i].empty())
                continue;
            if (gpset.find(i) != gpset.end())
                continue;
            
            if (!dfsa1(n,m,vvi,vv2,i,gpset,gpsfx,ans))
            {
                #ifdef __test
                cout<<"-----"<<i<<endl;
                #endif
                return {};
            }
        }
        return ans;
    }

    bool dfsa2(vector<int>& vi, vector<vector<int>>& itemsfx)
    {
        vector<int> ans;
        set<int> set2(begin(vi), end(vi));
        set<int> set3;
        set<int> set4;
        for (int i : vi)
        {
            if (!dfsa3(i, itemsfx, set2, set3, set4, ans))
                return false;
        }
        vi = ans;
        return true;
    }

    bool dfsa3(int item, vector<vector<int>>& sfx, 
        set<int>& set2, set<int>& set3, set<int>& set4, vector<int>& ans)
    {
        if (set4.find(item) != set4.end())
            return false;
        if (set3.find(item) != set3.end())
            return true;

        set4.insert(item);
        for (int t2 : sfx[item])
        {
            if (set2.find(t2) == set2.end())
                continue;
            if (set3.find(t2) != set3.end())
                continue;
            if (!dfsa3(t2, sfx, set2, set3, set4, ans))
                return false;
        }
        set4.erase(item);
        set3.insert(item);

        ans.push_back(item);
        return true;
    }

    bool dfsa1(int n, int m, vector<vector<int>>& vvi, vector<set<int>>& vv2, 
        int gp, set<int>& gpset, set<int>& gpsfx, vector<int>& ans)
    {
        if (gpsfx.find(gp) != gpsfx.end())
            return false;
        gpsfx.insert(gp);
        
        for (set<int>::iterator it = vv2[gp].begin(); it != vv2[gp].end(); it++)
        {
            int t2 = *it;
            if (gpset.find(t2) != gpset.end())
                continue;
            if (!dfsa1(n,m,vvi,vv2,t2,gpset,gpsfx,ans))
                return false;
        }
        ans.insert(ans.end(), begin(vvi[gp]), end(vvi[gp]));
        gpset.insert(gp);
        gpsfx.erase(gp);
        return true;
    }

};

int main()
{

    LT lt;

    int n{8},m{2};
    myvi gp = {-1,-1,1,0,0,1,0,-1};
    myvvi bf = {{},{6},{5},{6},{3,6},{},{},{}};

    myvi v2 = lt.sortItems(n,m,gp,bf);

    showVectorInt(v2);

    return 0;
}
