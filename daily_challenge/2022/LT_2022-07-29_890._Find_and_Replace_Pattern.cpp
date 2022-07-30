
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //vector<string> findAndReplacePattern(vector<string> words, string p) {
    //    vector<string> res;
    //    for (string w : words) if (F(w) == F(p)) res.push_back(w);
    //    return res;
    //}

    //string F(string w) {
    //    unordered_map<char, int> m;
    //    for (char c : w) if (!m.count(c)) m[c] = m.size();
    //    for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
    //    return w;
    //}






//Runtime: 4 ms, faster than 76.53 % of C++ online submissions for Findand Replace Pattern.
//Memory Usage : 7.9 MB, less than 95.56 % of C++ online submissions for Findand Replace Pattern.
    vector<string> lta(vector<string>& words, string pattern)
    {
        char arr[26] = { 0 };
        bool arr2[26] = { false };
        vector<string> ans;
        int sz1 = pattern.size();
        for (string& s : words)
        {
            fill(begin(arr), end(arr), 0);
            fill(begin(arr2), end(arr2), false);

            for (int i = 0; i < sz1; ++i)
            {
                char t = pattern[i];;
                char src = s[i];
                if (arr[src - 'a'] != 0)
                {
                    src = arr[src - 'a'];
                    if (src != t)
                    {
                        goto AAA;
                    }
                }
                else
                {
                    if (src != t)
                    {
                        if (arr2[t - 'a'])
                            goto AAA;
                    }
                    arr[src - 'a'] = t;
                    arr2[t - 'a'] = true;
                }
            }
            ans.push_back(s);

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
