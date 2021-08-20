
#include "../header/myheader.h"

class LT0842
{
public:

// D D

//


//Runtime: 4 ms, faster than 63.47% of C++ online submissions for Split Array into Fibonacci Sequence.
//Memory Usage: 6.5 MB, less than 79.94% of C++ online submissions for Split Array into Fibonacci Sequence.
    vector<int> lt0842a(string num)
    {
        int sz1 = num.size();
        int mxlen = min(sz1 / 2 - (sz1 + 1) % 2, 10);       // string(INT_MAX).length == 10
        vector<int> ans;

        for (int i = 0; i < mxlen; ++i)
        {
            if (num[0] == '0' && i != 0)
                break;
            long a = std::stol(num.substr(0, i + 1));
            if (a > INT_MAX)
                break;
            for (int j = 0; j < mxlen; ++j)
            {
                if (num[i + 1] == '0' && j != 0)
                    break;
                long b = std::stol(num.substr(i + 1, j + 1));
                if (b > INT_MAX)
                    break;
                bool t2 = dfsa1(num, i + j + 2, ans, a, b);
                if (t2)
                {
                    ans.push_back(b);
                    ans.push_back(a);
                    goto BBB;
                }
            }
        }
        BBB:
        std::reverse(begin(ans), end(ans));
        return ans;
    }

    bool dfsa1(string& s, int idx, vector<int>& ans, long a, long b)
    {
        #ifdef __test
        cout<<idx<<", "<<a<<", "<<b<<endl;
        #endif // __test
        if (idx == s.size())
        {
            return true;
        }
        if (idx > s.size())
            return false;
        long c = a + b;
        if (c > INT_MAX)
            return false;
        if (s[idx] == '0' && c != 0)            // "00000000"
            return false;
        string sc = to_string(c);
        #ifdef __test
        cout<<idx<<", "<<c<<", "<<sc<<endl;
        #endif // __test
        for (int i = 0; i < sc.size(); ++i)
        {
            if (idx >= s.size() || sc[i] != s[idx++])
            {
                return false;
            }
        }
        bool t2 = dfsa1(s, idx, ans, b, c);
        if (t2 == true)
            ans.push_back(c);
        return t2;
    }

};

int main()
{
//    string s = "123456579";
//    string s = "11235813";
//    string s = "112358130";
//    string s = "0123";
//    string s = "000000";
//    string s = "17522";
//    string s = "5511816597";
    string s = "214748364721474836422147483641";



    LT0842 lt;

    vector<int> vi = lt.lt0842a(s);

    cout<<vi.size()<<endl;
    for (int i : vi)
        cout<<i<<", ";

    return 0;
}
