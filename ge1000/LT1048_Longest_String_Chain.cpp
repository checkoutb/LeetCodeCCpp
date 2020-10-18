
#include "../header/myheader.h"

class LT1048
{
public:


// D D

//dp[w] = max(dp[w], dp[w.substr(0, i) + w.substr(i + 1)] + 1);





//Runtime: 120 ms, faster than 81.86% of C++ online submissions for Longest String Chain.
//Memory Usage: 19.8 MB, less than 7.09% of C++ online submissions for Longest String Chain.
    int lt1048a(vector<string>& words)
    {
        map<int, vector<string>> map2;
        unordered_map<string, int> map3;
        for (string& s : words)
        {
            map2[s.size()].emplace_back(s);
            map3[s] = 1;
        }
//        #ifdef __test
//        for (auto& p : map2)
//        {
//            cout<<p.first<<" : ";
//            for (string& s : p.second)
//            {
//                cout<<s<<", ";
//            }
//            cout<<endl;
//        }
//        #endif // __test
        for (auto& p : map2)
        {
            int sz1 = p.first;
            vector<string>& vs = p.second;
            if (map2.find(sz1 + 1) == map2.end())       // .
                continue;
            vector<string>& vs2 = map2[sz1 + 1];
            for (string& s : vs)
            {
                for (string& s2 : vs2)
                {
                    if (map3[s] >= map3[s2])
                    {
                        int dif = 0;
                        for (int i = 0; i < sz1; i++)
                        {
                            if (s[i] != s2[i + dif])
                            {
                                dif++;
                                if (dif > 1)
                                    break;
                                if (s[i] != s2[i + dif])        // .最开始没有，后来是 i==sz1-1 && s[i]!=s2[i+dif]. 为什么i==sz1-1加上会错。
                                {
                                    dif++;
                                    break;
                                }
                            }
                        }
                        if (dif <= 1)
                        {
                            map3[s2] = map3[s] + 1;
                        }
                    }
                }
            }
        }
        int ans = 0;
        for (auto& p : map3)
        {
            ans = max(ans, p.second);
//            cout<<p.first<<" : "<<p.second<<endl;
        }
        return ans;
    }

};

int main()
{

//    vector<string> v = {"a","b","ba","bca","bda","bdca"};
//    vector<string> v = {"qyssedya","pabouk","mjwdrbqwp","vylodpmwp",
//    "nfyqeowa","pu","paboukc","qssedya","lopmw","nfyqowa","vlodpmw","mwdrqwp","opmw",
//    "qsda","neo","qyssedhyac","pmw","lodpmw","mjwdrqwp","eo","nfqwa","pabuk","nfyqwa",
//    "qssdya","qsdya","qyssedhya","pabu","nqwa","pabqoukc","pbu","mw","vlodpmwp","x","xr"};

    LT1048 lt;

    cout<<lt.lt1048a(v)<<endl;

    return 0;
}
