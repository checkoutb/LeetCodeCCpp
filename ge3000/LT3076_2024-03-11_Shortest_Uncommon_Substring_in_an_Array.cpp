
#include "../header/myheader.h"

class LT3076
{
public:

// D D

        // const int n = arr.size();
        // vector<string> r(n);
        // for (int i = 0; i < n; ++i) {
        //     for (int len = 1; r[i].empty() && len <= arr[i].length(); ++len) {
        //         for (int b = 0; b + len <= arr[i].length(); ++b) {
        //             const string s = arr[i].substr(b, len);
        //             bool found = false;
        //             for (int j = 0; !found && j < n; ++j) {
        //                 found = j != i && arr[j].find(s) != string::npos;
        //             }
        //             if (!found && (r[i].empty() || r[i] > s)) {
        //                 r[i] = s;
        //             }
        //         }
        //     }
        // }


    // Trie



// Runtime
// 282ms
// Beats60.00%of users with C++
// Memory
// 100.34MB
// Beats20.00%of users with C++
    // 20
    vector<string> shortestSubstrings(vector<string>& arr)
    {
        int sz1 = arr.size();
        vector<string> ans(sz1, "");
        int cnt = sz1;
        for (int len = 1; len <= 20 && cnt > 0; ++len)
        {
            map<string, int> map2;
            for (int i = 0; i < sz1; ++i)
            {
                for (int j = 0; j + len <= arr[i].size(); ++j)
                {
                    string s2 = arr[i].substr(j, len);
#ifdef __test
                    std::cout<<"         "<<j<<" "<<len<<"  "<<s2<<endl;
#endif
                    if (map2.contains(s2) && map2[s2] != i) {           // .. && != i
                        map2[s2] = -1;
                    } else {
                        map2[s2] = i;
                    }
                }
            }

            if (map2.empty())       // no string >= len
                break;

            vector<pair<string, int>> vp;
            for (pair<string, int> p : map2)
            {
#ifdef __test
                // cout<<p.first<<" : "<<p.second<<"\n";
#endif

                if (p.second >= 0)
                {
                    vp.push_back(p);
                }
            }
            std::sort(begin(vp), end(vp));
            for (int i = 0; i < vp.size(); ++i)
            {
                if (ans[vp[i].second].size() == 0)
                {
                    ans[vp[i].second] = vp[i].first;
                    --cnt;
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT3076 lt;

    // vector<string> vs {"cab","ad","bad","c"};
    vector<string> vs {
        "tqnf","wrb","uke","d",
        "eq","nuhyoq"};

    vs = lt.shortestSubstrings(vs);

    for(string& s : vs)
    {
        cout<<" -- "<<s<<endl;
    }

    return 0;
}
