
#include "../header/myheader.h"

class LT1887
{
public:

// D D


//We sort the array, and go right-to-left, from largest to smallest.
//If the current number is the same as the one before it, we do nothing.
//If the number before is different, we need to update all numbers on the right (sz - j).
//    int res = 0, sz = n.size();
//    sort(begin(n), end(n));
//    for (int j = sz - 1; j > 0; --j)
//        if (n[j - 1] != n[j])
//            res += sz - j;
//    return res;
// 出现不同，说明 右侧的 所有元素值 都会 下降到 小的元素。 所以 加(sz-j)



//        sort(a.begin(),a.end());
//        vector<int> dp(n);
//        dp[0]=0;
//        for(int i=1;i<n;i++){
//            if(a[i]==a[i-1]){
//                dp[i]=dp[i-1];
//            }
//            else{
//                dp[i]=dp[i-1]+1;
//            }
//        }
//        int sum=0;
//        for(auto x:dp){
//            sum+=x;
//        }



//Runtime: 368 ms, faster than 55.90% of C++ online submissions for Reduction Operations to Make the Array Elements Equal.
//Memory Usage: 124.3 MB, less than 35.61% of C++ online submissions for Reduction Operations to Make the Array Elements Equal.
// bucket sort?
// 最大的会一路变为 所有出现过的值。
    int lt1887a(vector<int>& nums)
    {
        map<int, int> map2;
        for (int i = 0; i < nums.size(); ++i)
            map2[nums[i]]++;

        int ans = 0;
        int len = 1;
        map<int, int>::iterator it = begin(map2);
        for (it++; it != map2.end(); it++, len++)
        {
            ans += len * (it->second);
        }
        return ans;
    }

};

int main()
{
//    myvi v = {5,1,3};
//    myvi v = {1,1,1};
    myvi v = {1,1,2,2,3};

    LT1887 lt;

    cout<<lt.lt1887a(v)<<endl;

    return 0;
}
