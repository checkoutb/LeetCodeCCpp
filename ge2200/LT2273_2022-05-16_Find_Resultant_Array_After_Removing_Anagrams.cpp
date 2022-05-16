
#include "../header/myheader.h"

class LT2273
{
public:

// D D






//Runtime: 12 ms, faster than 85.71% of C++ online submissions for Find Resultant Array After Removing Anagrams.
//Memory Usage: 13.1 MB, less than 35.71% of C++ online submissions for Find Resultant Array After Removing Anagrams.
// 2个连续的 异构体。
    vector<string> lt2273a(vector<string>& words)
    {
        int sz1 = words.size();
        vector<string> vs(begin(words), end(words));
        for (int i = 0; i < sz1; ++i)
        {
            std::sort(begin(vs[i]), end(vs[i]));
        }
        stack<int> stk;
        for (int i = words.size() - 1; i >= 0; --i)
        {
            while ((!stk.empty()) && (vs[i] == vs[stk.top()]))      // delete 的是后面的
            {
                stk.pop();
            }
            stk.push(i);

//            if (stk.empty())
//            {
//                stk.push(i);
//                continue;
//            }
//            while ()
        }

        vector<string> ans;
        while (!stk.empty())
        {
            ans.push_back(words[stk.top()]);
            stk.pop();
        }
        return ans;


//        for (int i = 0; i <)
//        // or map?
//        stack<pair<int, string>> stk;
//        for (int i = words.size() - 1; i >= 0; --i)
//        {
//            if (stk.empty())
//            {
//
//            }
//        }

//        stack<int> stk;
//        for (int i = words.size() - 1; i >= 0; --i)
//        {
//            if (stk.empty())
//            {
//                stk.push(i);
//                continue;
//            }
//            int idx = stk.top();
//
//        }
    }

};

int main()
{

    LT2273 lt;

//    vector<string> vs = {"abba","baba","bbaa","cd","cd"};
    vector<string> vs = {"a","b","c"};

    vector<string> ans = lt.lt2273a(vs);

    for(string& s : ans)
    {
        cout<<s<<endl;
    }

    return 0;
}
