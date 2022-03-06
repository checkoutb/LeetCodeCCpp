
#include "../header/myheader.h"

class LT2109
{
public:

// D D

//        string ans;
//        ans.reserve(s.size() + A.size());

//    for (int i = 0; i <= sps.size(); ++i) {
//        int prev = i ? sps[i - 1] : 0, cur = i == sps.size() ? s.size() : sps[i];
//        copy(begin(s) + prev, begin(s) + cur, begin(res) + prev + i);
//    }


//Runtime: 255 ms, faster than 42.46% of C++ online submissions for Adding Spaces to a String.
//Memory Usage: 80.3 MB, less than 89.32% of C++ online submissions for Adding Spaces to a String.
    string lt2109b(string s, vector<int>& spaces)
    {
        int sz1 = s.size();
        int sz2 = spaces.size();
        vector<char> vc(sz1 + sz2);
        int si = 0;
        int ai = 0;
        for (int i = 0; i < vc.size(); i++)
        {
            if (ai < sz2 && si == spaces[ai])
            {
                vc[i] = ' ';
                ai++;
            }
            else
            {
                vc[i] = s[si++];
            }
        }
        return string(begin(vc), end(vc));
    }


//Memory Limit Exceeded ... 太多的 substr 了。。
    string lt2109a(string s, vector<int>& spaces)
    {
        int idx = 0;
        for (int i = 0; i < s.size() && idx < spaces.size(); ++i)
        {
            if (i == spaces[idx] + idx)
            {
                s = s.substr(0, spaces[idx] + idx) + " " + s.substr(spaces[idx] + idx);
                idx++;
            }
        }
        return s;
    }

};

int main()
{

    LT2109 lt;

    string s = "LeetcodeHelpsMeLearn";
    myvi v = {8,13,15};

//    string s = "spacing";
//    myvi v = {0,1,2,3,4,5,6};

    cout<<lt.lt2109b(s, v)<<endl;

    return 0;
}
