
#include "../header/myheader.h"

class LT2262
{
public:










// Runtime
// 16ms
// Beats84.57%of users with C++
// Memory
// 11.73MB
// Beats79.27%of users with C++
    long long appealSum(string s)
    {
        int sz1 = s.size();
        vector<int> vi(26, -1);
        long long ans = 0LL;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = s[i] - 'a';
            ans += 1LL * (i - vi[t2]) * (sz1 - i);
            vi[t2] = i;
        }
        return ans;


        // int sz1 = s.size();
        // vector<vector<int>> vvi(sz1, vector<int>(26, -1));      // last appear
        // long long ans = 0;
        // for (int i = 1; i < sz1; ++i)
        // {
        //     for (int j = 0; j < 26; ++j)
        //     {
        //         vvi[i][j] = vvi[i - 1][j];
        //     }
        //     vvi[i][s[i - 1] - 'a'] = i - 1;
        // }

//         vector<int> vi(26, sz1);
//
//         long long ans = 0LL;
//         for (int i = s.size() - 1; i >= 0; --i)
//         {
//
//         }
//         return ans;
    }

//     // next change
//     long long appealSum(string s)
//     {
//         int sz1 = s.size();
//         vector<int> vi(sz1, 0);
//         vi[0] = 1 << (s[0] - 'a');
//         for (int i = 1; i < sz1; ++i)
//         {
//             vi[i] = vi[i - 1] | (1 << (s[i] - 'a'));
//         }
//
//     }
};

int main()
{

    LT2262 lt;


    return 0;
}
