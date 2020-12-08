
#include "../header/myheader.h"

class LT1589
{
public:

// D

//    for (auto &r : requests) {
//        cnt[r[0]] += 1;
//        if (r[1] + 1 < nums.size())
//            cnt[r[1] + 1] -= 1;
//    }
//    for (auto i = 1; i < cnt.size(); ++i)
//        cnt[i] += cnt[i - 1];
// .. 还是这个结构，算法变了。。


// 估计是  第一个 for 循环速度慢，但是想不到更好的数据结构。
// tle...
    int lt1589a(vector<int>& nums, vector<vector<int>>& requests)
    {
        int ans = 0;
        std::sort(std::begin(nums), std::end(nums));
        int sz1 = nums.size();
        int arr[sz1];
        memset(arr, 0, sizeof(arr));
        for (vector<int>& vi : requests)
        {
            for (int i = vi[0]; i <= vi[1]; ++i)
            {
                arr[i]++;
            }
        }
        sort(arr, arr + sz1);           // 没有匹配的 begin方法。
        int mod = 1E9 + 7;
        for (int i = sz1 - 1; i >= 0 && arr[i] != 0; --i)
        {
            ans = (ans + arr[i] * nums[i]) % mod;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3,4,5};
//    myvvi vv = {{1,3},{0,1}};

    myvi v = {1,2,3,4,5,10};
    myvvi vv = {{0,2},{1,3},{1,1}};

    LT1589 lt;

    cout<<lt.lt1589a(v,vv);

    return 0;
}
