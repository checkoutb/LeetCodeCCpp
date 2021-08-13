
#include "../header/myheader.h"

class LT1177
{
public:

// D D

//        int mask = 0;
//        vector<int> ps(1);
//        for (char c : s)
//            ps.push_back(mask ^= 1 << (c - 'a'));
//
//        vector<bool> r;
//        for (auto &q : queries) {
//            int odds = __builtin_popcount(ps[q[1] + 1] ^ ps[q[0]]);
//            r.push_back(q[2] >= odds / 2);
//        }
// 偶数次 xor = 0.

//The __builtin_popcount() function is for g++ only. For C++20 use popcount(). For other compilers use bitset<26>().count().


//            if((odd)/2 <= k)
//            {
//                ans.push_back(true);
//            }
//            else
//            {
//                ans.push_back(false);
//            }





//Runtime: 524 ms, faster than 33.33% of C++ online submissions for Can Make Palindrome from Substring.
//Memory Usage: 186.7 MB, less than 22.59% of C++ online submissions for Can Make Palindrome from Substring.
    vector<bool> lt1177b(string s, vector<vector<int>>& queries)
    {
        int sz1 = s.size();
        int sz2 = queries.size();
        vector<bool> ans(sz2);
        vector<vector<int>> vvi(sz1, vector<int>(26, 0));
        vvi[0][s[0] - 'a'] = 1;
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                vvi[i][j] = vvi[i - 1][j];
            }
            vvi[i][s[i] - 'a'] += 1;
        }
        for (int i = 0; i < sz2; ++i)
        {
            int st = queries[i][0];
            int en = queries[i][1];
            int chg = queries[i][2];

            ans[i] = canPalinb1(vvi, st, en, chg);
        }
        return ans;
    }

    bool canPalinb1(vector<vector<int>>& vvi, int st, int en, int chg)
    {
        vector<int> vi(26);
        if (st == 0)
        {
            vi = vvi[en];
        }
        else
        {
            for (int i = 0; i < 26; ++i)
            {
                vi[i] = vvi[en][i] - vvi[st - 1][i];
            }
        }
        int odd = 0;
        for (int i = 0; i < 26; ++i)
            odd += (vi[i] % 2);

        int t2 = odd - (en - st + 1) % 2;
        return ((t2) / 2 + (t2 % 2)) <= chg;
    }


// error   。。。   rearrange 改变位置。。
    vector<bool> lt1177a(string s, vector<vector<int>>& queries)
    {
        int sz1 = s.size();
        int sz2 = queries.size();
        vector<bool> ans(sz2);
        for (int i = 0; i < sz2; ++i)
        {
            int st = queries[i][0];
            int en = queries[i][1];
            int chg = queries[i][2];

            ans[i] = isPalinda1(s, st, en, chg);
        }
        return ans;
    }

    bool isPalinda1(string& s, int st, int en, int chg)
    {
        while (st < en)
        {
            if (s[st] != s[en])
            {
                chg--;
                if (chg < 0)
                    return false;
            }
            st++;
            en--;
        }
        return true;
    }

};

int main()
{

//    string s = "abcda";
//    myvvi vv = {{3,3,0},{1,2,0},{0,3,1},{0,3,2},{0,4,1}};

//    string s = "hunu";
//    myvvi vv = {{1,1,1},{2,3,0},{3,3,1},{0,3,2},{1,3,3},{2,3,1},{3,3,1},{0,3,0},{1,1,1},{2,3,0},{3,3,1},{0,3,1},{1,1,1}};

    string s = "lyb";
    myvvi vv = {{0,1,0},{2,2,1}};


    LT1177 lt;

    vector<bool> vb = lt.lt1177b(s, vv);

    for (bool b : vb)
        cout<<b<<", ";

    return 0;
}
