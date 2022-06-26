
#include "../header/myheader.h"

class LT2321
{
public:

    // D D


    //int maxValue(const vector<int>& nums1, const vector<int>& nums2) {
    //    // repalce nums1 with nums2 and return the sum of nums1
    //    int n = nums1.size(), sum = 0, maxDiff = INT_MIN, cur = 0;
    //    for (int i = 0; i < n; i++) {
    //        sum += nums1[i];
    //        cur += nums2[i] - nums1[i];
    //        maxDiff = max(maxDiff, cur);
    //        cur = max(cur, 0);
    //    }
    //    return sum + maxDiff;
    //}


    // Kadane



    //int sum1 = 0, res1 = 0, sum2 = 0, res2 = 0;
    //for (int i = 0; i < n1.size(); ++i) {
    //    sum1 = max(n2[i] - n1[i], sum1 + n2[i] - n1[i]);
    //    res1 = max(res1, sum1);
    //    sum2 = max(n1[i] - n2[i], sum2 + n1[i] - n2[i]);
    //    res2 = max(res2, sum2);
    //}
    //return max(accumulate(begin(n1), end(n1), 0) + res1, accumulate(begin(n2), end(n2), 0) + res2);



//Runtime: 289 ms, faster than 66.67 % of C++ online submissions for Maximum Score Of Spliced Array.
//Memory Usage : 82.7 MB, less than 66.67 % of C++ online submissions for Maximum Score Of Spliced Array.
    // 就是一个 窗口， 不，不知道几时最大。 退化成 for for，估计tle的。
    // suma - parta + partb   sumb - partb + parta == sumall - (suma - parta + partb)
    // 不，知道的 。。 窗口一直往后走，如果 < 0，那么重新开始。 .. 得2次？ 就是 p1<0 还是 p2<0 才刷新
    // .. 不是0，而是 差。
    int lt2321a(vector<int>& nums1, vector<int>& nums2)
    {
        int sz1 = nums1.size();
        int sum1 = std::accumulate(begin(nums1), end(nums1), 0);
        int sum2 = std::accumulate(begin(nums2), end(nums2), 0);

        int p1 = 0;
        int p2 = 0;

        int ans = max(sum1, sum2);

        for (int i = 0; i < sz1; ++i)
        {
            p1 += nums1[i];
            p2 += nums2[i];
            ans = max(ans, max(sum1 - p1 + p2, sum2 - p2 + p1));
            if (p1 < p2)
            {
                p1 = p2 = 0;
            }
        }

        p1 = p2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            p1 += nums1[i];
            p2 += nums2[i];
            ans = max(ans, max(sum1 - p1 + p2, sum2 - p2 + p1));
            if (p2 < p1)
            {
                p1 = p2 = 0;
            }
        }

        return ans;
    }

};

int main()
{

    LT2321 lt;

    //myvi v1 = { 60,60,60 }, v2 = { 10,90,10 };

    //myvi v1 = { 20,40,20,70,30 }, v2 = { 50,20,50,40,20 };

    myvi v1 = { 7,11,13 }, v2 = { 1,1,1 };

    cout << lt.lt2321a(v1, v2) << endl;

    return 0;
}
