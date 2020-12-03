
#include "../header/myheader.h"

class LT1544
{
public:

// D D


//    while (sz != s.size()) {
//        sz = s.size();
//        for (int i = 0; i + 1 < s.size(); ++i)
//            if (abs(s[i] - s[i + 1]) == 32)
//                s = s.substr(0, i) + s.substr(i + 2);
//    }
//    return s;


//    for (int i = 0; i < s.size(); ++i) {
//        if (p > 0 && abs(s[i] - s[p - 1]) == 32)
//            --p;
//        else
//            s[p++] = s[i];
//    }
//    return s.substr(0, p);




//Runtime: 4 ms, faster than 62.82% of C++ online submissions for Make The String Great.
//Memory Usage: 6.9 MB, less than 41.72% of C++ online submissions for Make The String Great.
    string lt1544a(string s)
    {
        stack<char> stk1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (stk1.empty())
            {
                stk1.push(s[i]);
                continue;
            }
            char tp = stk1.top();
            if (abs(s[i] - tp) == ('a' - 'A'))
            {
                stk1.pop();
            }
            else
            {
                stk1.push(s[i]);
            }
        }
        string ans;
        while (!stk1.empty())
        {
            ans += stk1.top();
            stk1.pop();
        }
        std::reverse(begin(ans), end(ans));
        return ans;

//        for (int i = 1; i < s.size(); ++i)
//        {
//            if (abs(s[i] - s[i - 1]) == ('a' - 'A'))          // abBA .. ->  aA.   a--A
//            {
//                s[i] = '-';
//                s[i - 1] = '-';
//            }
//        }
//        string ans;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] != '-')
//                ans += s[i];
//        }
//        return ans;
    }

};

int main()
{

    vector<string> vs = {"leEeetcode","abBAcC","s"};

    LT1544 lt;

    for (string& s : vs)
        cout<<lt.lt1544a(s)<<endl;

    return 0;
}
