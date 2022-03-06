
#include "../header/myheader.h"

class LT2131
{
public:

// D D

//auto reversed = string(rbegin(w), rend(w));

//        array<int, 26 * 26> wordCounts{};
//        for (auto& w : words) {
//            int antiKey = 26 * (w[0] - 'a') + (w[1] - 'a');



// leetcode 的编译器实现 好像不一样。。 反正 这段代码，要换成 map 才能通过， 使用 unordered_map 的话， leetcode 的 会提前正常退出for。
//Runtime: 336 ms, faster than 88.89% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
//Memory Usage: 167.9 MB, less than 65.07% of C++ online submissions for Longest Palindrome by Concatenating Two Letter Words.
// ... 感觉 leetcode 的
    int lt2131a(vector<string>& words)
    {
        unordered_map<string, int> map2;
        for (string& s : words)
            map2[s]++;

//        cout<<map2.size()<<endl;
        int ans = 0;
        bool isll = false;
        for (unordered_map<string, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            if (it->second == 0)
                continue;
            string s = it->first;
            char ch = s[0];
            s[0] = s[1];
            s[1] = ch;
            int t2 = min(it->second, map2[s]);
//            cout<<s<<", "<<t2<<endl;
            if (s[0] == s[1])
            {
                if ((it->second) % 2)
                    isll = true;
                ans += 4 * (it->second / 2);
//                cout<<ans<<endl;
            }
            else
            {
                ans += 4 * (t2);
                it->second = 0;
                map2[s] = 0;
            }
        }
//        cout<<map2.size()<<endl;
        return ans + (isll ? 2 : 0);
    }

};

int main()
{

    LT2131 lt;

    vector<string> vs = {"oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig",
    "jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss",
    "tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo",
    "bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff",
    "ss","gi","yy","gb","mm","pp","uu","kk","jj","ee"};

    cout<<lt.lt2131a(vs)<<endl;

    return 0;
}
