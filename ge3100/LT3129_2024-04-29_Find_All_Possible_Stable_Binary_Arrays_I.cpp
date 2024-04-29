
#include "../header/myheader.h"

class LT3129
{
public:

    // D

    // int dp[202][202][2];

    // [remain 0][remain 1][can append 1?]
    // 如果可以append 1,那么 append 1-limit 个1， 继续dfs ( 不能append 1 )
    // 如果可以append 0,那么 append 1-limit 个0， dfs ( 能append 1 )
    //
    // 。。。


    // g


    // tle. 660 / 668    ,    663 / 668

    // 0 cnt = param1
    // 1 cnt = param2
    // subarr size > limit must contain 0+1
    // >=0,<500 is 0's continue length   >=500 is 1
    int numberOfStableArrays(int zero, int one, int limit)
    {
        // vector<int> vi(limit * 2, 0);
        vector<map<int, int>> vmp(limit * 2 + 3);   // <zero's remain count * 1000 + one's remain, ans>
                                            // <zero's remain, ans>
        const int MOD = 1e9 + 7;
        vmp[1][zero - 1] = 1;
        vmp[limit + 2][zero] = 1;       // +2
        int cnt0 = 0;
        int t2 = 0;
        int ans = 0;
        int cnt1 = 0;
        for (int i = zero + one - 1; i > 0; --i)        // total remain count
        {
            vector<map<int, int>> vmp2(limit * 2 + 2);

            for (int j = 0; j < vmp.size(); ++j)    // 0's length,  1's length
            {
                if (j == 0 || j == (limit + 1))
                    continue;
                if (vmp[j].empty())
                    continue;

                for (map<int, int>::iterator it = vmp[j].begin(); it != vmp[j].end(); it++)
                {
                    cnt0 = it->first;
                    t2 = it->second;

                    cnt1 = i - cnt0;    // remain 1

                    if ((cnt0 + 1) * limit < cnt1 || (cnt1 + 1) * limit < cnt0)
                        continue;


                    // choose 0, append a 0
                    if (cnt0 > 0)
                    {
                        if (j <= limit) // now is 0, append 0
                        {
                            if (j < limit)
                            {
                                vmp2[j + 1][cnt0 - 1] = (vmp2[j + 1][cnt0 - 1] + t2) % MOD;
                                // cout<<"now0, app0\n";
                            }
                        }
                        else
                        {
                            // now is 1, append 0
                            vmp2[1][cnt0 - 1] = (vmp2[1][cnt0 - 1] + t2) % MOD;
                            // cout<<"now1,app0\n";
                        }
                    }


                    // choose 1
#ifdef __test
                    cout<<j<<" 0len, cnt0"<<cnt0<<", ans:"<<t2<<", cnt1"<<cnt1<<std::endl;
#endif

                    if (cnt1 > 0)
                    {
                        if (j <= limit)
                        {
                            // 0 append 1
                            vmp2[limit + 2][cnt0] = (vmp2[limit + 2][cnt0] + t2) % MOD;
                            // cout<<"now0,app1\n";
                        }
                        else
                        {
                            // limit + 2 ==> 1
                            // limit + 2 + limit-1 -> limit
                            // 1 append 1
                            if (j < limit * 2 + 1)
                            {
                                vmp2[j + 1][cnt0] = (vmp2[j + 1][cnt0] + t2) % MOD;
                                // cout<<"now1,app1\n";
                            }
                        }
                    }
                    // cout<<"==== end\n";
                }
            }

            swap(vmp, vmp2);

#ifdef __test
            for (int i = 0; i < vmp.size(); ++i)
            {
                cout<<" 0size,1size ---- "<<i<<endl;
                for (auto& p : vmp[i])
                {
                    std::cout<<p.first<<", "<<p.second<<std::endl;
                }
            }
            cout<<"\n\n============\n\n";
#endif

        }
        // ans = vmp[0][0];
        for (int i = 0; i < vmp.size(); ++i)
            ans = (ans + vmp[i][0]) % MOD;
        return ans;
    }

    // inline int mpkey(int zero, int one)
    // {
    //     return zero * 1000 + one;
    // }
};

int main()
{

    LT3129 lt;

    // myvi v = {1,1,2};
    // myvi v = {1,2,1};
    // myvi v = {3,3,2};
    myvi v = {2,2,2};   // 6
    // myvi v = {2,3,1};

    std::cout<<lt.numberOfStableArrays(v[0], v[1], v[2])<<std::endl;

    return 0;
}
