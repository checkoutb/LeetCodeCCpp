
#include "../header/myheader.h"

class LT0821
{
public:


// D D
//        int n = S.size(), pos = -n;
//        vector<int> res(n, n);
//        for (int i = 0; i < n; ++i) {
//            if (S[i] == C) pos = i;
//            res[i] = i - pos;
//        }
//        for (int i = pos - 1; i >= 0; --i) {
//            if (S[i] == C)  pos = i;
//            res[i] = min(res[i], pos - i);
//        }


//        for (int i = 0; i < n; ++i)
//            res[i] = S[i] == C ? 0 : n;
//        for (int i = 1; i < n; ++i)
//            res[i] = min(res[i], res[i - 1] + 1);
//        for (int i = n - 2; i >= 0; --i)
//            res[i] = min(res[i], res[i + 1] + 1);



//Runtime: 4 ms, faster than 86.89% of C++ online submissions for Shortest Distance to a Character.
//Memory Usage: 6.7 MB, less than 100.00% of C++ online submissions for Shortest Distance to a Character.
    vector<int> lt0821a(string S, char C)
    {
        vector<int> ans(S.size(), 0);
        int fil = INT_MAX / 2;
        for (int i = 0; i < S.size(); i++)
        {
            ans[i] = fil;
            char ch = S[i];
            if (ch == C)
            {
                ans[i] = 0;
                int j = i - 1;
                int t2 = 1;
                while (j >= 0 && ans[j] > t2)
                {
                    ans[j] = t2;
                    t2++;
                    j--;
                }
                fil = 0;
            }
            fil++;
        }
        return ans;
    }

};

int main()
{

    string S = "loveleetcode";
    char C = 'e';

    LT0821 lt;

    vector<int> v = lt.lt0821a(S, C);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
