
#include "../header/myheader.h"

class LT2426
{
public:



    // n1i - n1j <= n2i - n2j + df
    // n1i - n2i <= n1j - n2j + df
    long long lt2426a(vector<int>& nums1, vector<int>& nums2, int diff)
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();

        vector<int> vi(sz1);
        vector<int> tmp(sz1);

        long long ans = dfsa1(vi, 0, sz1 - 1);

    }

    //long long dfsa1(vector<int>& vi, int st, int en, vector<int>& tmp)
    //{
    //    if (st == en)
    //    {
    //        return 0LL;
    //    }
    //    long long ans = 0LL;

    //    int md = (st + en) / 2;

    //    ans += dfsa1(vi, st, md) + dfsa1(vi, md + 1, en);

    //    int i = st, j = md + 1;
    //    int idx = st;

    //    while (i <= md || j <= en)
    //    {
    //        if (i > md)
    //        {
    //            tmp[idx] = vi[j++];
    //        }
    //        else if (j > en)
    //        {
    //            tmp[idx] = vi[i++];
    //        }
    //        else
    //        {
    //            if (vi[i] < vi[j])
    //            {
    //                tmp[idx] = vi[i];
    //                ++i;
    //            }
    //            else
    //            {
    //                tmp[idx] = vi[j];
    //                ++j;
    //            }
    //        }
    //        ++idx;
    //    }

    //}

    //vector<int> dfsa1(vector<int>& v1, vector<int>& v2, int df, int st, int en, )
    //{
    //    if (st == en)
    //    {
    //        return {v1[st] - v2[st]};
    //    }
    //    int md = (st + en) / 2;
    //    //vector<int> sv1 = dfsa1(v1, v2, df, st, md);
    //    //vector<int> sv2 = dfsa1(v)
    //}

};

int main()
{

    LT2426 lt;


    return 0;
}
