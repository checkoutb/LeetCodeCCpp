
#include "../header/myheader.h"
//#include "../header/mytool.h"
#include <sstream>

class LT0609
{
public:



//Runtime: 132 ms, faster than 97.88% of C++ online submissions for Find Duplicate File in System.
//Memory Usage: 45.3 MB, less than 60.48% of C++ online submissions for Find Duplicate File in System.
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        unordered_map<string, vector<string>> map2;
        vector<vector<string>> ans;
        for (string& path : paths)
        {
            vector<string> vs = splitMy(path);
            if (vs.size() <= 1)
                continue;

            string p = vs[0];
            for (int i = 1; i < vs.size(); i++)
            {
                string content = vs[i].substr(vs[i].find('('));
                map2[content].emplace_back(p + "/" + vs[i].substr(0, vs[i].find('(')));
            }
        }

        for (auto& p : map2)
        {
            if (p.second.size() <= 1)
                continue;
            ans.emplace_back(p.second);
        }
        return ans;
    }

//    vector<string> split1(string s)
//    {
//        istringstream iss(s);
//        vector<string> ans;
//        string st;
//        while (std::getline(iss, st, ' '))
//        {
//            ans.emplace_back(st);
//        }
//        return ans;
//    }

};

int main()
{

    vector<string> v = {"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};

    LT0609 lt;

    vector<vector<string>> vv = lt.findDuplicate(v);

    for (vector<string>& v1 : vv)
    {
        for_each(begin(v1), end(v1), fun_cout_s);
        cout<<endl;
    }

    return 0;
}
