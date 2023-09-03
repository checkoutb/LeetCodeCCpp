
#include "../../header/myheader.h"

class LT
{
public:


// D D
        // unordered_set<string_view> d(begin(D), end(D));
        // string_view t(s);


// Runtime234 ms
// Beats
// 38.20%
// Memory81.1 MB
// Beats
// 54.95%
    // sz1 < 51
    int minExtraChar(string s, vector<string>& dictionary)
    {
        int sz1 = s.size();
        vector<int> vi(sz1, INT_MAX);       // <= idx, min delete
        // vi[0] = 1;
        set<string> set2(begin(dictionary), end(dictionary));

        for (int i = 0; i < sz1; ++i)
        {
            vi[i] = i == 0 ? 1 : (vi[i - 1] + 1);      // delete all
            for (int j = 0; j <= i; ++j)     // substr [j, i]
            {
                if (set2.find(s.substr(j, i - j + 1)) != set2.end())
                {
                    vi[i] = min(vi[i], j == 0 ? 0 : vi[j - 1]);
                }
            }
        }

        #ifdef __test
        showVectorInt(vi);
        #endif

        return vi[sz1 - 1];
    }


};

int main()
{

    LT lt;

    vector<string> vs = {"leet","leetcode","code"};
    string s = "leetscode";

    cout<<lt.minExtraChar(s, vs)<<endl;

    return 0;
}
