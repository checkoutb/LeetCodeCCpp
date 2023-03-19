
#include "../header/myheader.h"

class LT2375
{
public:

    // D D


    //for (int i = 0, f = 0; (i <= sz); ++i)
    //{
    //    res[i] += i;
    //    if (i == sz || pattern[i] == 'I')
    //    {
    //        std::reverse(res.begin() + f, res.begin() + i + 1);
    //        f = i + 1;
    //    }
    //}


    //If we meet I, II, III...
    //    we can greedily pick the smallest numebr.

    //    If we meet D,
    //    we can pick second smallestand then pick the smallest,
    //    like 21.

    //    If we meet DD,
    //    we can pick the third smallest, then the second smallest, then the smallest,
    //    like 321.

    //Final result for D D I D D I D D,
    //    is 3, 2, 1, 6, 5, 4, 9, 8, 7

    // 所以 DD 也是选最小的，只不过 需要 倒序。


    //Runtime3 ms
    //    Beats
    //    51.71 %
    //    Memory6.1 MB
    //    Beats
    //    42.91 %

    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory6 MB
    //    Beats
    //    42.91 %
    // 9! = 360000
    string lt2375a(string pattern)
    {
        int sz1 = pattern.size();
        string ans(sz1 + 1, ' ');

        for (int i = 1; i <= 9; ++i)
        {
            ans[0] = char('0' + i);
            if (dfsa1(pattern, 1 << i, i, 1, ans))
            {
                break;
            }
        }

        return ans;
    }

    // find ?
    bool dfsa1(string& p, int vst, int lst, int idx, string& ans)
    {
        if (idx >= ans.size())
            return true;

        if (p[idx - 1] == 'D')
        {
            for (int i = 1; i < lst; ++i)
            {
                if ((vst & (1 << i)) == 0)
                {
                    ans[idx] = char(i + '0');
                    if (dfsa1(p, vst | (1 << i), i, idx + 1, ans))
                        return true;
                }
            }
        }
        else
        {
            for (int i = lst + 1; i <= 9; ++i)
            {
                if ((vst & (1 << i)) == 0)
                {
                    ans[idx] = char('0' + i);
                    if (dfsa1(p, vst | (1 << i), i, idx + 1, ans))
                        return true;
                }
            }
        }
        return false;
    }

};

int main()
{

    LT2375 lt;

    string p = "IIIDIDDD";
    //string p = "DDD";

    cout << lt.lt2375a(p) << endl;

    return 0;
}
