
#include "../header/myheader.h"

class LT0974
{
public:


// D D

// vector<int> as map





// 各2次。。都不快。
//06/11/2022 12:24	Accepted	119 ms	31.9 MB	cpp
//06/11/2022 12:24	Accepted	112 ms	31.7 MB	cpp
//06/11/2022 12:24	Accepted	87 ms	31.9 MB	cpp
//06/11/2022 12:22	Accepted	129 ms	31.8 MB	cpp
//Runtime: 87 ms, faster than 43.84% of C++ online submissions for Subarray Sums Divisible by K.
//Memory Usage: 31.9 MB, less than 17.51% of C++ online submissions for Subarray Sums Divisible by K.
//Runtime: 129 ms, faster than 11.52% of C++ online submissions for Subarray Sums Divisible by K.
//Memory Usage: 31.8 MB, less than 26.23% of C++ online submissions for Subarray Sums Divisible by K.
// (j - i) divide by k  <==>  i%k == j%k
// map
    int lt0974a(vector<int>& nums, int k)
    {
        unordered_map<int, int> map2 = {{0, 1}};
        int psum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            psum = (psum + nums[i]) % k;
            if (psum < 0)
                psum = (psum + k) % k;
            ans += map2[psum];
            map2[psum]++;

//            psum = ((psum + nums[i]) % k + k) % k;
//            ans += map2.find(psum) == map2.end() ? 0 : map2[psum];
//            map2[psum]++;
        }
        #ifdef __test
        for (auto& p : map2)
        {
            cout<<p.first<<" -> "<<p.second<<endl;
        }
        #endif // __test
        return ans;
    }

};

int main()
{

    LT0974 lt;

    myvi v = {4,5,0,-2,-3,1};
    int k = 5;

    cout<<lt.lt0974a(v, k)<<endl;

    return 0;
}
