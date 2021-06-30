
#include "../../header/myheader.h"

class LT
{
public:

// D D

//string removeDuplicates(string S) {
//  for (auto i = 1; i < S.size(); ++i)
//    if (S[i - 1] == S[i])
//	  return removeDuplicates(S.substr(0, i - 1) + S.substr(i + 1));
//  return S;
//}


//        int i = 0, n = s.length();
//        for (int j = 0; j < n; ++j, ++i) {
//            s[i] = s[j];
//            if (i > 0 && s[i - 1] == s[i]) // count = 2
//                i -= 2;
//        }
//        return s.substr(0, i);


//        string res = "";
//        for (char& c : S)
//            if (res.size() && c == res.back())
//                res.pop_back();
//            else
//                res.push_back(c);
//        return res;




// AC
    string lta(string s)
    {
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == s[i - 1])
            {
                s.erase(i - 1, 2);
                i = i - 2;
                if (i < 0)
                    i = 0;
            }
        }
        return s;
    }

};

int main()
{
//    string s = "abbaca";
    string s = "azxxzy";

    LT lt;

    cout<<lt.lta(s)<<endl;

    return 0;
}
