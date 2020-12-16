
#include "../header/myheader.h"

class LT0040
{
public:

// D D

//        int n=A.size(), i;
//        for(i=b; i<n; i++) {
//            if (i!=b && A[i]==A[i-1]) continue;
//            if (A[i]+s>t) break;
//            p.push_back(A[i]);
//            dfs(A, i+1, s+A[i], t, p, ret);
//            p.pop_back();
//        }




//Runtime: 4 ms, faster than 98.22% of C++ online submissions for Combination Sum II.
//Memory Usage: 12.5 MB, less than 36.00% of C++ online submissions for Combination Sum II.
// unique combinations
    vector<vector<int>> lt0040a(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        map<int, int> map2;
        for (int i : candidates)
            map2[i]++;
        vector<int> keys;
        for (map<int, int>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
            keys.push_back(it->first);
        }
        vector<int> path;
        dfsa1(map2, keys, 0, ans, path, target, false);
        return ans;
    }
    void dfsa1(map<int, int>& map2, vector<int>& keys, int idx, vector<vector<int>>& ans, vector<int>& path, int remain, bool hasParent)
    {
        if (remain == 0 && hasParent)
        {
            ans.push_back(path);
            return;
        }
        if (idx >= keys.size())
        {
            return;
        }
        if (remain < 0)
            return;
        int mx = map2[keys[idx]];
        dfsa1(map2, keys, idx + 1, ans, path, remain, false);
        for (int i = 1; i <= mx; ++i)
        {
            path.push_back(keys[idx]);
            dfsa1(map2, keys, idx + 1, ans, path, remain - i * keys[idx], true);
        }
        while (mx-- > 0)
            path.pop_back();
    }

};

int main()
{
    myvi v = {10,1,2,7,6,1,5};
    int t{8};

//    myvi v = {2,5,2,1,2};
//    int t{5};

//    myvi v = {2};
//    int t{1};

    LT0040 lt;

    myvvi vv = lt.lt0040a(v, t);

    for (myvi vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
