
#include "../header/myheader.h"

class LT2449
{
public:

    // D D

    //sort(nums.begin(), nums.end());
    //sort(target.begin(), target.end());
    //vector<int> oa, ob, ea, eb;
    //long long ans = 0;
    //for (auto& i : nums) i % 2 == 0 ? ea.push_back(i) : oa.push_back(i);
    //for (auto& i : target) i % 2 == 0 ? eb.push_back(i) : ob.push_back(i);
    //int ol = oa.size();
    //int el = ea.size();
    //for (int i = 0; i < ol; ++i) {
    //    ans += (abs((long long)oa[i] - (long long)ob[i]) / 2);
    //}
    //for (int i = 0; i < el; ++i) {
    //    ans += (abs((long long)ea[i] - (long long)eb[i]) / 2);
    //}
    //return ans / 2;


    //vector<vector<int>> AA(2), BB(2);
    //for (int a : A) AA[a % 2].push_back(a);
    //for (int b : B) BB[b % 2].push_back(b);
    //sort(AA[0].begin(), AA[0].end());
    //sort(AA[1].begin(), AA[1].end());
    //sort(BB[0].begin(), BB[0].end());
    //sort(BB[1].begin(), BB[1].end());

    //long long res = 0;
    //for (int i = 0; i < AA[0].size(); ++i)
    //    res += abs(AA[0][i] - BB[0][i]) / 2;
    //for (int i = 0; i < AA[1].size(); ++i)
    //    res += abs(AA[1][i] - BB[1][i]) / 2;
    //return res / 2;




    //sort(begin(n), end(n));
    //sort(begin(t), end(t));
    //long long res = 0;
    //for (int i = 0, j1 = 0, j2 = 0; i < n.size(); ++i) {
    //    int& j = n[i] % 2 ? j1 : j2;
    //    while (n[i] % 2 != t[j] % 2)
    //        ++j;
    //    res += abs(n[i] - t[j]) / 2;
    //    ++j;
    //}
    //return res / 2;


    // 新界面。。   害得我升级了浏览器。。。不然完全不显示。。
//Runtime550 ms
//Beats
//22.57%
//Memory83.3 MB
//Beats
//85.87%
    long long lt2449a(vector<int>& nums, vector<int>& target)
    {
        sort(begin(nums), end(nums));
        sort(begin(target), end(target));

        vector<int> vi;
        vector<int> v2;
        int sz1 = nums.size();
        long long t2 = 0;
        long long ans = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] % 2)
                vi.push_back(nums[i]);
            if (target[i] % 2)
                v2.push_back(target[i]);
        }

        int sz2 = vi.size();
        long long t3 = 0;
        for (int i = 0; i < sz2; ++i)
        {
            t3 = vi[i] - v2[i];
            if (t3 < 0)
            {
                if (t2 + t3 >= 0)
                {
                    t2 += t3;
                }
                else
                {
                    if (t2 < 0)
                    {
                        ans += (-t3) / 2;
                        t2 += t3;
                    }
                    else
                    {
                        t3 += t2;
                        t2 = t3;
                        ans += (-t3) / 2;
                    }
                }
            }
            else if (t3 > 0)
            {
                if (t2 + t3 <= 0)
                {
                    t2 += t3;
                }
                else
                {
                    if (t2 < 0)
                    {
                        t3 += t2;
                        t2 = t3;
                        ans += t3 / 2;
                    }
                    else
                    {
                        ans += t3 / 2;
                        t2 += t3;
                    }
                }
            }
        }



        vi.clear();
        v2.clear();
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] % 2 == 0)
                vi.push_back(nums[i]);
            if (target[i] % 2 == 0)
                v2.push_back(target[i]);
        }

        sz2 = vi.size();

        for (int i = 0; i < sz2; ++i)
        {
            t3 = vi[i] - v2[i];
            if (t3 < 0)
            {
                if (t2 + t3 >= 0)
                {
                    t2 += t3;
                }
                else
                {
                    if (t2 < 0)
                    {
                        ans += (-t3) / 2;
                        t2 += t3;
                    }
                    else
                    {
                        t3 += t2;
                        t2 = t3;
                        ans += (-t3) / 2;
                    }
                }
            }
            else if (t3 > 0)
            {
                if (t2 + t3 <= 0)
                {
                    t2 += t3;
                }
                else
                {
                    if (t2 < 0)
                    {
                        t3 += t2;
                        t2 = t3;
                        ans += t3 / 2;
                    }
                    else
                    {
                        ans += t3 / 2;
                        t2 += t3;
                    }
                }
            }
        }



        return ans;

        //sort(begin(nums), end(nums));
        //sort(begin(target), end(target));

        ////int idx1 = 0;
        ////int idx2 = 0;
        //int sz1 = target.size();
        //int sti = 0;
        //int eni = sz1 - 1;
        //
        //int t3 = 0;
        //int t2 = 0;     // <  -,   > +
        //for (int i = 0; i < sz1; ++i)
        //{
        //    t3 = nums[i] - target[i];
        //    if (t3 < 0)
        //    {
        //        if (t3 >= t2)
        //        {
        //            t2 -= t3;
        //        }
        //        else
        //        {
        //            ans += ()
        //        }
        //    }
        //    else if (t3 > 0)
        //    {
        //        
        //    }
        //}

    }

};

int main()
{

    LT2449 lt;

    //myvi v = { 6,12,8 };
    //myvi v2 = { 2,14,10 };

    //myvi v = { 1,3,4 };
    //myvi v2 = { 1,2,5 };

    // 645
    myvi v = { 758,334,402,1792,1112,1436,1534,1702,1538,1427,720,1424,114,1604,564,120,578 };
    myvi v2 = { 1670,216,1392,1828,1104,464,678,1134,644,1178,1150,1608,1799,1156,244,2,892 };

    cout << lt.lt2449a(v, v2);

    return 0;
}
