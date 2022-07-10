
#include "../header/myheader.h"

class LT2333
{
public:

    // D D

    //sort(arr.begin(), arr.end(), greater<int>());

    //while (lo <= hi) {
    //    int mid = lo + (hi - lo) / 2;
    //    long long req = 0;

    //    for (int x : arr) {
    //        req += max(x - mid, 0);
    //    }

    //    if (req > tot) {
    //        lo = mid + 1;
    //    }
    //    else {
    //        val = mid;
    //        hi = mid - 1;
    //    }
    //}




    //int n = nums1.size();
    //vector<int> diff(n);
    //for (int i = 0; i < n; ++i) {
    //    diff[i] = abs(nums1[i] - nums2[i]);
    //}
    //int M = *max_element(diff.begin(), diff.end());
    //vector<int> bucket(M + 1);
    //for (int i = 0; i < n; ++i) {
    //    bucket[diff[i]]++;
    //}
    //int k = k1 + k2;
    //for (int i = M; i > 0; --i) {
    //    if (bucket[i] > 0) {
    //        int minus = min(bucket[i], k);
    //        bucket[i] -= minus;
    //        bucket[i - 1] += minus;
    //        k -= minus;
    //    }
    //}
    //long long ans = 0;
    //for (long long i = M; i > 0; --i) {
    //    ans += bucket[i] * i * i;
    //}






//Runtime: 378 ms, faster than 50.00 % of C++ online submissions for Minimum Sum of Squared Difference.
//Memory Usage : 103.2 MB, less than 50.00 % of C++ online submissions for Minimum Sum of Squared Difference.
    // 应该就是减去diff最大的吧。   (a+1)^2 = a^2 + 1 + 2a， (a+1-1)^2 = a^2, 差距是 1+2a， 所以这个 -1 应用到 大值上，减去的更多
    // k < 10^9   二分。 不需要..  二分更快。
    long long lt2333a(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        int sz1 = nums1.size();
        vector<long long> vi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            vi[i] = abs(nums1[i] - nums2[i]);
        }

        sort(rbegin(vi), rend(vi));

#ifdef __test
        for (long long i : vi)
        {
            cout << i << ".";
        }
        cout << endl;
#endif

        vector<long long> vi2(begin(vi), end(vi));

        for (int i = 1; i < sz1; ++i)
        {
            vi[i] += vi[i - 1];
        }

        int ks = k1 + k2;
        int idx = sz1 - 1;
        for (int i = 1; i < sz1; ++i)
        {
            long long t2 = vi[i] - (vi2[i] * (i + 1));
            if (t2 > ks)
            {
                idx = i - 1;
                break;
            }
        }
#ifdef __test
        cout << idx << endl;
#endif

        long long t2 = vi[idx] - (vi2[idx] * (idx + 1));
        
        int remaink = ks - (int) t2;

        int mx = vi2[idx] - (remaink / (idx + 1));

        if (idx == sz1 - 1 && mx <= 0)                  // .
            return 0LL;

        int mx2 = mx - 1;
        int cnt2 = remaink % (idx + 1);
        int cnt1 = (idx + 1) - cnt2;

        long long ans = 0;

#ifdef __test
        for (long long i : vi2)
        {
            cout << i << ", ";
        }
        cout << endl;

        cout << mx << " - " << cnt1 << endl;
        cout << mx2 << " - " << cnt2 << endl;

#endif


        for (int i = 0; i < cnt2; ++i)
        {
            ans += 1LL * mx2 * mx2;
        }
        for (int i = 0; i < cnt1; ++i)
        {
            ans += 1LL * mx * mx;
        }

        for (int i = idx + 1; i < sz1; ++i)
        {
            ans += 1LL * vi2[i] * vi2[i];
        }

        return ans;
    }

};

int main()
{

    LT2333 lt;

    //myvi v1 = { 1,2,3,4 };
    //myvi v2 = { 2,10,20,19 };
    //myvi vk = { 0,0 };

    //myvi v1 = { 1,4,10,12 };
    //myvi v2 = { 5,8,6,9 };
    //myvi vk = { 1,1 };

    //myvi v1 = { 1, 4, 10, 12 };
    //myvi v2 = { 5, 8, 6, 9 };
    //myvi vk = { 10, 5 };

    myvi v1 = { 10, 10, 10, 11, 5 };
    myvi v2 = { 1, 0, 6, 6, 1 };
    myvi vk = { 11,27 };

    //myvi v1 = { 11, 12, 13, 14, 15 };
    //myvi v2 = { 13, 16, 16, 12, 14 };
    //myvi vk = { 3,6 };


    cout << lt.lt2333a(v1, v2, vk[0], vk[1]) << endl;

    return 0;
}
