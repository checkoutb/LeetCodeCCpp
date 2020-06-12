
#include "../header/myheader.h"

class LT0830
{
public:


// D D

// S += '.';   .....

//        for (int i = 0, j = 0; i < S.size(); i = j) {
//            while (j < S.size() && S[j] == S[i]) ++j;
//            if (j - i >= 3)
//                res.push_back({i, j - 1});
//        }

//    return [[r.start(), r.end() - 1] for r in re.finditer(r'(\w)\1{2,}', S)]




//Runtime: 4 ms, faster than 96.95% of C++ online submissions for Positions of Large Groups.
//Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Positions of Large Groups.
    vector<vector<int>> lt0830a(string S)
    {
        vector<vector<int>> ans;
        int len = 1;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == S[i - 1])
            {
                len++;
            }
            else
            {
                if (len >= 3)
                {
                    ans.push_back({i - len, i - 1});
                }
                len = 1;
            }
        }
        if (len >= 3)
            ans.push_back({(int) S.size() - len, (int) S.size() - 1});          // warning:unsigned long cannot convert to int
        return ans;
    }

};

int main()
{

//    string s = "abcdddeeeeaabbbcd";
    string s = "aaa";

    LT0830 lt;

    vector<vector<int>> ans = lt.lt0830a(s);

    for (auto p : ans)
    {
        for (auto i : p)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
