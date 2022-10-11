
#include "../header/myheader.h"

class LT2434
{
public:

    // D D


    //for (auto ch : s)
    //    ++cnt[ch - 'a'];
    //for (auto ch : s) {
    //    t += ch;
    //    --cnt[ch - 'a'];
    //    while (lo < 26 && cnt[lo] == 0)
    //        ++lo;
    //    while (!t.empty() && t.back() - 'a' <= lo) {
    //        p += t.back();
    //        t.pop_back();
    //    }
    //}
    



    // No. 1600
//Runtime: 323 ms, faster than 51.16 % of C++ online submissions for Using a Robot to Print the Lexicographically Smallest String.
//Memory Usage : 29.7 MB, less than 72.40 % of C++ online submissions for Using a Robot to Print the Lexicographically Smallest String.
    string lt2434a(string s)
    {
        string ans;
        stack<char> t;
        int sz1 = s.size();

        int arr[123] = { 0 };
        int mnch = s[0];
        for (int i = 0; i < sz1; ++i)
        {
            ++arr[s[i]];
            if (s[i] < mnch)
                mnch = s[i];
        }

        for (int i = 0; i < sz1; ++i)
        {
            while ((!t.empty()) && (t.top() <= mnch))
            {
                ans.push_back(t.top());
                t.pop();
            }

            //if (t.empty())
            {
                t.push(s[i]);
                --arr[s[i]];
                if (arr[mnch] == 0)
                {
                    for (int j = mnch; j <= 'z'; ++j)
                    {
                        if (arr[j] != 0)
                        {
                            mnch = j;
                            break;
                        }
                    }
                }
                continue;
            }

            //while (t.top() <= mnch)
            //{

            //}

        }
        while (!t.empty())
        {
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
    }

};

int main()
{

    LT2434 lt;

    //string a = "zza";
    string a = "bac";

    cout << lt.lt2434a(a) << endl;

    return 0;
}
