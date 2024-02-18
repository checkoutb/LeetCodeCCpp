
#include "../header/myheader.h"

class LT2983
{
public:




    // 还差 prefix sum, 看能否rerange [0, sz1/2] 后变成回文。 不行的话，就全部false了
    // 已经cover了， 所以只需要看 中间， prefix sum 是否可以 支持 rerange成回文。

    // 有 overlap 的情况下( 比如a-b, c-d, c<d)，只需要保证  a-c 所需的 char 能被 a-b 提供。

    // overlap
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries)
    {
        vector<int> vi;
        size_t sz1 = s.size();
        for (size_t i = 0; i < (sz1 >> 1); ++i)
        {
            if (s[i] != s[sz1 - i - 1])
                vi.push_back(i);
        }

        vector<bool> ans(queries.size());

        if (vi.empty())
        {
            fill(begin(ans), end(ans), true);
            return ans;
        }

        for (size_t i = 0; i < queries.size(); ++i)
        {
            int a = queries[i][0], b = queries[i][1], c = queries[i][2], d = queries[i][3];
            c = sz1 - c - 1;
            d = sz1 - d - 1;

            // a < b,  d < c
            if (d > b || a > c)     // no overlap
            {
                if (d > b)      // a-b, d-c
                {
                    if (a > vi[0] || c < vi[vi.size() - 1])
                    {
                        ans[i] = false;
                    }
                    else
                    {
                        auto it = std::upper_bound(std::begin(vi), end(vi), b);
                        if (it != end(vi) && *it < d)
                        {
                            ans[i] = false;
                        }
                        else
                        {
                            // prefix sum.
                        }
                    }
                }
                else        // d-c, a-b
                {

                }
            }
            else
            {

            }
        }

        return ans;
    }

};

int main()
{

    LT2983 lt;


    return 0;
}
