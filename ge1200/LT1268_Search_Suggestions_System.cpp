
#include "../header/myheader.h"

class LT1268
{
public:


// D D

//        auto it = A.begin();
//        sort(it, A.end());
//        vector<vector<string>> res;
//        string cur = "";
//        for (char c : searchWord) {
//            cur += c;
//            vector<string> suggested;
//            it = lower_bound(it, A.end(), cur);
//            for (int i = 0; i < 3 && it + i != A.end(); i++) {
//                string& s = *(it + i);
//                if (s.find(cur)) break;
//                suggested.push_back(s);
//            }
//            res.push_back(suggested);
//        }
//        return res;
// sort后，直接搜索 前缀，然后 从前缀开始 添加3个。



//Runtime: 80 ms, faster than 67.18% of C++ online submissions for Search Suggestions System.
//Memory Usage: 51.1 MB, less than 51.66% of C++ online submissions for Search Suggestions System.
    vector<vector<string>> lt1268a(vector<string>& products, string searchWord)
    {
        std::sort(begin(products), end(products));
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); ++i)
        {
            vector<string> vs;
            for (string& s : products)
            {
                if (s[i] == searchWord[i])
                {
                    vs.push_back(s);
                }
            }
            vector<string> vss;
            for (int i = 0; i < 3 && i < vs.size(); ++i)
                vss.push_back(vs[i]);
            ans.push_back(vss);
            products = vs;
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {"mobile","mouse","moneypot","monitor","mousepad"};
    string s = "mouse";

    LT1268 lt;

    vector<vector<string>> ans = lt.lt1268a(vs, s);
    for (vector<string>& vs : ans)
    {
        for (string& s : vs)
            cout<<s<<", ";
        cout<<endl;
    }

    return 0;
}
