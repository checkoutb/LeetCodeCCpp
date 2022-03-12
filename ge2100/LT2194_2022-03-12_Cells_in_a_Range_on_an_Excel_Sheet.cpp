
#include "../header/myheader.h"

class LT2194
{
public:

// D D

//        string ts;
//        for(char c = s[0]; c <= s[3]; c++)
//        {
//            for(char num = s[1]; num <= s[4]; num++)
//            {
//                ts = c;           // char -> string....
//                ts += num;
//                vs.push_back(ts);
//            }
//        }



//Runtime: 4 ms, faster than 64.29% of C++ online submissions for Cells in a Range on an Excel Sheet.
//Memory Usage: 7.9 MB, less than 19.41% of C++ online submissions for Cells in a Range on an Excel Sheet.
    vector<string> lt2194a(string s)
    {
        char st = s[0], en = s[3], st2 = s[1], en2 = s[4];
        vector<string> ans;
        for (char ch = st; ch <= en; ch++)
        {
            for (char ch2 = st2; ch2 <= en2; ch2++)
            {
                ans.push_back(string({ch, ch2}));
            }
        }
        return ans;
    }

};

int main()
{

    LT2194 lt;

    string s = "K1:L2";

    char c = '1';
    c++;
    cout<<c<<endl;

    vector<string> vs = lt.lt2194a(s);

    for (string& s : vs)
        cout<<s<<endl;

    return 0;
}
