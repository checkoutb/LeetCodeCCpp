
#include "../header/myheader.h"

class LT2911
{
public:




//     Runtime189 ms
// Beats
// 71.34%
// Memory11.8 MB
// Beats
// 65.33%


    // ... "a" not a semi-palindrome
    // d<len,  1<=d<1

    // x = index % d;   {vi[x] | x % d are same}  is palindrome
    // k substrings
    // <= 200
    // [last index][substring count]
    // [st][en] to be a semi-palindrome, change count
    // 123454321  9 3  143 252 341   1
    // 12344321  8 2 1342
    int minimumChanges(string s, int k)
    {
        size_t sz1 = s.size();
        std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz1, INT_MAX));
        // std::vector<bool> vb(sz1, false);

        for (size_t i = 0; i < sz1; ++i)
        {
            for (size_t j = i + 1; j < sz1; ++j)
            {
                vvi[i][j] = changeCount(s, i, j);
            }
        }

#ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int val : vvi[i])
            {
                cout<<val<<", ";
            }
            cout<<endl;
        }
#endif

        std::vector<vector<int>> vv2(sz1, std::vector<int>(k + 1, INT_MAX));
        // std::vector<int> vik;

        for (size_t j = 0; j < sz1; ++j)
        {
            vv2[j][1] = vvi[0][j];
        }

        for (size_t i = 1; i < sz1; ++i)
        {
            // vik.clear();

            // // if (i != 0)
            // {
            //     for (size_t a = 0; a <= k; ++a)
            //     {
            //         if (vv2[i - 1][a] != -1)
            //         {
            //             vik.push_back(a);
            //         }
            //     }
            // }

            // if (i != 0 && vik.empty())
            //     continue;

            for (size_t j = i + 1; j < sz1; ++j)
            {
                for (int a = 1; a < k; ++a)
                {
                    if (vv2[i - 1][a] == INT_MAX)
                        break;
                    vv2[j][a + 1] = std::min(vv2[j][a + 1], vv2[i - 1][a] + vvi[i][j]);
                }
            }
        }

#ifdef __test
        for (auto& v : vv2)
        {
            for (int i : v)
            {
                cout<<i<<", ";
            }
            cout<<endl;
        }
#endif

        return vv2[sz1 - 1][k];
    }

    int changeCount(string& s, size_t st, size_t en)
    {
        int cnt = INT_MAX;
        size_t sz1 = en - st + 1;
        // if (sz1 <= 1)
        //     return cnt;

        int t2 = 0;
        for (int d = sz1 >> 1; d >= 1; --d)
        {
            if (sz1 % d)
                continue;

            t2 = 0;

#ifdef __test
            // cout<<" --- "<<d<<endl;
#endif

            for (int i = 0; i < d; ++i)
            {
                for (int j = i + st, k = st + sz1 - d + i; j < k; j += d, k -= d)
                {
                    t2 += s[j] != s[k];

#ifdef __test
                    // cout<<j<<" "<<k<<" "<<s[j]<<", "<<s[k]<<" -------- "<<t2<<endl;
#endif
                }
            }

            cnt = std::min(cnt, t2);
#ifdef __test
            // cout<<" ??? "<<cnt<<", "<<t2<<endl;
#endif
        }

#ifdef __test
        // cout<<st<<", "<<en<<", "<<cnt<<endl;
#endif

        return cnt == INT_MAX ? 0 : cnt;
    }

};

int main()
{

    LT2911 lt;

    string s("abcac");
    int k{2};

    // string s("abcdef");
    // int k{2};

    // string s{"acba"};
    // int k{2};       // 2

    std::cout<<lt.minimumChanges(s, k)<<std::endl;

    return 0;
}
