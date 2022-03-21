
#include "../../header/myheader.h"

class LT
{
public:

// D D

//  vector<int> res, pos(26, 0);
//  for (auto i = 0; i < S.size(); ++i) pos[S[i] - 'a'] = i;
//  for (auto i = 0, idx = INT_MIN, last_i = 0; i < S.size(); ++i) {
//    idx = max(idx, pos[S[i] - 'a']);
//    if (idx == i) res.push_back(i - exchange(last_i, i + 1) + 1);
//  }
//  return res;
// 。。exchange。



//Runtime: 4 ms, faster than 72.57% of C++ online submissions for Partition Labels.
//Memory Usage: 6.7 MB, less than 64.08% of C++ online submissions for Partition Labels.
// char 只出现在一个 part 中。
    vector<int> lta(string s)
    {
        int arr[123] = {0};
        std::fill(begin(arr), end(arr), -1);
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (arr[s[i]] == -1)
            {
                arr[s[i]] = i;
            }
        }
        int lst = -1;
        vector<int> ans;
        int mxi = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (arr[s[i]] > mxi)
                mxi = arr[s[i]];

            if (i == mxi)
            {
                ans.push_back(i - lst);
                lst = i;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;

//    string s = "ababcbacadefegdehijhklij";

//    string s = "ecasedasdc";

    string s = "a";

    myvi v = lt.lta(s);

    showVectorInt(v);

    return 0;
}
