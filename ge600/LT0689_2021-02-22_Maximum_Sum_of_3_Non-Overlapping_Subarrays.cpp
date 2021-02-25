
#include "../header/myheader.h"

class LT0689
{
public:

// D D

// dou hen chang.



//Runtime: 20 ms, faster than 97.76% of C++ online submissions for Maximum Sum of 3 Non-Overlapping Subarrays.
//Memory Usage: 20.4 MB, less than 59.42% of C++ online submissions for Maximum Sum of 3 Non-Overlapping Subarrays.
    vector<int> lt0689a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1 - k + 1);
        int sum2 = 0;
        for (int i = 0; i < k; ++i)
        {
            sum2 += nums[i];
        }
        vi[0] = sum2;
        for (int i = 1; i < sz1 - k + 1; ++i)
        {
            sum2 -= nums[i - 1];
            sum2 += nums[i + k - 1];
            vi[i] = sum2;
        }
        int mxsum = vi[0];
        int mxsumi = 0;
        int sumi = 0;
//        vector<int> v2(sz1 - k + 1 - k + 1);
//        vector<int> v2(sz1 - k + 1);        // prev's index
        vector<int> v2(sz1 - k + 1);    // lazy calculate mxsum, so i cannot change vi[x], need a new vector
        vector<int> v2i(sz1 - k + 1);
        for (int i = k; i < sz1 - k + 1; ++i)
        {
            int t2 = vi[i] + mxsum;
            v2[i] = t2;
            v2i[i] = mxsumi;

            sumi++;
            if (vi[sumi] > mxsum)
            {
                mxsumi = sumi;
                mxsum = vi[sumi];
            }
        }
        mxsum = v2[k];
        mxsumi = k;
        sumi = k;
        vector<int> v3(sz1 - k + 1);
        vector<int> v3i(sz1 - k + 1);
        for (int i = k * 2; i < sz1 - k + 1; ++i)
        {
            int t2 = vi[i] + mxsum;     // ... 正好反了， 之前 这里 用了 v2 , 下面用了 vi .
            v3[i] = t2;
            v3i[i] = mxsumi;
            sumi++;
            if (v2[sumi] > mxsum)
            {
                mxsumi = sumi;
                mxsum = v2[sumi];           // 。。。 还是得要一个好名字。。
            }
        }
        int mxi = std::distance(begin(v3), std::max_element(begin(v3), end(v3)));       // return the first max element's iterator. if empty, return last.

        #ifdef __test
        showVectorInt(vi);
        showVectorInt(v2);
        showVectorInt(v3);
        #endif // __test

        return {v2i[v3i[mxi]], v3i[mxi], mxi};
    }

};

int main()
{

//    myvi v = {1,2,1,2,6,7,5,1};
//    int k = 2;

    myvi v = {1,2,1,2,2,2,2,2};     // 0 3 5
    int k = 2;

//    myvi v = {1,2,1,2,6,7,5,1};     // 0 3 5
//    int k = 2;


    LT0689 lt;

//    cout<<lt.lt0689a(v, k)<<endl;
    myvi v2 = lt.lt0689a(v, k);
    showVectorInt(v2);

    return 0;
}
