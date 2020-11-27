
#include "../header/myheader.h"

class LT1512
{
public:

// D D

//        return accumulate(A.begin(), A.end(), 0, [count = unordered_map<int, int> {}] (auto a, auto b) mutable {
//            return a + count[b]++;
//        });

//        int res = 0;
//        unordered_map<int, int> count;
//        for (int a: A) {
//            res += count[a]++;
//        }
//        return res;


//    int cnt[101] = {};
//    for (auto n: nums)
//        ++cnt[n];
//    return accumulate(begin(cnt), end(cnt), 0, [](int s, int i)
//        { return s + i * (i - 1) / 2; });
// ... {} , no 0..


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs.
//Memory Usage: 7.6 MB, less than 31.96% of C++ online submissions for Number of Good Pairs.
    int lt1512a(vector<int>& nums)
    {
        int arr[101] = {0};
        for (int i : nums)
            arr[i]++;
        int ans = 0;
        for (int i = 0; i < 101; ++i)
        {
            if (arr[i] > 1)
            {
                ans += arr[i] * (arr[i] - 1) / 2;
            }
        }
        return ans;
    }

};

int main()
{

//    myvi v = {1,2,3,1,1,3};
    myvi v = {1,2,3};

    LT1512 lt;

    cout<<lt.lt1512a(v)<<endl;

    return 0;
}
