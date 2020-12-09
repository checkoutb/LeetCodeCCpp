
#include "../header/myheader.h"

class LT1624
{
public:

// D D

// 两个for 可以合并， else if (fst[s[i]] != -1) { ans = max(i - fst[s[i]], ans) }


//    int idx[26] = {}, res = -1;
//    for (auto i = 0; i < s.size(); ++i) {
//        if (idx[s[i] - 'a'] == 0)
//            idx[s[i] - 'a'] = i + 1;
//        res = max(res, i - idx[s[i] - 'a']);
//    }
// = i + 1;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest Substring Between Two Equal Characters.
//Memory Usage: 6.5 MB, less than 94.32% of C++ online submissions for Largest Substring Between Two Equal Characters.
    int lt1624a(string s)
    {
        int fst[123] = {0};
        int lst[123] = {0};
        for (int i = 0; i < s.size(); ++i)
        {
            if (fst[s[i]] == 0)
                fst[s[i]] = i;
            lst[s[i]] = i;
        }
        fst[s[0]] = 0;
        int ans = -1;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            ans = max(ans, lst[i] - fst[i] - 1);
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"aa", "abca", "zxcvb", "cabbac"};

    LT1624 lt;

    for (string& s : vs)
        cout<<lt.lt1624a(s)<<endl;

    return 0;
}
