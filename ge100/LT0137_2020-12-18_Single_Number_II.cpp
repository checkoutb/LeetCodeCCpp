
#include "../header/myheader.h"

class LT0137
{
public:

// D D

//    int ones = 0, twos = 0;
//    for(int i = 0; i < A.length; i++){
//        ones = (ones ^ A[i]) & ~twos;
//        twos = (twos ^ A[i]) & ~ones;
//    }
//    return ones;

//    int ans = 0;
//    for(int i = 0; i < 32; i++) {
//        int sum = 0;
//        for(int j = 0; j < nums.length; j++) {
//            if(((nums[j] >> i) & 1) == 1) {
//                sum++;
//                sum %= 3;
//            }
//        }
//        if(sum != 0) {
//            ans |= sum << i;
//        }
//    }
//    return ans;
// you get a general solution for any times of occurrence. Say all the numbers have 5 times, just do sum %= 5.
// I like to think about the number in 32 bits and just count how many 1s are there in each bit, and sum %= 3 will clear it once it reaches 3
// 每个bit 有多少个1， 最后 %3 就是 单独的那个。


//Runtime: 16 ms, faster than 53.77% of C++ online submissions for Single Number II.
//Memory Usage: 10.5 MB, less than 11.54% of C++ online submissions for Single Number II.
// 1 3
    int lt0137a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        for (int i = 0; i < nums.size(); ++i)
            map2[nums[i]]++;
        for (auto& p : map2)
            if (p.second == 1)
                return p.first;
        return -1;
    }

};

int main()
{
//    vector<int> v = {2,2,3,2};
    vector<int> v = {0,1,0,1,0,1,99};

    LT0137 lt;

    cout<<lt.lt0137a(v);

    return 0;
}
