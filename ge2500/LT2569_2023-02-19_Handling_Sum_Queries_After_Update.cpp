
#include "../header/myheader.h"

class LT2569
{
public:



    // tle

    // hint: Lazy Segment Tree.....
    // just sum.
    vector<long long> lt2569a(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries)
    {
        int sz1 = nums1.size();
        int szq = queries.size();

        long long sum2 = 0LL;
        int st = sz1, en = 0;       // [st, en] changed
        int cnt1 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums2[i];
            cnt1 += nums1[i];
        }

        vector<long long> ans;
        vector<bool> vb(sz1 + 1, false);
        bool chg = false;
        for (int i = 0; i < szq; ++i)
        {
            switch (queries[i][0])
            {
            case 1:
                st = min(st, queries[i][1]);
                en = max(en, queries[i][2]);
                vb[queries[i][1]] = !vb[queries[i][1]];
                vb[queries[i][2] + 1] = !vb[queries[i][2] + 1];
                break;
            case 2:
                chg = false;
                for (int i = st; i <= en; ++i)
                {
                    if (vb[i])
                    {
                        chg = !chg;
                        vb[i] = false;
                    }
                    if (chg)
                    {
                        if (nums1[i] == 1)
                        {
                            nums1[i] = 0;
                            --cnt1;
                        }
                        else
                        {
                            nums1[i] = 1;
                            ++cnt1;
                        }
                    }
                }
                vb[en + 1] = false;
                st = sz1, en = 0;
                sum2 += 1LL * cnt1 * queries[i][1];
                break;
            default:

                ans.push_back(sum2);
            }
        }

        return ans;

        //long long sum2 = nums2[0];
        //vector<int> vi(sz1);            // <= index, how many 1
        //vi[0] = nums1[0];
        //for (int i = 1; i < sz1; ++i)
        //{
        //    sum2 += nums2[i];
        //    vi[i] = vi[i - 1] + nums1[i];
        //}

        //long long cnt1 = vi[sz1 - 1];

        //// flip 之后的 vi 是无效的了。


    }

};

int main()
{

    LT2569 lt;

    //myvi v1 = { 1,0,1 };
    //myvi v2 = { 0,0,0 };
    //myvvi vv = { {1,1,1},{2,1,0},{3,0,0} };

    //myvi v1 = { 1 };
    //myvi v2 = { 5 };
    //myvvi vv = { {2,0,0},{3,0,0} };


    //// 679,679,1053
    //myvi v1 = { 0,0,0,0,1,0,0,0,1,1,0,1,0,1,1,1,0,0,0,0,1,1,1 };
    //myvi v2 = { 30,46,43,34,39,16,14,41,22,11,32,2,44,12,22,36,44,49,50,10,33,7,42 };
    //myvvi vv = { {1,15,21}, {3,0,0},{3,0,0},{2,21,0},{2,13,0},{3,0,0} };

    // 1280
    myvi v1 = { 1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,0,1,1,1,0 };
    myvi v2 = { 4,33,4,8,19,48,21,9,23,33,36,43,47,48,18,30,38,1,47,19,21,31,19,24,3,41 };
    myvvi vv = { {1,9,19},{1,1,16},{2,5,0},{2,29,0},{3,0,0} };

    vector<long long> vll = lt.lt2569a(v1, v2, vv);

    for (long long ll : vll)
        cout << ll << endl;

    return 0;
}
