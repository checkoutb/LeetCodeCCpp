
#include "../header/myheader.h"

class LT0368
{
public:

// D D

//        for (int i = 1; i < len; ++ i) {
//            for (int j = 0; j < i; ++ j) {
//                if (nums[i]%nums[j] == 0 && dp[i] < dp[j]+1) {
//                    dp[i] = dp[j]+1;
//                    pos[i] = j;
//                    if (maxD < dp[i]) {
//                        maxD = dp[i];
//                        maxIdx = i;
//                    }
//                }
//            }
//        }


//void helper(vector<int> &nums,vector<int> curr,int j,int prev,vector<int> &mem)
//{
//	if(curr.size()>res.size())
//		res=curr;
//	for(int i=j;i<nums.size();i++)
//	{
//		if(mem[i]<=curr.size()&&nums[i]%prev==0)
//		{
//			mem[i]=curr.size();
//			curr.push_back(nums[i]);
//			helper(nums,curr,i+1,nums[i],mem);
//			curr.pop_back();
//		}
//	}
//}



// 守得云开见月明，  前路茫茫，前途缈渺。
//12/25/2020 11:21	Accepted	44 ms	10.1 MB	cpp
//12/25/2020 11:15	Time Limit Exceeded	N/A	N/A	cpp
//12/25/2020 11:14	Runtime Error	N/A	N/A	cpp
//12/25/2020 11:13	Runtime Error	N/A	N/A	cpp
//12/25/2020 11:12	Wrong Answer	N/A	N/A	cpp
//05/17/2019 13:06	Time Limit Exceeded	N/A	N/A	cpp
//05/17/2019 12:49	Wrong Answer	N/A	N/A	cpp
//05/17/2019 12:47	Wrong Answer	N/A	N/A	cpp
//05/17/2019 12:45	Wrong Answer	N/A	N/A	cpp
//05/17/2019 12:43	Wrong Answer	N/A	N/A	cpp
//05/17/2019 12:42	Runtime Error	N/A	N/A	cpp
//Runtime: 44 ms, faster than 46.98% of C++ online submissions for Largest Divisible Subset.
//Memory Usage: 10.1 MB, less than 19.77% of C++ online submissions for Largest Divisible Subset.
    vector<int> lt0368b(vector<int>& nums)
    {
        int sz1 = nums.size();
        if (sz1 == 0)
            return nums;
        sort(begin(nums), end(nums));
        vector<int> arr(sz1, -1);
        unordered_map<int, int> map2;
        long mx = nums[sz1 - 1];
        bool has1 = false;
        int mxcnt = 0;
        int mxbegi = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            int n = nums[i];
            if (n == 1)
            {
                has1 = true;
                break;
            }
            int cnt = 1;
            int par = -1;

            for (int j = i + 1; j < sz1; ++j)
            {
                if (nums[j] % n == 0)
                {
//                    cnt = map2[nums[j]] + 1;        // should use vector, not map...
                    if (cnt < map2[nums[j]] + 1)
                    {
                        cnt = map2[nums[j]] + 1;
                        par = nums[j];              // should save parent's Index ..
                    }
                }
            }

            // tle  [2,3,5,7,11,13,17,19,23,31,1000000007]
//            for (long i = 2; i * n <= mx; ++i)
//            {
//                if (map2.find(i * n) != map2.end())
//                {
//                    if (cnt < map2[i * n] + 1)
//                    {
//                        cnt = map2[i * n] + 1;
//                        par = i * n;
//                    }
//                }
//            }


            map2[n] = cnt;
            arr[i] = par;       // parent.value   not index.
            if (mxcnt < cnt)
            {
                mxcnt = cnt;
                mxbegi = i;
            }
        }
        vector<int> ans;
        int t1 = nums[mxbegi];
        if (has1 && t1 != 1)
            ans.push_back(1);
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] == t1)
            {
                ans.push_back(t1);
                t1 = arr[i];
                if (t1 == -1)
                    break;
            }
        }
        return ans;
    }


// error
    vector<int> lt0368a(vector<int>& nums)
    {
        unordered_set<int> set2(begin(nums), end(nums));
        sort(begin(nums), end(nums));
        unordered_set<int> set3;
        set3.insert(1);
        int t2 = nums[0] == 1 ? 1 : 0;
        int mx = nums[nums.size() - 1];
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (set3.find(nums[i]) != set3.end())
                continue;
            vector<int> vi;
            vi.push_back(nums[i]);
            int sz1 = -1;
            while (sz1 != vi.size())
            {
                sz1 = vi.size();

            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,2,3};
//    myvi v = {1,2,4,8,3,9,18};
//    myvi v = {1};
//    myvi v = {2000000000};
    myvi v = {2,3,5,7,11,13,17,19,23,31,1000000007};                // prime

    LT0368 lt;

    myvi vv = lt.lt0368b(v);

    showVectorInt(vv);

    return 0;
}
