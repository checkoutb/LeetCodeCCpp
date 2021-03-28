
#include "../../header/myheader.h"

class LT5714
{
public:




// AC
// 没有嵌套。

// 会出现 (a(z))qwe 这种吗。。就是 ()嵌套。
    string lt5714a(string s, vector<vector<string>>& knowledge)
    {
        unordered_map<string, string> map2;
        for (vector<string>& vs : knowledge)
            map2[vs[0]] = vs[1];

        string ans;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != '(')
            {
                ans.push_back(s[i]);
            }
            else
            {
                string subs;
                for (++i; s[i] != ')'; ++i)
                {
                    subs.push_back(s[i]);
                }
                if (map2.find(subs) != map2.end())
                {
                    ans.append(map2[subs]);
                }
                else
                {
                    ans.push_back('?');
                }
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "(name)is(age)yearsold";
//    vector<vector<string>> vvs = {{"name","bob"},{"age","two"}};

//    string s = "her(name)plz";
//    vector<vector<string>> vvs = {{"a","b"}};

//    string s = "(a)(a)(a)aaa";
//    vector<vector<string>> vvs = {{"a","yes"}};

    string s = "(a)(b)";
    vector<vector<string>> vvs = {{"a","b"},{"b","a"}};

    LT5714 lt;

    cout<<lt.lt5714a(s,vvs)<<endl;

    return 0;
}
