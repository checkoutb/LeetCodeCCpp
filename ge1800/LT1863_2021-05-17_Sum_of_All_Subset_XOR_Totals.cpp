
#include "../header/myheader.h"

class LT1863
{
public:

// D D

//        int bits = 0, n = nums.size();
//        // Finding bitwise OR of all elements
//        // https://www.geeksforgeeks.org/sum-xor-possible-subsets/
//        for (int i=0; i < n; ++i){
//            bits |= nums[i];
//        }
//        int ans = bits * pow(2, n-1);
//        return ans;


//Since we only have 12 numbers, we can represent all combinations using a bitmask: [1 << 0.... 1 << n)
//    for (auto i = 1; i < (1 << nums.size()); ++i) {
//        int total = 0;
//        for (auto j = 0; j < nums.size(); ++j)
//            if (i & (1 << j))
//                total ^= nums[j];
//        res += total;
//    }



//Take a OR of all  elements, we get
//= 1 | 5 | 6
//= 001 | 101 | 110
//= 111
//Now to find final summation,
//= 1*2^(n-1+2) + 1*2^(n-1+1) + 1*2^(n-1+0)
//= 2^(n-1) * (1*2^2 + 1*2^1 + 1*2^0 )
//= 2^(n-1) * 7
//so final result will be putting n=3,
//= 28





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of All Subset XOR Totals.
//Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Sum of All Subset XOR Totals.
    int lt1863b(vector<int>& nums)
    {
        dfsb1(nums, 0, 0);
        return ans;
    }
    int ans = 0;
    void dfsb1(vector<int>& vi, int idx, int xor1)          // xor is a operator.. baoliuzi
    {
        if (idx == vi.size())
        {
            ans += xor1;
            return;
        }
        dfsb1(vi, idx + 1, xor1);
        dfsb1(vi, idx + 1, xor1 xor vi[idx]);
    }


// error
//subset ...
//1 <= nums.length <= 12
    int lt1863a(vector<int>& nums)
    {
        int ans = 0;
        std::sort(begin(nums), std::end(nums));
        for (int i = 0; i < nums.size(); ++i)
        {
            #ifdef __test
            cout<<endl;
            #endif // __test
            int t2 = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                t2 ^= nums[j];
                ans += t2;
                #ifdef __test
                cout<<t2<<endl;
                #endif // __test
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,3};
//    myvi v = {5,1,6};
    myvi v = {3,4,5,6,7,8};

    LT1863 lt;

    cout<<lt.lt1863b(v)<<endl;

    return 0;
}
