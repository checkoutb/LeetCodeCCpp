
#include "../header/myheader.h"

class LT0811
{
public:

// D D
// 手动for遍历的比较多


//Runtime: 32 ms, faster than 42.71% of C++ online submissions for Subdomain Visit Count.
//Memory Usage: 11.8 MB, less than 100.00% of C++ online submissions for Subdomain Visit Count.
    vector<string> lt0811a(vector<string>& cpdomains)
    {
        map<string, int> map1;
        for (string s : cpdomains)
        {
            int i = s.find(' ');
            string cntstr = s.substr(0, i);
            int cnt = std::stoi(cntstr);
            string site = s.substr(i + 1);
            map1[site] += cnt;
            while((i = s.find('.', i + 1)) != std::string::npos)
            {
                site = s.substr(i + 1);
                map1[site] += cnt;
            }
        }
        vector<string> ans;
        for (auto p : map1)
        {
            string s2 = std::to_string(p.second) + ' ' + p.first;
            ans.push_back(s2);
        }
        return ans;
    }

};

int main()
{

//    vector<string> cp = {"9001 discuss.leetcode.com"};

    vector<string> cp = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    LT0811 lt;

    vector<string> ans = lt.lt0811a(cp);

    for_each(ans.begin(), ans.end(), fun_cout_s);
    cout<<endl;

    return 0;
}
