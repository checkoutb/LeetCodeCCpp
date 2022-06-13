
#include "../header/myheader.h"

class LT2294
{
public:

    // D D

    //class Solution {
    //    using b_type = uint64_t;
    //    static constexpr int b_size = sizeof(b_type) * CHAR_BIT;
    //    b_type b[(100001 + b_size - 1) / b_size]{};
    // 
    //public:
    //    int partitionArray(vector<int>& nums, int k) {
    //        int ans = 0;
    //        int begin = 0;//INT_MAX;
    //        int end = 100000;//INT_MIN;
    //        for (int i = 0; i < nums.size(); ++i) {
    //            auto byte = nums[i] / b_size;
    //            auto bit = 1LL << (nums[i] % b_size);
    //            b[byte] |= bit;
    //            //begin = min(begin, nums[i]);
    //            //end = max(end, nums[i]);
    //        }
    //        for (int i = begin; i <= end;) {
    //            auto byte = i / b_size;
    //            auto bit = 1LL << (i % b_size);
    //            if (!b[byte]) {
    //                i = (i + b_size) & ~(b_size - 1);
    //            }
    //            else if (b[byte] & bit) {
    //                ans++;
    //                i += k + 1;
    //            }
    //            else {
    //                i++;
    //            }
    //        }
    //        return ans;
    //    }
    //};




//Runtime: 185 ms, faster than 99.02 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
//Memory Usage : 83.1 MB, less than 52.76 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
    int lt2294c(vector<int>& nums, int k)
    {
        //int arr[100001] = { 0 };
        bitset<100001> bs;
        int mxele = -123;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > mxele)
                mxele = nums[i];
            bs.set(nums[i]);
        }
        int ans = 1;
        int st = 0;
        for (; st <= mxele; ++st)
        {
            if (bs[st])
            {
                break;
            }
        }
        for (int i = st + 1; i <= mxele; ++i)
        {
#ifdef __test
            cout << i << endl;
#endif
            if (bs[i] && (i - st > k))
            {
#ifdef __test
                cout << i << endl;
#endif
                st = i;
                ans++;
            }
        }
        return ans;
    }


    // ???
//Runtime: 406 ms, faster than 7.19 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
//Memory Usage : 83.1 MB, less than 52.76 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
    int lt2294b(vector<int>& nums, int k)
    {
        std::sort(begin(nums), end(nums));
        int ans = 1;
        int st = nums[0];
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - st > k)
            {
                st = nums[i];
                ans++;
            }
        }
        return ans;
    }


//Runtime: 584 ms, faster than 5.02 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
//Memory Usage : 121.6 MB, less than 5.38 % of C++ online submissions for Partition Array Such That Maximum Difference Is K.
    // 某个值只会在 一个subseq中出现。  subseq的最大最小的差距 <= k
    int lt2294a(vector<int>& nums, int k)
    {
        set<int> set2(begin(nums), end(nums));
        int ans = 1;
        int st = *(set2.begin());
        while (!set2.empty())
        {
            int t2 = *(set2.begin());
            set2.erase(set2.begin());
            if (t2 - st <= k)
            {
                ;
            }
            else
            {
                st = t2;
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    LT2294 lt;

    //myvi v = { 3,6,1,2,5 };
    //int k = 2;

    //myvi v = { 1,2,3 };
    //int k = 1;

    myvi v = { 2,2,4,5 };
    int k = 0;

    cout << lt.lt2294c(v, k) << endl;

    return 0;
}
