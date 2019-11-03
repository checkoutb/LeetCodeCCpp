
#include "../header/myheader.h"

class LT0503
{
public:

// details
// stack。。。


// discuss
//        for (int i = 0; i < n * 2; i++) {
//            int num = nums[i % n];
//            while (!s.empty() && nums[s.top()] < num) {
//                next[s.top()] = num;
//                s.pop();
//            }
//            if (i < n) s.push(i);
//        }



    // 看了discuss的title: O(n)..
    // ....更慢了。。。
//Runtime: 864 ms, faster than 5.05% of C++ online submissions for Next Greater Element II.
//Memory Usage: 12.9 MB, less than 11.11% of C++ online submissions for Next Greater Element II.
    vector<int> lt0503c(vector<int>& nums)
    {
        int sz1 = nums.size();
        long long TAG = (long long)INT_MIN - 1;
        vector<long long> ans(sz1, TAG);
        if (sz1 == 0)
            return nums;
        for (int i = 1; i < sz1; i++)           // 第一次不能越界。
        {
            if (nums[i] > nums[i - 1])
            {
                int j = i - 1;
                while (nums[j] < nums[i])
                {
                    if (ans[j] == TAG)
                        ans[j] = nums[i];
                    j--;
                    if (j < 0)
                        break;
                }
            }
        }
        if (nums[sz1 - 1] < nums[0])                // ...
        {
            int j = sz1 - 1;
            while (nums[j] < nums[0])
            {
                if (ans[j] == TAG)
                    ans[j] = nums[0];
                j--;
                if (j < 0)
                    j = sz1 - 1;
            }
        }
        for (int i = 1; i < sz1; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                int j = i - 1;
                while (nums[j] < nums[i])
                {
                    if (ans[j] == TAG)
                        ans[j] = nums[i];
                    j--;
                    if (j < 0)
                        j = sz1 - 1;
                }
            }
        }
        vector<int> ans2(sz1);
        for (int i = 0; i < sz1; i++)
        {
            if (ans[i] == TAG)
            {
                ans2[i] = -1;
            }
            else
            {
                ans2[i] = (int) ans[i];
            }
        }
        return ans2;
    }

//Runtime: 196 ms, faster than 11.45% of C++ online submissions for Next Greater Element II.
//Memory Usage: 14.2 MB, less than 11.11% of C++ online submissions for Next Greater Element II.

// 好久没遇到==0判断了。。

    vector<int> lt0503b(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> ans(sz1);
        if (sz1 == 0)
            return ans;
        int TEMP = 100000;
        set<int> maxIndeies;
        int max2 = nums[0];
        for (int i = 1; i < sz1; i++)
        {
            if (nums[i] > max2)
            {
                max2 = nums[i];
                maxIndeies.clear();
                maxIndeies.insert(i);
            }
            else if (nums[i] == max2)
            {
                maxIndeies.insert(i);
            }
        }
        set<int> set3(maxIndeies);
        for (int i : set3)
        {
            maxIndeies.insert(TEMP + i);
        }
        map<int, int> map2;
        for (int i = 0; i < sz1; i++)
        {
            int val = nums[i];
            if (val == max2)
            {
                ans[i] = -1;
                continue;
            }
            int start3 = i + 1;
            auto it = maxIndeies.upper_bound(i);
            int end3 = *it >= TEMP ? *it - TEMP : *it;
            int j = start3;
            for (; j != end3; j++)
            {
                if (j >= sz1)
                    j = 0;
                if (nums[j] > val)
                {
                    break;
                }
            }
            ans[i] = nums[j];
        }
        return ans;
    }

    // 无意义，比val小的数的next greater大概率是val自己。
    vector<int> lt0503a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int TEMP = 100000;
        vector<int> ans(sz1);
        map<int, int> map2;         // val - next greater's index
        for (int i = 0; i < sz1; i++)
        {
            int val = nums[i];
            auto it = map2.lower_bound(val);
            if (it->first != val && it != map2.begin())
            {
                it--;
            }
            int start2 = i + 1;
            int end2 = i - 1;               // ... need another map..
            if (it->first <= val && it->second > start2)
            {
                start2 = (it->second > TEMP ? it->second - TEMP : it->second);
            }
        }
        return ans;
    }
};

int main()
{
//    vector<int> n = {1,2,1};
//    vector<int> n = {5,4,3,2,1};
//    vector<int> n = {1,2,3,4,5,6,5,4,5,1,2,3};
//    vector<int> n = {100,1,11,1,120,111,123,1,-1,-100};
    vector<int> n = {1,8,-1,-100,-1,222,1111111,-111111};

    LT0503 lt;
    vector<int> ans = lt.lt0503c(n);
    cout<<endl<<endl;
    for_each(ans.begin(), ans.end(), fun_cout);
    cout<<endl;
    return 0;
}
