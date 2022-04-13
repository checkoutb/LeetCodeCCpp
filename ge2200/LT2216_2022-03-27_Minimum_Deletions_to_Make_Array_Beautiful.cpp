
#include "../header/myheader.h"

class LT2216
{
public:

// D D


//        for(auto &i : nums) {
//            if(count==0 || i!=last) {
//                count++;
//                last=i;
//            }
//            if(count==2) {
//                ans+=2;
//                count=0;
//            }
//        }
//        ans=nums.size()-ans;
// 。。这ans不正规啊。 最后来一个反转。。 这个记录 2个不同的数的对。


//        for(int i=0; i+1<n; i++) {
//            if((i-ans)%2==0 && nums[i]==nums[i+1]) {
//                ans++;
//            }
//        }
//        ans+=(n-ans)&1;


//    int j = 0, sz = nums.size();
//    for(int i = 0; i - j + 1 < sz; i += 2)
//        j += nums[i - j] == nums[i - j + 1];
//    return j + (sz - j) % 2;

//        int res = 0, pre = -1;
//        for (int& a: A) {
//            if (a == pre)
//                res++;
//            else
//                pre = pre < 0 ? a : -1;
//        }
//        return res + (pre >= 0);


//Runtime: 244 ms, faster than 14.29% of C++ online submissions for Minimum Deletions to Make Array Beautiful.
//Memory Usage: 121.2 MB, less than 57.14% of C++ online submissions for Minimum Deletions to Make Array Beautiful.
// 长度偶数， 偶数下标和后一位不能相等。
// 1 2 3 3 4 4 6 6 8 8 ，，无所谓。
    int lt2216a(vector<int>& nums)
    {
        int ans = 0;
        int now = 0, nxt = 1, sz1 = nums.size();
        while (nxt < sz1)
        {
            while (nxt < sz1 && nums[now] == nums[nxt])
            {
                nxt++;
                ans++;
            }
            now = nxt + 1;
            nxt = now + 1;
        }
        ans += (sz1 - ans) % 2 == 1 ? 1 : 0;
        return ans;
    }

};

int main()
{

    LT2216 lt;

//    myvi v = {1,1,2,3,5};
//    myvi v = {1,1,2,2,3,3};
    myvi v = {1,2,3,3,4,4};

    cout<<lt.lt2216a(v)<<endl;

    return 0;
}
