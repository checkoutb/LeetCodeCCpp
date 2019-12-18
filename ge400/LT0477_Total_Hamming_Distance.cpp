
#include "../header/myheader.h"

class LT0477
{
public:





// discuss
//    int total = 0, n = nums.length;
//    for (int j=0;j<32;j++) {
//        int bitCount = 0;
//        for (int i=0;i<n;i++)
//            bitCount += (nums[i] >> j) & 1;
//        total += bitCount*(n - bitCount);
//    }
//    return total;

// 某位上，为1的个数是bitCount，为0就是 n-bitCount. 相乘就是 这位上的 所有汉明距离。如果全1，那么就是n*0==0。



// gg


    int lt0477b(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 <= 1)
            return 0;
        bitset<32> arr[sz1];
        for (int i = 0; i < sz1; i++)
        {
            arr[i] = bitset<32>(nums[i]);
        }

        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {

            }
        }
        return -1;
    }

    // 36 / 47 . tle
    int lt0477a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                int t1 = nums[i] ^ nums[j];
                bitset<32> bs(t1);
                for (int i = 0; i < 32; i++)
                {
                    ans += bs[i];
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> v = {4, 14, 2};

    LT0477 lt;

    cout<<lt.lt0477a(v)<<endl;

    return 0;
}
