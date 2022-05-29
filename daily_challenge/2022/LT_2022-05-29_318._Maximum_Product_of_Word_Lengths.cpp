
#include "../../header/myheader.h"

class LT
{
public:


// Runtime: 32 ms, faster than 99.61% of C++ online submissions for Maximum Product of Word Lengths.
// Memory Usage: 16.3 MB, less than 49.36% of C++ online submissions for Maximum Product of Word Lengths.
    int lta(vector<string>& words)
    {
        unordered_map<int, int> map2;
        for (string& s : words)
        {
            int t2 = 0;
            for (char ch : s)
            {
                t2 |= (1 << (ch - 'a'));
            }
            if (map2[t2] < s.size())
            {
                map2[t2] = (int) s.size();
            }
        }
        int ans = 0;
        for (unordered_map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            unordered_map<int, int>::iterator it2 = it;
#ifdef __test
            cout << &it << ", " << &it2 << endl;
#endif
            it2++;
            while (it2 != end(map2))
            {
                if ((it2->first & it->first) == 0)
                {
                    ans = std::max(it2->second * it->second, ans);
                }
                it2++;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;

    vector<string> vs{ "abcw","baz","foo","bar","xtfn","abcdef" };

    cout << lt.lta(vs) << endl;

    return 0;
}
