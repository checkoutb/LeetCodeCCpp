
#include "../header/myheader.h"

class LT1233
{
public:


// D D

// 直接sort folder。。。可以的。字典顺序，保证了  父文件夹一定在 它的子文件夹之前。。

//        for(string &s:folder)
//            if(res.empty()
//               ||s.rfind(res.back(), 0) != 0
//               ||s[res.back().length()]!='/')
//                res.push_back(s);
// 而且 父文件夹之间在前面，确实可以 res.back ......


//Arrays.sort(folder, Comparator.comparing(s -> s.length()));
// 按长度也可以，不过 不能保证 父文件夹和子文件夹 连在一起。

// trie不必保存string， 只需要保存 bool 代表是否结束。 string 由父结点的 hashMap 的key 来表达。


//Runtime: 588 ms, faster than 21.04% of C++ online submissions for Remove Sub-Folders from the Filesystem.
//Memory Usage: 62.4 MB, less than 5.57% of C++ online submissions for Remove Sub-Folders from the Filesystem.
// trie?
    vector<string> lt1233a(vector<string>& folder)
    {
//        std::sort(begin(folder), end(folder), [](string& s1, string& s2){ return accumulate })
        unordered_map<string, int> map2;
        for (string& s : folder)
        {
            map2[s] = std::accumulate(begin(s), end(s), 0, [](int v, char ch) { return v + (ch == '/'); });
        }
        std::sort(begin(folder), end(folder), [&map2](string& s1, string& s2) { return map2[s1] < map2[s2]; });
//        #ifdef __test
//        for (auto& p : map2)
//            cout<<p.first<<" : "<<p.second<<endl;
//
//        for (string& s : folder)
//            cout<<s<<", ";
//        cout<<endl;
//        #endif // __test
        vector<string> ans;
//        unordered_set<string> set2;
        for (string& s : folder)
        {
            int st1 = 0;
            while ((st1 = s.find('/', st1 + 1)) != std::string::npos)
            {
                string subs = s.substr(0, st1);
                if (map2.find(subs) != map2.end())
                {
                    goto AAA;
                }
            }
            ans.push_back(s);

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

//    vector<string> vs = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
//    vector<string> vs = {"/a","/a/b/c","/a/b/d"};
    vector<string> vs = {"/a/b/c","/a/b/ca","/a/b/d"};

    LT1233 lt;

    vector<string> ans = lt.lt1233a(vs);

    for (string& s : ans)
        cout<<s<<endl;

    return 0;
}
