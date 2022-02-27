
#include "../header/myheader.h"

class LT2055
{
public:

// D D

//        for (int i = 0; i < s.size(); ++i)
//            if (s[i] == '|')
//                A.push_back(i);
//        for (int q = 0; q < queries.size(); ++q) {
//            int i = lower_bound(A.begin(), A.end(), queries[q][0]) - A.begin();
//            int j = upper_bound(A.begin(), A.end(), queries[q][1]) - A.begin() - 1;
//            res.push_back(i < j ? (A[j] - A[i]) - (j - i) : 0);
//        }
// nb,aj-ai 是 ||包围的substr 的长度, j-i 是 | 的个数。





//Runtime: 665 ms, faster than 54.88% of C++ online submissions for Plates Between Candles.
//Memory Usage: 142.3 MB, less than 61.92% of C++ online submissions for Plates Between Candles.
    vector<int> lt2055a(string s, vector<vector<int>>& queries)
    {
        int sz1 = s.size();
        vector<int> vr(sz1);        // *'s right |  | is self
        vector<int> vl(sz1);        // *'s left |
        vector<int> v2(sz1);        // cnt(*) in |'s left
        int cnt = 0;
        int idx = -1;
        for (int i = 0; i < sz1; i++)
        {
            if (s[i] == '|')
            {
                v2[i] = cnt;
                idx = i;
                vl[i] = idx;
            }
            else
            {
                vl[i] = idx;
                cnt++;
            }
        }
        idx = sz1;
        for (int i = sz1 - 1; i >= 0; i--)
        {
            if (s[i] == '|')
            {
                idx = i;
                vr[i] = idx;
            }
            else
            {
                vr[i] = idx;
            }
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++)
        {
            int st = queries[i][0];
            int en = queries[i][1];
//            if (vl[en] == -1 || vr[st] == sz1)
            if (vl[en] <= vr[st])
                continue;
            ans[i] = v2[vl[en]] - v2[vr[st]];
        }
        return ans;
    }

};

int main()
{

    LT2055 lt;

    string s = "**|**|***|";
    myvvi vv = {{2,5},{5,9}};

//    string s = "***|**|*****|**||**|*";
//    myvvi vv = {{1,17},{4,5},{14,17},{5,11},{15,16}};

    myvi v = lt.lt2055a(s, vv);

    showVectorInt(v);

    return 0;
}
