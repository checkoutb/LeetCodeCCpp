
#include "../header/myheader.h"

class LT1957
{
public:

// D D

//        for(char c : s){
//            int m = ans.size();
//            if(m < 2 || ans[m-1] != c || ans[m-2] != c){
//                ans.push_back(c);
//            }
//        }


//        int p = 0, cnt = 0;
//        char last = 0;
//        for (char c : s) {
//            if (c == last && cnt == 2) continue;
//            if (c != last) { last = c, cnt = 1; }
//            else { cnt += 1; }
//            s[p++] = c;
//        }
//        s.resize(p);


//    for (int i = 1, cnt = 1; i < s.size(); ++i) {
//        cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
//        if (cnt < 3)
//            s[j++] = s[i];
//    }
//    s.resize(j);





//Runtime: 140 ms, faster than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.
//Memory Usage: 41 MB, less than 16.67% of C++ online submissions for Delete Characters to Make Fancy String.
    string lt1957a(string s)
    {
        if (s.size() < 3)
            return s;
        string ans(begin(s), begin(s) + 2);
        for (int i = 2; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1] || s[i] != s[i - 2])
                ans.push_back(s[i]);
        }
        return ans;
    }

};

int main()
{
//    string s = "leeeeetcode";
//    string s = "aab";
//    string s = "a";
    string s = "aaaabbabbabbaaabbbb";

    LT1957 lt;

    cout<<lt.lt1957a(s)<<endl;

    return 0;
}
