
#include "../header/myheader.h"

class LT3113
{
public:

    // D D


    // int find(vector<int> &nums, int l, int r)
    // {
    //     int ans=nums[l];
    //     for(int i=l;i<=r;i++)
    //     {
    //         ans=max(ans,nums[i]);
    //     }
    //     return ans;
    // }
    //
    // long long numberOfSubarrays(vector<int>& nums) {
    //     unordered_map<int,vector<int>> v;
    //     for(int i=0;i<nums.size();i++)
    //     {
    //         v[nums[i]].push_back(i);
    //     }
    //     long long ans=nums.size();
    //     for(auto x:v)
    //     {
    //         long long cnt=1;
    //         for(int i=1;i<x.second.size();i++)
    //         {
    //             if(find(nums,x.second[i-1],x.second[i])==x.first)
    //             {
    //                 cnt+=1;
    //             }
    //             else
    //             {
    //                 ans+=cnt*(cnt-1)/2;
    //                 cnt=1;
    //             }
    //         }
    //         ans+=cnt*(cnt-1)/2;
    //     }
    //     return ans;



        // vector<vector<int>> stack;
        // long long res = 0;
        // for (int& a : A) {
        //     while (!stack.empty() && stack.back()[0] < a)
        //         stack.pop_back();
        //     if (stack.empty() || stack.back()[0] != a)
        //         stack.push_back({a, 0});
        //     res += ++stack.back()[1];
        // }
        // return res;






// Runtime
// 197ms
// Beats100.00%of users with C++
// Memory
// 139.79MB
// Beats33.33%of users with C++
    // fst == lst == maxofsubarray
    // 10^5 , long long ans;
    // range query max, BIT ....but...
    // prefix last bigger. stack ..
    long long numberOfSubarrays(vector<int>& nums)
    {
        size_t sz1 = nums.size();
        // long long ans = 0LL;
        long long ans = sz1;

        std::stack<int> stk;
        vector<int> bigIdx(sz1, -1);

        for (size_t i = 0; i < sz1; ++i)
        {
            while (!stk.empty() && nums[stk.top()] <= nums[i])
                stk.pop();
            if (!stk.empty())
            {
                bigIdx[i] = stk.top();
            }
            // bigIdx[i] = stk.empty() ? -1 : stk.top();
            stk.push(static_cast<int>(i));
        }

#ifdef __test
        showVectorInt(bigIdx);
#endif

        unordered_map<int, int> map2;   // same value's last index

        vector<long long> vll(sz1, 0LL);    // subarray count

        for (int i = 0; i < sz1; ++i)
        {
            if (map2.contains(nums[i]))
            {
                int lstappear = map2[nums[i]];
                int lstbig = bigIdx[i];
                if (lstbig < lstappear)
                {
                    vll[i] = vll[lstappear] + 1;
                    ans += vll[i];
                }
            }

            map2[nums[i]] = i;
        }

        return ans;
    }

};

int main()
{

    LT3113 lt;

    // myvi v {1,4,3,3,2};
    myvi v {3,3,3};

    cout<<lt.numberOfSubarrays(v)<<endl;

    return 0;
}
