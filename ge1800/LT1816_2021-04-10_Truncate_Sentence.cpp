
#include "../header/myheader.h"

class LT1816
{
public:

// D D

//        for(; i < s.size(); ){
//            k1 += s[i] == ' ';
//            if(k1 == k) break;
//            ++i;
//        }
//        return s.substr(0, i);

//    for (int i = 0; i < s.size(); ++i)
//        if (s[i] == ' ' && --k == 0)
//            return s.substr(0, i);
//    return s;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Truncate Sentence.
//Memory Usage: 6.4 MB, less than 42.10% of C++ online submissions for Truncate Sentence.
    string lt1816a(string s, int k)
    {
        int idx = 0;
        while (idx < s.size() && k > 0)
        {
            if (s[idx++] == ' ')
                k--;
        }
        return s.substr(0, idx - (idx != s.size()));
    }

};

int main()
{
    string s = "Hello how a y";
    int k = 4;

    LT1816 lt;

    cout<<lt.lt1816a(s, k)<<"."<<endl;

    return 0;
}
