
#include "../header/myheader.h"

class LT1818
{
public:

// D D

//    long res = 0, gain = 0;
//    set<int> s(begin(n1), end(n1));
//    for (int i = 0; i < n1.size(); ++i) {
//        long original = abs(n1[i] - n2[i]);
//        res += original;
//        if (gain < original) {
//            auto it = s.lower_bound(n2[i]);
//            if (it != end(s))
//                gain = max(gain, original - abs(*it - n2[i]));
//            if (it != begin(s))
//                gain = max(gain, original - abs(*prev(it) - n2[i]));
//        }
//    }
//    return (res - gain) % 1000000007;
// set, not unordered...  s.lower_bound..
// long...所以没有提前的 mod，所以不需要 return的时候 +mod。



//Runtime: 172 ms, faster than 86.26% of C++ online submissions for Minimum Absolute Sum Difference.
//Memory Usage: 63.9 MB, less than 99.55% of C++ online submissions for Minimum Absolute Sum Difference.
// replace, not swap
// max-diff, no.??try . . .如果是相同的diff，那么怎么分辨。
//
    int lt1818a(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> vi(begin(nums1), end(nums1));
        std::sort(begin(vi), end(vi));
        int mxdec = 0;
        int sum2 = 0;
        const int mod = 1E9 + 7;
        for (int i = 0; i < nums1.size(); ++i)
        {
            if (nums1[i] != nums2[i])
            {
                int t2 = abs(nums1[i] - nums2[i]);
                sum2 = (sum2 + t2) % mod;
                int idx = std::distance(begin(vi), lower_bound(begin(vi), end(vi), nums2[i]));
                int t3 = idx == vi.size() ? INT_MAX : vi[idx] - nums2[i];           // .
                if (idx > 0)
                    t3 = min(t3, nums2[i] - vi[idx - 1]);
                #ifdef __test
//                cout<<t2<<", "<<t3<<", "<<vi[idx]<<", "<<i<<", "<<nums1[i]<<", "<<nums2[i]<<", "<<endl;
                #endif // __test
                if ((t2 - t3) > mxdec)
                {
                    mxdec = t2 - t3;
                }
            }
        }
        #ifdef __test
        cout<<sum2<<", "<<mxdec<<endl;
        #endif // __test
        return (sum2 - mxdec + mod) % mod;      // negative

//        int t2 = 0;
//        int mxdif = 0;
//        for (int i = 0; i < nums1.size(); ++i)
//        {
//            if (abs(nums1[i] - nums2[i]) > mxdif)
//            {
//
//            }
//        }
    }

};

int main()
{
//    myvi v1 = {1,7,5};
//    myvi v2 = {2,3,5};

//    myvi v1 = {2,3,3,4};
//    myvi v2 = {2,3,3,4};

//    myvi v1 = {1,10,4,4,2,7};
//    myvi v2 = {9,3,5,1,7,4};


    LT1818 lt;

    cout<<lt.lt1818a(v1, v2)<<endl;

    return 0;
}
