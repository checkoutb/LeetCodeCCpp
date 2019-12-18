
#include "../header/myheader.h"

class LT0482
{
public:






// ans.push_back(toupper(c))         这应该是原来的string 上修改。



//Runtime: 12 ms, faster than 70.25% of C++ online submissions for License Key Formatting.
//Memory Usage: 10.5 MB, less than 72.41% of C++ online submissions for License Key Formatting.

    string lt0482b(string S, int K)
    {
        int n1 = 0;
        for (char c : S)
            n1 += (c != '-');
        if (n1 == 0)                    // == 0
            return "";
        n1 += (n1 / K) - (n1 % K == 0);             // - (n1 % k == 0)
        char* buf = new char[n1 + 1];
        buf[n1] = '\0';

        int j = n1 - 1;
        int diff = n1 - n1 / K;
        int t1 = 0;
        for (int i = S.size() - 1; i >= 0 && j >= 0; i--)
        {
            if (S[i] == '-')
                continue;

            buf[j--] = (char)(S[i] >= 'a' ? S[i] - 'a' + 'A' : S[i]);
            t1++;
            if (t1 % K == 0 && j >= 0)          // j>=0
            {
                t1 = 0;
                buf[j--] = '-';
            }
        }
        string ans(buf);
        return ans;
    }


// StringBuilder ?

// ostringstream 不知道这个有没有用。

// 34 / 38 . Memory Limit Exceeded
    string lt0482a(string S, int K)
    {
        int t1 = 0;
        string ans = "";
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == '-')
                continue;

            ans = (char)(S[i] >= 'a' ? S[i] - 'a' + 'A' : S[i]) + ans;
            t1++;
            if (t1 == K)
            {
                ans = '-' + ans;
                t1 = 0;
            }
        }
        if (ans[0] == '-')
            ans = ans.substr(1, ans.size() - 1);
        return ans;
    }
};

int main()
{
    string s = "5F3Z-2e-9-w";
    int k = 4;

//    string s = "2-5g-3-J";
//    int k = 2;

    LT0482 lt;

    cout<<lt.lt0482b(s, k)<<endl;

    return 0;
}
