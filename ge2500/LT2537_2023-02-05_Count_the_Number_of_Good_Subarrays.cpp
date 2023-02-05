
#include "../header/myheader.h"

class LT2537
{
public:

    // D D

    //long long countGood(vector<int>& A, int k) {
    //    long long res = 0;
    //    unordered_map<int, int> count;
    //    for (int i = 0, j = 0; j < A.size(); ++j) {
    //        k -= count[A[j]]++;
    //        while (k <= 0)
    //            k += --count[A[i++]];
    //        res += i;
    //    }
    //    return res;
    //}




    //Runtime388 ms
    //    Beats
    //    17.83 %
    //    Memory77.1 MB
    //    Beats
    //    31.51 %
    // after hint...
    long long lt2537b(vector<int>& nums, int k)
    {
        long long ans = 0LL;
        int sz1 = nums.size();
        map<int, int> map2;
        int cnt = 0;
        int en = 0;
        for (int i = 0; i < sz1; ++i)
        {
            while (en < sz1 && cnt < k)
            {
                cnt += map2[nums[en]];
                ++map2[nums[en]];
                ++en;
            }
            if (cnt >= k)
            {
                ans += sz1 - en + 1;
            }
            --map2[nums[i]];
            cnt -= map2[nums[i]];
        }
        return ans;
    }


    // error
    long long lt2537a(vector<int>& nums, int k)
    {
        long long ans = 0LL;
        int sz1 = nums.size();
        map<int, int> map2;
        int cnt = 0;
        int st = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            cnt += map2[nums[i]];
            ++map2[nums[i]];
            if (cnt >= k)
            {
                t2 = st;
                while ((cnt - (map2[nums[st]] - 1)) >= k)
                {
                    cnt -= map2[nums[st]] - 1;
                    ++st;
                }
                //if (st != t2)
                    ans += 1LL * (st - t2) * (sz1 - i);
            }
        }
        return ans;
    }

};

int main()
{

    LT2537 lt;

    //myvi v = { 1,1,1,1,1 };
    //int k = 10;

    //myvi v = { 3,1,4,3,2,2,4 };
    //int k = 2;

    myvi v = { 2,1,3,1,2,2,3,3,2,2,1,1,1,3,1 };     // 21
    int k = 11;

    cout << lt.lt2537b(v, k) << endl;

    return 0;
}
