
#include "../header/myheader.h"

class LT1961
{
public:

// D D

//    for (int j = 0; j < words.size() && i < s.size(); ++j)
//        for (auto ch : words[j])
//            if (i == s.size() || s[i++] != ch)
//                return false;
//    return i == s.size();





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Check If String Is a Prefix of Array.
//Memory Usage: 13.9 MB, less than 25.00% of C++ online submissions for Check If String Is a Prefix of Array.

//Input "a" ["aa","aaaa","banana"]
//Output true
//Expected false

// 第一眼看成是： 能否从每个word中取 前x个 (对于每个word，x可以取不同值，但是必须属于[0,sz1)),组成 s。。。。凉了的感觉。。
// Example 2 救了我。。
    bool lt1961a(string s, vector<string>& words)
    {
        int is = 0;
        int iw = 0;
        int iiw = 0;
        for (; is < s.size(); ++is)
        {
            if (iiw == words[iw].size())
            {
                iw++;
                iiw = 0;
                if (iw >= words.size())
                    return false;
            }
            if (s[is] != words[iw][iiw])
                return false;
            iiw++;
        }
        return iiw == words[iw].size();
    }

};

int main()
{

    LT1961 lt;


    return 0;
}
