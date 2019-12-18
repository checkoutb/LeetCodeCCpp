
#include "../header/myheader.h"

class LT0472
{

public:


// discuss
// dp, 每次计算string时，建立一维数组，保存这个字符是否可以达到。。forfor 循环计算[i, j]是否存在，靠dp可以提前退出。


// [160, 700]ms.

//Runtime: 1356 ms, faster than 5.12% of C++ online submissions for Concatenated Words.
//Memory Usage: 95.3 MB, less than 16.67% of C++ online submissions for Concatenated Words.

    vector<string> ans;

    vector<string> lt0472a(vector<string>& words)
    {
        map<char, vector<string>> map1;
        for (string s : words)
        {
            map1[s[0]].push_back(s);
        }
        for (string s : words)
        {
            dfsa1(s, 0, map1, 0);
        }
        return ans;
    }

    bool dfsa1(string& s, int from, map<char, vector<string>>& map1, int lv)
    {

//        cout<<s<<", "<<from<<endl;

        if (from == s.size() && lv > 0)
        {
            ans.push_back(s);
            return true;
        }
        if (from > s.size())
            return false;

        vector<string>& vs2 = map1[s[from]];

//        cout<<vs2.size()<<endl;

        for (string s2 : vs2)
        {
            if (s2 == s)
                continue;
            if (partOf(s2, s, from))
            {
                if (dfsa1(s, from + s2.size(), map1, 1))
                    return true;
            }
        }
        return false;
    }

    bool partOf(string& s1, string& s2, int from2)
    {

//        cout<<s1<<", "<<s2<<", "<<from2<<endl;

        int sz1 = s1.size();
        if (sz1 > s2.size() - from2)
            return false;
        for (int i = 0; i < sz1; i++)
        {
            if (s1[i] != s2[from2 + i])
                return false;
        }
        return true;
    }
};

int main()
{
    vector<string> v = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};

    LT0472 lt;

    vector<string> ans = lt.lt0472a(v);

    cout<<endl;
    for_each(ans.begin(), ans.end(), fun_cout_s);
    cout<<endl;

    return 0;
}
