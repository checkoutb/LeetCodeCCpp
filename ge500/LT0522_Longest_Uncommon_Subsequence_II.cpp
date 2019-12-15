
#include "../header/myheader.h"

class LT0522
{
public:





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Uncommon Subsequence II.
//Memory Usage: 8.9 MB, less than 50.00% of C++ online submissions for Longest Uncommon Subsequence II.
    int lt0522c(vector<string>& strs)
    {
        map<int, vector<string>> map2;
        for (string s : strs)
        {
            map2[s.size()].push_back(s);
        }
        for (map<int, vector<string>>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
            vector<string> vs = it->second;
            for (int i = 0; i < vs.size(); i++)             // 和下面合并。。。
            {
                bool hasSame = false;
                for (int j = 0; j < vs.size(); j++)
                {
                    if (j == i)
                        continue;
                    if (vs[i] == vs[j])
                    {
                        hasSame = true;
                        break;
                    }
                }
                if (hasSame)
                {
                    continue;
                }
                for (auto it2 = map2.rbegin(); it2 != map2.rend(); it2++)
                {
                    if (it2->first <= it->first)
                    {
                        return vs[i].size();
                    }
                    bool find2 = false;
                    for (string s : it2->second)
                    {
                        int j = 0;
                        int k = 0;
                        while (k < vs[i].size() && j < s.size())
                        {
                            if (vs[i][k] == s[j])
                            {
                                k++;
                            }
                            j++;
                        }
                        if (k == vs[i].size())
                        {
                            find2 = true;
                            break;
                        }
                    }
                    if (find2)
                        break;
                }
            }
        }
        return -1;
    }

    // error
    int lt0522b(vector<string>& strs)
    {
        set<int> skip;
        int sz1 = strs.size();
        for (int i = 0; i < sz1; i++)
        {
            if (skip.find(i) != skip.end())
                continue;
            for (int j = i + 1; j < sz1; j++)
            {
                if (skip.find(j) != skip.end())
                    continue;
                int t2 = lusb1(strs[i], strs[j]);
                if (t2 != -1)
                {

                }
            }
        }
    }

    int lusb1(string a, string b)
    {
        return a.size() == b.size() ? (a == b ? -1 : a.size()) : std::max(a.size(), b.size());
    }

    // error
    int lt0522a(vector<string>& strs)
    {
        int sz1 = strs[0].size();
        int sz2 = sz1;
        set<char> set2;
        for (string s : strs)
        {
            int sz3 = s.size();
            sz1 = std::max(sz1, sz3);
            sz2 = std::min(sz2, sz3);
            for (char c : s)
            {
                set2.insert(c);
            }
        }
        if (sz1 != sz2)
        {
            return set2.size() == 1 ? -1 : sz1;
        }
        set<int> skip;
        for (int i = 0; i < strs.size(); i++)
        {
            if (skip.find(i) != skip.end())
                continue;
            int sz4 = skip.size();
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (strs[j] == strs[i])
                    skip.insert(j);
            }
            if (sz4 == skip.size())
                return strs[i].size();
        }
        return -1;
    }
};

int main()
{
    vector<string> v = {"aabbcc","aabbcc","cb"};

    LT0522 lt;
    cout<<lt.lt0522c(v)<<endl;

    return 0;
}
