
#include "../header/myheader.h"

class LT1593
{
public:

// D D

//    for (int sz = 1; p + sz <= s.size(); ++sz) {
//        auto it = st.insert(s.substr(p, sz));
//        if (it.second) {
//            int n_res = maxUniqueSplit(s, p + sz);
//            if (n_res != -1)
//                res = max(res, 1 + n_res);
//            st.erase(it.first);
//        }
//    }




//Runtime: 544 ms, faster than 33.14% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.
//Memory Usage: 44.4 MB, less than 55.10% of C++ online submissions for Split a String Into the Max Number of Unique Substrings.
    int lt1593a(string s)
    {
        unordered_set<string> set2;
        for (int i = 0; i < s.size(); ++i)
        {
            string s1 = s.substr(0, i + 1);
            set2.insert(s1);
            dfsa1(s, set2, i + 1);
            set2.erase(s1);
        }
        return ans;
    }
    int ans = 1;
    void dfsa1(string& s, unordered_set<string>& set2, int st)
    {
        if (s.size() == st)
        {
            ans = max(ans, (int) set2.size());
            return;
        }
        for (int i = st; i < s.size(); ++i)
        {
            string s1 = s.substr(st, i - st + 1);
            if (set2.find(s1) != set2.end())
                continue;
            set2.insert(s1);
            dfsa1(s, set2, i + 1);
            set2.erase(s1);
        }
    }

};

int main()
{

    vector<string> vs = {"ababccc", "aba", "aa"};

    LT1593 lt;

    for (string& s : vs)
    {
        lt.ans = 1;
        cout<<lt.lt1593a(s)<<endl;
    }
    return 0;
}
