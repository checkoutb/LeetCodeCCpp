
#include "../header/myheader.h"

class LT2981
{
public:





    // 找了半天，总算找到一个可以过的。其他的真的是。。。

// Runtime
// 11ms
// Beats65.57%of users with C++
// Memory
// 12.42MB
// Beats50.36%of users with C++
    int lt2981b(string s)
    {
        int sz1 = s.size();
        vector<int> vi(sz1, 1);
        for (int i = 1; i < sz1; ++i)
        {
            if (s[i] == s[i - 1])
            {
                vi[i] = vi[i - 1] + 1;
            }
        }
        int ans = -1;
        vector<vector<int>> vvi(26);            // or sort(vi), check which char will first get 3 number
        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - 'a'].push_back(vi[i]);
        }
        for (int i = 0; i < 26; ++i)
        {
            if (vvi[i].size() < 3)
                continue;
            sort(rbegin(vvi[i]), rend(vvi[i]));
            ans = max(ans, vvi[i][2]);
        }
        return ans;
    }


// Runtime
// 7ms
// Beats83.76%of users with C++
// Memory
// 9.78MB
// Beats82.01%of users with C++
    int maximumLength(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vvi(26);
        // for (char ch : s)
        for (int i = 0; i < sz1; ++i)
        {
            char ch = s[i];
            vvi[ch - 'a'].push_back(i);
        }
        int ans = -1;
        for (int i = 0; i < 26; ++i)
        {
            char ch = char(i + 'a');
            int cnt = vvi[i].size();
            int len = 0;
            while (cnt >= 3)
            {
                cnt = 0;
                ++len;

                for (int j = 0; j < vvi[i].size(); ++j)
                {
                    int t2 = vvi[i][j];
                    if (t2 != -1)
                    {
                        if (t2 + 1 < s.size() && s[t2 + 1] == ch)
                        {
                            ++vvi[i][j];
                            cnt += 1;
                        }
                        else
                        {
                            vvi[i][j] = -1;
                        }
                    }
                }
            }
            if (len != 0)
                ans = max(ans, len);
        }
        return ans;
    }

};

int main()
{

    LT2981 lt;


    return 0;
}
