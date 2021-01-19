
#include "../header/myheader.h"

class LT1208
{
public:

// D D

//            accrued_cost += abs(s[r] - t[r]);
//            ++r;
//            while (l < r && accrued_cost > maxCost) {
//                accrued_cost -= abs(s[l] - t[l]);
//                ++l;
//            }
//            max_len = max(max_len, r - l);

//  auto i = 0, j = 0;
//  while (i < s.size()) {
//    maxCost -= abs(s[i] - t[i++]);
//    if (maxCost < 0) maxCost += abs(s[j] - t[j++]);
//  }
//  return i - j;
// 每次循环，j最多++一次， 所以 i,j 距离越来越大。


//Runtime: 8 ms, faster than 78.35% of C++ online submissions for Get Equal Substrings Within Budget.
//Memory Usage: 8.3 MB, less than 26.78% of C++ online submissions for Get Equal Substrings Within Budget.
    int lt1208a(string s, string t, int maxCost)
    {
        vector<int> vi(s.size());
        for (int i = 0; i < s.size(); ++i)
        {
            vi[i] = abs(s[i] - t[i]);
        }
        int ans = 0;
        int st = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            maxCost -= vi[i];
            while (maxCost < 0)
            {
                maxCost += vi[st];
                st++;
            }
            ans = max(ans, i - st + 1);
        }
        ans = max(ans, int (s.size()) - st);
        return ans;
    }

};

int main()
{
//    string s{"abcd"}, t{"bcdf"};
    string s{"abcd"}, t{"cdef"};
    int mc = 3;

    LT1208 lt;

    cout<<lt.lt1208a(s,t,mc);

    return 0;
}
