
#include "../header/myheader.h"

class LT2559
{
public:

    // D D

    //unordered_set<char> vw({ 'a', 'e', 'i', 'o', 'u' });
    //vector<int> ps(1), res;
    //for (const auto& w : ws)
    //    ps.push_back(ps.back() + (vw.count(w.front()) && vw.count(w.back())));
    //for (const auto& q : queries)
    //    res.push_back(ps[q[1] + 1] - ps[q[0]]);


    //Runtime152 ms
    //    Beats
    //    100 %
    //    Memory63.3 MB
    //    Beats
    //    100 %
    vector<int> lt2559a(vector<string>& words, vector<vector<int>>& queries)
    {
        int sz1 = words.size();
        int szq = queries.size();

        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size() - 1]))
                vi[i] = 1;
        }
        for (int i = 1; i < sz1; ++i)
        {
            vi[i] += vi[i - 1];
        }

        vector<int> ans(szq);
        int st, en;
        for (int i = 0; i < szq; ++i)
        {
            st = queries[i][0];
            en = queries[i][1];

            ans[i] = vi[en] - (st == 0 ? 0 : vi[st - 1]);
        }

        return ans;
    }

    bool isVowel(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

};

int main()
{

    LT2559 lt;

    //vector<string> vs = { "aba","bcb","ece","aa","e" };
    //myvvi vv = { {0,2},{1,4},{1,1} };

    vector<string> vs = { "a","e","i" };
    myvvi vv = { {0,2},{0,1},{2,2} };

    myvi v = lt.lt2559a(vs, vv);

    showVectorInt(v);

    return 0;
}
