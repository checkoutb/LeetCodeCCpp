
#include "../header/myheader.h"

class LT1002
{
public:

// D D

//  vector<int> cnt(26, INT_MAX);
//  vector<string> res;
//  for (auto s : A) {
//    vector<int> cnt1(26, 0);
//    for (auto c : s) ++cnt1[c - 'a'];
//    for (auto i = 0; i < 26; ++i) cnt[i] = min(cnt[i], cnt1[i]);
//  }
//  for (auto i = 0; i < 26; ++i)
//    for (auto j = 0; j < cnt[i]; ++j) res.push_back(string(1, i + 'a'));
//  return res;
// 借助一个temp，一维数组就可以了。





//Runtime: 8 ms, faster than 99.37% of C++ online submissions for Find Common Characters.
//Memory Usage: 10.1 MB, less than 31.67% of C++ online submissions for Find Common Characters.
    vector<string> lt1002a(vector<string>& A)
    {
        vector<vector<int>> vv(A.size(), vector<int>(26, 0));
        for (int i = 0; i < A.size(); i++)
        {
            for (char ch : A[i])
            {
                vv[i][ch - 'a']++;
            }
        }
        for (int j = 0; j < 26; j++)
        {
            for (int i = 1; i < A.size(); i++)
            {
                vv[0][j] = min(vv[0][j], vv[i][j]);
            }
        }
        vector<string> ans;
        for (int j = 0; j < 26; j++)
        {
            for (int m = 0; m < vv[0][j]; m++)
            {
                ans.emplace_back(string(1, ((char) ('a' + j))));
            }
        }
        return ans;
    }

};

int main()
{

    vector<string> a = {"bella","label","roller"};

    LT1002 lt;

    vector<string> v = lt.lt1002a(a);

    for_each(begin(v), end(v), fun_cout_s);

    return 0;
}
