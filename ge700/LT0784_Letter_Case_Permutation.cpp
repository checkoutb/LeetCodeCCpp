
#include "../header/myheader.h"

class LT0784
{
public:


//Runtime: 12 ms, faster than 83.68% of C++ online submissions for Letter Case Permutation.
//Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Letter Case Permutation.
    vector<string> lt0784a(string S)
    {
        vector<string> ans;
        ans.push_back(S);
        dfsa1(S, ans, 0);
        return ans;
    }

    void dfsa1(string S, vector<string>& ans, int i)
    {
        if (i >= S.size())
            return;
        while (i < S.size())
        {
            if (std::isalpha(S[i]))
            {
                break;
            }
            i++;
        }
        if (i >= S.size())      // ...
            return;

        string S2(S);
        dfsa1(S, ans, i + 1);
        S2[i] = S2[i] >= 'a' ? S2[i] - 'a' + 'A' : S2[i] - 'A' + 'a';

        #ifdef __test
        cout<<S<<", "<<S2<<", "<<i<<", "<<ans.size()<<endl;
        #endif // __test

        ans.push_back(S2);
        dfsa1(S2, ans, i + 1);
    }

};

int main()
{

//    string s = "a1b2";
//    string s = "3z4";
    string s = "1234";

    LT0784 lt;

    vector<string> vv = lt.lt0784a(s);
    cout<<vv.size()<<endl;
    for_each(vv.begin(), vv.end(), fun_cout_s);
    cout<<endl;

    return 0;
}
