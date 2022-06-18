
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    // dp可以跳过mxlen个，开始计算。



//Runtime: 21 ms, faster than 90.55 % of C++ online submissions for Longest Palindromic Substring.
//Memory Usage : 7 MB, less than 92.20 % of C++ online submissions for Longest Palindromic Substring.
    string ltb(string s)
    {
        int sz1 = s.size();
        int mxlen = 1;
        int st{ 0 }, en{ 0 };
        for (int i = 0; i < sz1 - 1; ++i)
        {
            int b = i;
            int e = i;
            while (b > 0 && (e < sz1 - 1) && s[b - 1] == s[e + 1])
            {
                b--;
                e++;
            }
#ifdef __test
            if (i == 1)
                cout << b << " ? " << e << endl;
#endif
            if ((e - b + 1) > mxlen)
            {
                st = b;
                en = e;
                mxlen = e - b + 1;
            }
            
            if (s[i] == s[i + 1])
            {
                b = i;
                e = i + 1;
                while (b > 0 && (e < sz1 - 1) && s[b - 1] == s[e + 1])
                {
                    b--, e++;
                }
                if ((e - b + 1) > mxlen)
                {
                    st = b, en = e;
                    mxlen = e - b + 1;
                }
            }
        }
#ifdef __test
        cout << st << " - " << en << endl;
#endif

        return s.substr(st, en - st + 1);
    }


//Runtime: 649 ms, faster than 18.77 % of C++ online submissions for Longest Palindromic Substring.
//Memory Usage : 387.1 MB, less than 5.33 % of C++ online submissions for Longest Palindromic Substring.
    string lta(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        vector<int> vi(2, 0);
        int mxlen = 1;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            vvi[i][i] = 1;
            for (int j = i + 1; j < sz1; j++)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                    {
                        vvi[i][j] = 2;
                        if (mxlen < 2)
                        {
                            mxlen = 2;
                            vi[0] = i;
                            vi[1] = j;
                        }
                    }
                    else
                    {
                        if (vvi[i + 1][j - 1])
                        {
                            vvi[i][j] = vvi[i + 1][j - 1] + 2;
                            if (mxlen < vvi[i][j])
                            {
                                mxlen = vvi[i][j];
                                vi[0] = i, vi[1] = j;
                            }
                        }
                    }
                }
            }
        }
#ifdef __test
        cout << vi[0] << " - " << vi[1] << endl;
#endif
        return s.substr(vi[0], vi[1] - vi[0] + 1);
    }

};

int main()
{

    LT lt;

    //string s = "babad";

    //string s = "cbbd";

    //string s = "bb";

    string s = "ccc";

    cout << lt.ltb(s) << endl;

    return 0;
}
