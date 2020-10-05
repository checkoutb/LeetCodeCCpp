
#include "../header/myheader.h"

class LT0696
{
public:


// D D


//        int cur = 1, pre = 0, res = 0;
//        for (int i = 1; i < s.size(); i++) {
//            if (s[i] == s[i - 1]) cur++;
//            else {
//                res += min(cur, pre);
//                pre = cur;
//                cur = 1;
//            }
//        }
//        return res + min(cur, pre);
// 2 int is enough.



//Runtime: 28 ms, faster than 97.00% of C++ online submissions for Count Binary Substrings.
//Memory Usage: 14.5 MB, less than 7.35% of C++ online submissions for Count Binary Substrings.
    int lt0696a(string s)
    {
        vector<int> v;
        int len = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] != s[i - 1])
            {
                v.push_back(len);
                len = 0;
            }
            len++;
        }
        v.push_back(len);
        #ifdef __test
        for_each(begin(v), end(v), fun_cout);
        cout<<endl;
        #endif // __test
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
        {
            ans += min(v[i], v[i - 1]);
        }
        return ans;
    }

};

int main()
{

    string s = "00110011";
//    string s = "10101";

    LT0696 lt;

    cout<<lt.lt0696a(s)<<endl;

    return 0;
}
