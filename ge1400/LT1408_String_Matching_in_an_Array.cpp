
#include "../header/myheader.h"

class LT1408
{
public:

// D D





//Runtime: 4 ms, faster than 95.80% of C++ online submissions for String Matching in an Array.
//Memory Usage: 9.4 MB, less than 16.33% of C++ online submissions for String Matching in an Array.
    vector<string>  lt1408a(vector<string>& words)
    {
        string map2[31] = {};
        for (string& s : words)
        {
            map2[s.size()] += ("|" + s);
        }
        vector<string> ans;
        for (string& s : words)
        {
            for (int i = 30; i > s.size(); --i)
            {
                if (map2[i].size() == 0)
                    continue;
                if (map2[i].find(s) != std::string::npos)
                {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<string> vs = {"mass","as","hero","superhero"};
//    vector<string> vs = {"leetcode","et","code"};
    vector<string> vs = {"blue","green","bu"};

    LT1408 lt;

    vector<string> ans = lt.lt1408a(vs);

    for (string& s : ans)
        cout<<s<<", ";
    cout<<endl;

    return 0;
}
